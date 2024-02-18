#include "CRenderer3D.h"

CRenderer3D *CRenderer3D::s_instance = nullptr;
CRenderer3D::CRenderer3D()
{

}

CRenderer3D *CRenderer3D::instance()
{
    return s_instance = (s_instance == nullptr)? new CRenderer3D(): s_instance;
}

void CRenderer3D::quit()
{

}
