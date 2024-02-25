#ifndef CLAYER_H
#define CLAYER_H

#include <vector>
#include <Widgets/CApplication.h>
#include <SDL_events.h>

class AEventReceiver;
class CPainter;
class CEventDispatcher;
class CLayer
{
public:
    CLayer(CApplication* app);

    virtual void update(float) = 0;
    virtual void render() = 0;

    bool handleEvent(const SDL_Event*);
    void subscribeToEvents(AEventReceiver*);

private:
    std::vector<AEventReceiver*> m_receivers;
    CApplication* m_app;
};

#endif // CLAYER_H
