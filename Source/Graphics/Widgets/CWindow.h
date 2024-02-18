#ifndef CWINDOW_H
#define CWINDOW_H

#include <CObject.h>
#include <CSignal.h>

class CWindow : public CObject
{
public:
    CWindow();
    CWindow(const char *m_title, int m_width, int m_height, bool m_is_full = false);
    ~CWindow();

    void toggleIsFull();
    const char *title() const;
    int width() const;
    int height() const;

    CSignal<void, bool>& signalIsFull();

private:
    const char* m_title;
    int m_width, m_height;
    bool m_is_full;


private: // signals declare
    CSignal<void, bool> m_signal_is_full;
};

#endif // CWINDOW_H
