#include "CApplication.h"
#include "AWindow.h"
#include <SDL_events.h>

CApplication::CApplication(AWindow *window)
    :m_window(window)
{

}

void CApplication::execute()
{

}

void CApplication::quit()
{
    SDL_Event quitEvt {SDL_QUIT};
    SDL_PushEvent(&quitEvt);
}
