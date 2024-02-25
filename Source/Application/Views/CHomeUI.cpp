#include "CHomeUI.h"


CHomeUI::CHomeUI(CApplication* app): CLayer(app)
{
    m_start_btn = new CTextButton(app);
    m_start_btn->init();
    this->subscribeToEvents(m_start_btn);
}

void CHomeUI::update(float dt)
{
    m_start_btn->update();
}

void CHomeUI::render()
{
    m_start_btn->render();
}
