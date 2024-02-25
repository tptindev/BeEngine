#include "CHomeUI.h"
#include <Widgets/CWindow.h>

CHomeUI::CHomeUI(CApplication* app): CLayer(app)
{
    int spacing = 25;
    {
        m_start_btn = new CTextButton(app, "Start");
        m_start_btn->init();
        m_start_btn->setWidth(200);
        m_start_btn->setHeight(75);
        m_start_btn->setX((app->window()->width() / 3) - m_start_btn->width() / 2);
        m_start_btn->setY((app->window()->height() / 3)- m_start_btn->height() / 2);
        m_start_btn->stateChanged().connect([&](CButton::E_BTN_STATE state){
            if(state == CButton::E_BTN_STATE::CLICKED)
            {
                this->start();
            }
        });
    }
    {
        m_options_btn = new CTextButton(app, "Options");
        m_options_btn->init();
        m_options_btn->setWidth(200);
        m_options_btn->setHeight(75);
        m_options_btn->setX(m_start_btn->x());
        m_options_btn->setY(m_start_btn->y() + m_start_btn->height() + spacing);
        m_options_btn->stateChanged().connect([&](CButton::E_BTN_STATE state){
            if(state == CButton::E_BTN_STATE::CLICKED)
            {
                this->options();
            }
        });
    }
    { // Define quit button
        m_quit_btn = new CTextButton(app, "Quit");
        m_quit_btn->init();
        m_quit_btn->setWidth(50);
        m_quit_btn->setHeight(25);
        m_quit_btn->setX(app->window()->width() - m_quit_btn->width());
        m_quit_btn->setY(0);
        m_quit_btn->stateChanged().connect([&](CButton::E_BTN_STATE state){
            if(state == CButton::E_BTN_STATE::CLICKED)
            {
                this->quit();
            }
        });
    }
    this->subscribeToEvents(m_start_btn);
    this->subscribeToEvents(m_options_btn);
    this->subscribeToEvents(m_quit_btn);

    // common
    app->window()->windowSizeChanged().connect([&](int w, int h){
        // start btn
        m_start_btn->setX((w / 3) - m_start_btn->width() / 2);
        m_start_btn->setY((h / 3)- m_start_btn->height() / 2);

        // options btn
        m_options_btn->setX(m_start_btn->x());
        m_options_btn->setY(m_start_btn->y() + m_start_btn->height() + 25);

        // quit btn
        m_quit_btn->setX(w - m_quit_btn->width());
        m_quit_btn->setY(0);

    });
}

void CHomeUI::start()
{

}

void CHomeUI::options()
{

}

void CHomeUI::quit()
{
    m_app->quit();
}

void CHomeUI::update(float dt)
{
    m_start_btn->update();
    m_options_btn->update();
    m_quit_btn->update();
}

void CHomeUI::render()
{
    m_start_btn->render();
    m_options_btn->render();
    m_quit_btn->render();
}
