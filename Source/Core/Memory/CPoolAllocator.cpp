#include "CPoolAllocator.h"
#include <Utils.h>
#include <cstring>

CPoolAllocator::CPoolAllocator()
{

}

void *CPoolAllocator::allocate(size_t)
{
    return nullptr;
}

void CPoolAllocator::deallocate(void *ptr, size_t size)
{
    memset(ptr, 0x0, size);
}
