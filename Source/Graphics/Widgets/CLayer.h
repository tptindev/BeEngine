#ifndef CLAYER_H
#define CLAYER_H

class CEventReceiver;
class CEventDispatcher;
class CLayer
{
public:
    CLayer();

    void subcribeToEvent(CEventReceiver*);

private:
    CEventDispatcher* m_dispatcher;
};

#endif // CLAYER_H
