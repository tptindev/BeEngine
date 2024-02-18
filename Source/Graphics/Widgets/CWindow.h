#ifndef CWINDOW_H
#define CWINDOW_H

#include <CObject.h>

class CWindow : public CObject
{
private:
    const char* m_title;
    int m_width, m_height;
    bool m_is_full;
public:
    CWindow();
};

#endif // CWINDOW_H
