#ifndef CWORLDUI_H
#define CWORLDUI_H

#include <Widgets/CLayer.h>
#include <Widgets/CButton.h>

class CWorldUI: public CLayer
{
public:
    CWorldUI(CApplication *app);

    // CLayer interface
public:
    virtual void update(float) override;
    virtual void render() override;

private:
    CTextButton* m_home_btn;

private:
    void home();
};

#endif // CWORLDUI_H
