
#include <LoggerDefines.h>
#include <CEngine.h>
#include <Widgets/CWindow.h>
#include <Widgets/CApplication.h>
#include <Widgets/CLayer.h>
#include <Views/CHomeUI.h>
#include <Views/CWorldUI.h>

int main(int argc, char *argv[])
{
    CWindow window("BeEngine", 980, 720);
    CApplication app(&window);
    CHomeUI UI(&app);
    CWorldUI World(&app);

    window.registerLayer(&UI);
    window.registerLayer(&World);

    return app.execute();
}
