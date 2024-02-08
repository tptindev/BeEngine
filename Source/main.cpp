
#include <LoggerDefines.h>
#include <CEngine.h>
#include <CSinglyLinkedList.h>
#include <CDoublyLinkedList.h>
#include <Utils.h>
#include <CIterator.h>
#include <SNode.h>
#include <CPoolSignals.h>

int main(int argc, char *argv[])
{
    CDoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(0);
    list.push_back(3);
    list.push_back(-9);
    list.push_front(5);
    list.push_front(7);
    list.push_front(1);
    list.push_front(9);
    list.emplace_front(33);
    list.emplace_back(99);
    list.push_front(8);


    std::cout << &list <<std::endl;
    list.pop_front();
    list.pop_back();
    list.pop_back();
    list.pop_back();

    std::cout << &list <<std::endl;
    std::cout << list.head() << ", " << list.tail() << std::endl;

//    CDoublyLinkedList<int>::iterator it = list.begin();
//    while (it != list.end())
//    {
//        if((*it) == 0)
//        {
//            list.erase(it);
//            break;
//        }
//        ++it;
//    }

//    std::cout << &list <<std::endl;

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
