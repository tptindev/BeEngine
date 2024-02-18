#ifndef ARENDERER_H
#define ARENDERER_H

class CWindow;
class ARenderer
{
public:
    virtual void initialize() = 0;
    virtual bool ready() = 0;
    virtual bool openWindow(CWindow* window) = 0;
    virtual bool destroyWindow() = 0;
    virtual void quit() = 0;
    virtual void beginDraw() = 0;
    virtual void endDraw() = 0;
};

#endif // ARENDERER_H
