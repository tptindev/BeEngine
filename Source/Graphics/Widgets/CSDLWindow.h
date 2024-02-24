#ifndef CSDLWINDOW_H
#define CSDLWINDOW_H

#include <CObject.h>
#include <CSignal.h>
#include "AWindow.h"

class SDL_Window;
class SDL_Surface;
class CSDLWindow : public CObject, public AWindow
{
public:
    CSDLWindow(CObject *parent = nullptr);
    explicit CSDLWindow(const char *title, int width, int height, CObject *parent = nullptr);

    ~CSDLWindow();

    void toggleIsFull();

    void initialize();

    SDL_Window* sdlWindow();
    SDL_Surface* sdlSurface();

private:
    SDL_Window* m_sdl_window {nullptr};
    SDL_Surface* m_sdl_window_surface {nullptr};

    // AWindow interface
public:
    virtual void update_window_surface() override;
};

#endif // CSDLWINDOW_H
