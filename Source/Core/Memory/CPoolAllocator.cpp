#include "CPoolAllocator.h"
#include <Utils.h>

CPoolAllocator::CPoolAllocator()
{

}

void *CPoolAllocator::allocate(size_t)
{
    return nullptr;
}

void CPoolAllocator::deallocate(void *ptr)
{
    safeRelease(ptr);
}
