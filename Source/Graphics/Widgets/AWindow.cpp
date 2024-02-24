#include "AWindow.h"

const char *AWindow::title() const
{
    return m_title;
}

int AWindow::width() const
{
    return m_width;
}

int AWindow::height() const
{
    return m_height;
}

int AWindow::x() const
{
    return m_x;
}

int AWindow::y() const
{
    return m_y;
}

bool AWindow::is_full() const
{
    return m_is_full;
}

bool AWindow::active() const
{
    return m_active;
}

