
#include <LoggerDefines.h>
#include <CEngine.h>
#include <Utils.h>
#include <CHashTable.h>
#include <CDoublyLinkedList.h>

int main(int argc, char *argv[])
{

    CDoublyLinkedList<int> list;
    list.push_back(9);
    list.push_front(1);
    list.push_back(5);
    list.push_back(6);

    std::cout << &list << std::endl;

    _DEBUG("%d", list[2]);


    CHashTable<const char*, int> hashTable(256);
    hashTable.insert("Tinne", &list[0]);
    hashTable.insert("King", &list[1]);

    std::cout << hashTable << std::endl;

    bool initialized = CEngine::instance()->initialize();
    if(initialized)
    {
        CEngine::instance()->loop();
        CEngine::instance()->clean();
        CEngine::instance()->quit();
    }
    else
    {
        _DEBUG("Can't initialize Game Game");
    }

    return 0;
}
