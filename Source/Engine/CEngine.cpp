#include "CEngine.h"
#include <LoggerDefines.h>
#include <CMemoryManager.h>
#include <CRenderer.h>
#include <Widgets/CWindow.h>
#include <Widgets/CApplication.h>
#include <CEventDispatcher.h>
#include <SDL_timer.h>
CEngine* CEngine::s_instance = nullptr;
bool CEngine::s_running = false;
CEngine::CEngine(CObject *parent)
    :CObject(parent), m_renderer(CRenderer::instance())
{
    _DEBUG("%s", __FUNCTION__);

}

CEngine::~CEngine()
{
    _DEBUG("%s", __FUNCTION__);
}

void CEngine::handle_events()
{
    CEventDispatcher::instance()->dispatchEvent();
}

void CEngine::update(float dt)
{

}

void CEngine::render()
{
    m_renderer->beginDraw();

    // Render code goes here

    m_renderer->endDraw();
}

CEngine *CEngine::instance()
{
    return s_instance = (s_instance == nullptr)? new CEngine(): s_instance;
}

bool CEngine::initialize(CApplication* app)
{
    m_app = app;

    // [1] init SDL and create the Game Window and Renderer
    if (!m_renderer->initialize(app->window()))
    {
        return false;
    }

    m_window_full.connect(std::bind(&CWindow::toggleIsFull, app->window()));

    // [2] register event handler
    registerEvent();

    // [3] start game engine
    s_running = true;


    return true;
}

void CEngine::registerEvent()
{
    CEventDispatcher* dispatcher = CEventDispatcher::instance();
    dispatcher->addEventListener(SDL_QUIT, [&](SDL_Event& event){ s_running = false; });
    dispatcher->addEventListener(SDL_KEYDOWN, [&](SDL_Event& event){
        SDL_Keycode sym = event.key.keysym.sym;
        if(sym == SDLK_ESCAPE)
        {
            s_running = false;
        }
        else if(sym == SDLK_F11)
        {
            m_window_full.emit(true);
        }
    });
}

void CEngine::loop()
{
    const int fps = 60;
    const int _1s = 1000;
    const int frameDelay = _1s / fps; // 16 milliseconds

    // time between 2 frames
    float deltaTime = 0.0f;

    // time at start
    Uint32 lastTime = SDL_GetTicks();

    while (s_running)
    {
        // current time
        Uint32 currentTime = SDL_GetTicks();

        // calculate deltatime
        deltaTime = (float)(currentTime - lastTime) / 1000.0f;

        // update lastTime
        lastTime = currentTime;

        // [game logic]
        {
            handle_events();
            update(deltaTime);
            render();
        }
        // [game logic]

        if (deltaTime < frameDelay) //
        {
            SDL_Delay(frameDelay - deltaTime);
        }
    }
}

void CEngine::clean()
{
    m_renderer->destroy();
    m_app->window()->destroy();
    _DEBUG("Game Release Resource");
}

void CEngine::quit()
{
    // Get elapsed time
    _DEBUG("Elapsed milliseconds: %lld",m_timer.elapsed_milliseconds());
    _DEBUG("Elapsed seconds: %lf",m_timer.elapsed_seconds());
    _DEBUG("Elapsed minutes: %lf",m_timer.elapsed_minutes());
    _DEBUG("Elapsed hours: %lf",m_timer.elapsed_hours());
    _DEBUG("Elapsed days: %lf",m_timer.elapsed_days());
    _DEBUG("Game Quit");
}

