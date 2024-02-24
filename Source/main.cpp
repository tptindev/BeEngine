
#include <LoggerDefines.h>
#include <CEngine2D.h>
#include <Widgets/CSDLWindow.h>
#include <Widgets/CApplication.h>

int main(int argc, char *argv[])
{
    CSDLWindow window("BeEngine", 720, 480);
    CApplication app(&window);

    bool initialized = CEngine2D::instance()->initialize(&window);
    if(initialized)
    {
        CEngine2D::instance()->loop();
        CEngine2D::instance()->clean();
        CEngine2D::instance()->quit();
    }
    else
    {
        _DEBUG("Can't initialize Game Game");
    }

    return app.execute();
}
