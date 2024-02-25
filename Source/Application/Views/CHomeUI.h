#ifndef CHOMEUI_H
#define CHOMEUI_H

#include <Widgets/CLayer.h>
#include <Widgets/CButton.h>

class CHomeUI: public CLayer
{
public:
    explicit CHomeUI(CApplication* app);
private:
    CTextButton *m_start_btn;

    // CLayer interface
public:
    virtual void update(float) override;
    virtual void render() override;
};

#endif // CHOMEUI_H
