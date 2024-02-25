#ifndef CTEXT_H
#define CTEXT_H

#include <Widgets/CWidget.h>
#include <SDL_ttf.h>

class CText : public CWidget
{
public:
    CText();

private:
    int m_pixel_size;
    SDL_Color m_color;
    TTF_Font* m_font;
    float m_content_width, m_content_height;
    bool m_antialiasing{true};

    // CWidget interface
public:
    virtual void init() override;
    virtual void update() override;
    virtual void render() override;
};

#endif // CTEXT_H
