#include "CApplication.h"
#include "CWindow.h"
#include <SDL_events.h>

CApplication::CApplication(CWindow *window)
    :m_window(window)
{

}

int CApplication::execute()
{
    return 0;
}

void CApplication::quit()
{
    SDL_Event quitEvt {SDL_QUIT};
    SDL_PushEvent(&quitEvt);
}

CWindow *CApplication::window()
{
    return m_window;
}
