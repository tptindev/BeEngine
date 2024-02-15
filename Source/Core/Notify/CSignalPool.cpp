#include "CSignalPool.h"

CSignalPool *CSignalPool::s_instance = nullptr;
CSignalPool::CSignalPool()
{

}

CSignalPool::~CSignalPool()
{

}

CSignalPool *CSignalPool::instance()
{
    return s_instance = (s_instance == nullptr)? new CSignalPool(): s_instance;
}

