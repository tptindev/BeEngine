#include "CButton.h"
#include <SDL_render.h>
#include <SDL_image.h>

CButton::CButton(const char* src, CObject *parent) : CWidget(parent)
{
    m_texture = nullptr;
    m_texture = IMG_LoadTexture(nullptr, src);

    m_mouse = new CMouseArea(this);
}
