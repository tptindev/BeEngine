#ifndef CWINDOW_H
#define CWINDOW_H

#include <list>
#include <CObject.h>
#include <CSignal.h>

class SDL_Window;
class SDL_Surface;
class SDL_Renderer;
class CLayer;
class CWindow : public CObject
{
public:
    CWindow(CObject *parent = nullptr);
    explicit CWindow(const char *title, int width, int height, CObject *parent = nullptr);

    ~CWindow();

    void toggleIsFull();

    void initialize();
    void destroy();

    SDL_Window* sdlWindow();
    SDL_Surface* sdlSurface();
    SDL_Renderer* sdlRenderer();

    const char *title() const;
    int width() const;
    int height() const;
    int x() const;
    int y() const;
    bool is_full() const;
    bool active() const;
    void updateWindowSurface();
    void registerLayer(CLayer* layer);
    std::list<CLayer *>& layers();


    CSignal<void, int, int>& windowSizeChanged();

protected:
    const char* m_title;
    int m_width, m_height;
    int m_x, m_y;
    bool m_is_full {false};
    bool m_active {true};

    std::list<CLayer*> m_layers;

private:
    SDL_Window* m_sdl_window {nullptr};
    SDL_Surface* m_sdl_window_surface {nullptr};
    SDL_Renderer* m_sdl_renderer {nullptr};

    CSignal<void, int, int> m_window_size_changed;
};

#endif // CWINDOW_H
