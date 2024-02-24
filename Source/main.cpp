
#include <LoggerDefines.h>
#include <CEngine.h>
#include <Widgets/CSDLWindow.h>
#include <Widgets/CApplication.h>

int main(int argc, char *argv[])
{
    CSDLWindow window("BeEngine", 720, 480);
    CApplication app(&window);

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
