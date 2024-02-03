#include "CHeapAllocator.h"
#include <LoggerDefines.h>
#include <Utils.h>

CHeapAllocator::CHeapAllocator()
{
    
}

CHeapAllocator::~CHeapAllocator()
{

}

void *CHeapAllocator::allocate(size_t size)
{
    void* ptr = std::malloc(size);
    if (!ptr) {
        _DEBUG("Failed to allocate memory!");
        std::exit(EXIT_FAILURE);
    }
    return ptr;
}

void CHeapAllocator::deallocate(void *ptr)
{
    safeRelease(ptr);
}
