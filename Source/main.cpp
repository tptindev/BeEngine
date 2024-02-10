
#include <LoggerDefines.h>
#include <CEngine.h>
#include <CSinglyLinkedList.h>
#include <CDoublyLinkedList.h>
#include <Utils.h>
#include <CIterator.h>
#include <SNode.h>

int main(int argc, char *argv[])
{
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
