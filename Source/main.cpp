
#include <LoggerDefines.h>
#include <CEngine.h>
#include <Widgets/CWindow.h>
#include <Widgets/CApplication.h>

int main(int argc, char *argv[])
{
    CWindow window("BeEngine", 720, 480);
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

    return app.execute();
}
