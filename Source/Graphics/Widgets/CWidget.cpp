#include "CWidget.h"


CWidget::CWidget(CObject *parent) : CObject(parent)
{}

float CWidget::x() const
{
    return m_x;
}

void CWidget::setX(float newX)
{
    m_x = newX;
}

float CWidget::y() const
{
    return m_y;
}

void CWidget::setY(float newY)
{
    m_y = newY;
}

float CWidget::z() const
{
    return m_z;
}

void CWidget::setZ(float newZ)
{
    m_z = newZ;
}
