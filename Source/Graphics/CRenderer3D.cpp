#include "CRenderer3D.h"

CRenderer3D *CRenderer3D::s_instance = nullptr;
CRenderer3D::CRenderer3D()
{

}

CRenderer3D *CRenderer3D::instance()
{
    return s_instance = (s_instance == nullptr)? new CRenderer3D(): s_instance;
}

void CRenderer3D::initialize()
{

}

bool CRenderer3D::ready()
{
    return false;
}

bool CRenderer3D::openWindow(CWindow* window)
{
    return false;
}

bool CRenderer3D::destroyWindow()
{
    return false;
}

void CRenderer3D::quit()
{

}

void CRenderer3D::beginDraw()
{

}

void CRenderer3D::endDraw()
{

}
