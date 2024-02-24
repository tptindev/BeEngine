#ifndef ARENDERER_H
#define ARENDERER_H

class AWindow;
class ARenderer
{
public:
    virtual void initialize() = 0;
    virtual bool ready() = 0;
    virtual bool openWindow(AWindow* window) = 0;
    virtual bool destroyWindow() = 0;
    virtual void quit() = 0;
    virtual void beginDraw() = 0;
    virtual void endDraw() = 0;
};

#endif // ARENDERER_H
