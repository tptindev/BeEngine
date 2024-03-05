#include "CApplication.h"
#include "CWindow.h"
#include <SDL_events.h>
#include <CEngine.h>

CApplication::CApplication(CWindow *window)
    :m_window(window)
{
    _DEBUG("Start");
}

int CApplication::execute()
{
    bool initialized = CEngine::instance()->initialize(this);
    if(initialized)
    {
        CEngine::instance()->loop();
        CEngine::instance()->clean();
        CEngine::instance()->quit();
    }
    else
    {
        _DEBUG("Can't initialize Game Game");
        return -1;
    }
    return 0;
}

void CApplication::quit()
{
    _DEBUG("Quit");
    SDL_Event quitEvt {SDL_QUIT};
    SDL_PushEvent(&quitEvt);
}

CWindow *CApplication::window()
{
    return m_window;
}

SDL_Surface *CApplication::windowSurface()
{
    return m_window->sdlSurface();
}
