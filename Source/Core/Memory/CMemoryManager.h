#ifndef CMEMORYMANAGER_H
#define CMEMORYMANAGER_H


class CMemoryManager
{
private:
    static CMemoryManager* s_instance;
    CMemoryManager();

public:
    CMemoryManager(CMemoryManager &other) = delete;
    void operator=(const CMemoryManager &) = delete;
    ~CMemoryManager();
    static CMemoryManager* instance();
};

#endif // CMEMORYMANAGER_H
