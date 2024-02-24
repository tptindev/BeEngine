#include "CWindow.h"

CWindow::CWindow()
    :m_title("Undefined"), m_width(720), m_height(480), m_is_full(false), m_active(true) {}

CWindow::CWindow(const char *m_title, int m_width, int m_height, bool m_is_full)
    : m_title(m_title), m_width(m_width), m_height(m_height),
    m_is_full(m_is_full), m_active(true)
{}

CWindow::~CWindow()
{

}

const char *CWindow::title() const
{
    return m_title;
}

int CWindow::width() const
{
    return m_width;
}

int CWindow::height() const
{
    return m_height;
}

CSignal<void, bool> &CWindow::stateChanged()
{
    return m_state_changed;
}

int CWindow::x() const
{
    return m_x;
}

int CWindow::y() const
{
    return m_y;
}

void CWindow::toggleIsFull()
{
    m_is_full = !m_is_full;
    m_state_changed.emit(std::move(m_is_full));
}
