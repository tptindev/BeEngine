#include "CHomeUI.h"
#include <Widgets/CWindow.h>

CHomeUI::CHomeUI(CApplication* app): CLayer(app)
{
    m_start_btn = new CTextButton(app, "Quit");
    m_start_btn->init();
    m_start_btn->setWidth(50);
    m_start_btn->setHeight(25);
    m_start_btn->setX(app->window()->width() - m_start_btn->width());
    m_start_btn->setY(app->window()->height() - m_start_btn->height());

    this->subscribeToEvents(m_start_btn);

    app->window()->windowSizeChanged().connect([&](int w, int h){
        m_start_btn->setX(w - m_start_btn->width());
        m_start_btn->setY(h - m_start_btn->height());
    });
}

void CHomeUI::update(float dt)
{
    m_start_btn->update();
}

void CHomeUI::render()
{
    m_start_btn->render();
}
