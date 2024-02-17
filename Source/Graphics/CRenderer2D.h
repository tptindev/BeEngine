#ifndef CRENDERER2D_H
#define CRENDERER2D_H

#include "ARenderer.h"

class SDL_Renderer;
class SDL_Window;
class CRenderer2D: public ARenderer
{
private:
    static CRenderer2D* s_instance;
    static SDL_Renderer* s_renderer;
    SDL_Window* m_window;
    CRenderer2D();
public:
    CRenderer2D(const CRenderer2D &) = default; // copy constructor
    CRenderer2D(CRenderer2D &&) = default; // move constructor
    CRenderer2D &operator=(const CRenderer2D &) = default;
    CRenderer2D &operator=(CRenderer2D &&) = default;
    static CRenderer2D *instance();
    static SDL_Renderer *renderer();

    // ARenderer interface
public:
    virtual void initialize() override;
    virtual bool ready() override;
    virtual bool openWindow(const char* title, int width, int height) override;
    virtual bool destroyWindow() override;
    virtual void beginDraw() override;
    virtual void endDraw() override;
    virtual void render() override;
};

#endif // CRENDERER2D_H
