#ifndef CWIDGET_H
#define CWIDGET_H

#include <CObject.h>

class CWidget : public CObject
{
public:
    CWidget(CObject *parent = nullptr);

    float x() const;
    void setX(float newX);
    float y() const;
    void setY(float newY);
    float z() const;
    void setZ(float newZ);
protected:
    float m_x, m_y, m_z;
};

#endif // CWIDGET_H
