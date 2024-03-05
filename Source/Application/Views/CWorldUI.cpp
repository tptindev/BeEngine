#include "CWorldUI.h"
#include <Widgets/CApplication.h>
#include <Widgets/CWindow.h>

CWorldUI::CWorldUI(CApplication *app) : CLayer(app)
{
    { // home btn
        m_home_btn = new CTextButton(app, "Home");
        m_home_btn->init();
        m_home_btn->setWidth(50);
        m_home_btn->setHeight(25);
        m_home_btn->setX(app->window()->width() - m_home_btn->width());
        m_home_btn->setY(0);
        m_home_btn->stateChanged().connect([&](CButton::E_BTN_STATE state){
            if(state == CButton::E_BTN_STATE::CLICKED)
            {
                this->home();
            }
        });
    }

    this->subscribeToEvents(m_home_btn);
    // common
    app->window()->windowSizeChanged().connect([&](int w, int h){
        // quit btn
        m_home_btn->setX(w - m_home_btn->width());
        m_home_btn->setY(0);

    });
}

void CWorldUI::update(float)
{
    m_home_btn->update();
}

void CWorldUI::render()
{
    m_home_btn->render();
}

void CWorldUI::home()
{

}

