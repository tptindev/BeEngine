#ifndef CBUTTON_H
#define CBUTTON_H

#include "CWidget.h"
#include "CMouseArea.h"

class SDL_Texture;
class CButton : public CWidget
{
private:
    SDL_Texture* m_texture;
    CMouseArea* m_mouse;

public:
    CButton(const char* src, CObject *parent = nullptr);
};

#endif // CBUTTON_H
