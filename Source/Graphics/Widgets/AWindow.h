#ifndef AWINDOW_H
#define AWINDOW_H

#include <CObject.h>
#include <CSignal.h>

class AWindow
{
public:
    const char *title() const;
    int width() const;
    int height() const;
    int x() const;
    int y() const;
    bool is_full() const;
    bool active() const;

    virtual void update_window_surface() = 0;


protected:
    const char* m_title;
    int m_width, m_height;
    int m_x, m_y;
    bool m_is_full {false};
    bool m_active {true};
};

#endif // AWINDOW_H
