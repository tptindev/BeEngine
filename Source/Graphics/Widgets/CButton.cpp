#include "CButton.h"
#include <SDL_render.h>
#include <SDL_image.h>

CButton::CButton(const char* src, CObject *parent) : CWidget(parent)
{
    m_texture = nullptr;
    m_texture = IMG_LoadTexture(nullptr, src);
}

bool CButton::handleEvent(const SDL_Event *event)
{
    return false;
}
