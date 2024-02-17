#ifndef CRENDERER3D_H
#define CRENDERER3D_H

#include "ARenderer.h"

class CRenderer3D : public ARenderer
{
private:
    static CRenderer3D* s_instance;
    CRenderer3D();
public:
    CRenderer3D(const CRenderer3D &) = delete;
    CRenderer3D(CRenderer3D &&) = delete;
    CRenderer3D &operator=(const CRenderer3D &) = delete;
    CRenderer3D &operator=(CRenderer3D &&) = delete;
    static CRenderer3D *instance();

    // ARenderer interface
public:
    virtual void initialize() override;
    virtual bool ready() override;
    virtual bool openWindow(const char *title, int width, int height) override;
    virtual bool destroyWindow() override;
    virtual void beginDraw() override;
    virtual void endDraw() override;
};

#endif // CRENDERER3D_H
