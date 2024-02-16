
#include <LoggerDefines.h>
#include <CEngine.h>
#include <Utils.h>
#include <CHash.h>

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
