#include "CApplication.h"
#include "AWindow.h"
#include <SDL_events.h>

CApplication::CApplication(AWindow *window)
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
