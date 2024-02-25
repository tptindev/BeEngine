#ifndef CWORLDUI_H
#define CWORLDUI_H

#include <Widgets/CLayer.h>

class CWorldUI: public CLayer
{
public:
    CWorldUI(CApplication *app);

    // CLayer interface
public:
    virtual void update(float) override;
    virtual void render() override;
};

#endif // CWORLDUI_H
