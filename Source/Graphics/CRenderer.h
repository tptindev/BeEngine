#ifndef CRENDERER_H
#define CRENDERER_H

class CWindow;
class SDL_Renderer;
class SDL_Window;
class CRenderer
{
private:
    static CRenderer* s_instance;
    static SDL_Renderer* s_renderer;
    CRenderer();
    SDL_Window* m_window;
public:
    CRenderer(const CRenderer &) = delete; // copy constructor
    CRenderer(CRenderer &&) = delete; // move constructor
    CRenderer &operator=(const CRenderer &) = delete;
    CRenderer &operator=(CRenderer &&) = delete;
    static CRenderer *instance();
    static SDL_Renderer *renderer();

    // ARenderer interface
public:
    bool initialize(CWindow* window);
    bool destroy();
    void beginDraw();
    void endDraw();
};

#endif // CRENDERER_H
