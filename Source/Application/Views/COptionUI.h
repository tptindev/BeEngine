#ifndef COPTIONUI_H
#define COPTIONUI_H

#include <Widgets/CLayer.h>

class COptionUI : public CLayer
{
public:
    COptionUI(CApplication *app);

    // CLayer interface
public:
    virtual void update(float) override;
    virtual void render() override;
};

#endif // COPTIONUI_H
