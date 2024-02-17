#include "CEngine.h"
#include <LoggerDefines.h>
#include <CMemoryManager.h>
#include <SDL_timer.h>
#include <CRenderer2D.h>

CEngine* CEngine::s_instance = nullptr;
bool CEngine::s_running = false;
CEngine::CEngine(CObject *parent)
    :CObject(parent)
{
    _DEBUG("%s", __FUNCTION__);

}

CEngine::~CEngine()
{
    _DEBUG("%s", __FUNCTION__);
}

CEngine *CEngine::instance()
{
    return s_instance = (s_instance == nullptr)? new CEngine(): s_instance;
}

bool CEngine::initialize(const char* title, float width, float height)
{
    if (!CRenderer2D::instance()->ready())
        return false;

    // [1] init SDL and create the Game Window and Renderer
    if (!CRenderer2D::instance()->openWindow(title, width, height))
    {
        return false;
    }

    // [2] start game engine
    s_running = true;
    return true;
}

void CEngine::loop()
{
    const int fps = 60;
    const int frameDelay = 1000 / fps;

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
//            handle_events();
//            update(deltaTime);
//            render();
        }
        // [game logic]

        if (deltaTime < frameDelay)
        {
            SDL_Delay(frameDelay - deltaTime);
        }
    }
}

void CEngine::clean()
{

}

void CEngine::quit()
{
    // Get elapsed time
    _DEBUG("Elapsed milliseconds: %lld",m_timer.elapsed_milliseconds());
    _DEBUG("Elapsed seconds: %lf",m_timer.elapsed_seconds());
    _DEBUG("Elapsed minutes: %lf",m_timer.elapsed_minutes());
}

