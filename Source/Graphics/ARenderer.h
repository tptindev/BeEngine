#ifndef ARENDERER_H
#define ARENDERER_H

class ARenderer
{
public:
    virtual void initialize() = 0;
    virtual bool ready() = 0;
    virtual bool openWindow(const char* title, int width, int height) = 0;
    virtual bool destroyWindow() = 0;
    virtual void quit() = 0;
    virtual void beginDraw() = 0;
    virtual void endDraw() = 0;
    virtual void render() {}
};

#endif // ARENDERER_H
