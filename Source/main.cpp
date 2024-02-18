
#include <LoggerDefines.h>
#include <CEngine.h>
#include <Widgets/CWindow.h>

int main(int argc, char *argv[])
{
    CWindow window("xin_chao", 720, 480);
    bool initialized = CEngine::instance()->initialize(&window);
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
