#ifndef CMEMORYMANAGER_H
#define CMEMORYMANAGER_H


class CMemoryManager
{
private:
    static CMemoryManager* s_instance;
    CMemoryManager();

public:
    static CMemoryManager* instance();
};

#endif // CMEMORYMANAGER_H
