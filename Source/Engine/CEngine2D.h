#ifndef __CENGINE2D_H__
#define __CENGINE2D_H__

#include "CObject.h"
#include "CTimer.h"
#include <CSignal.h>

class CSDLWindow;
class CRenderer2D;
class CEngine2D: public CObject
{
private:
    static CEngine2D* s_instance;
    static bool s_running;
    explicit CEngine2D(CObject* parent = nullptr);
    ~CEngine2D();

    CRenderer2D* m_renderer = nullptr;
    CTimer m_timer;


    // signals:
    CSignal<void, bool> m_window_full;

private:
    void handle_events();
    void update(float dt);
    void render();

public:
    CEngine2D(CEngine2D &&) = delete;
    CEngine2D &operator=(CEngine2D &&) = delete;
    CEngine2D(CEngine2D &other) = delete;
    void operator=(const CEngine2D &) = delete;
    static CEngine2D *instance();
    
    bool initialize(CSDLWindow* window);
    void registerEvent();
    void loop();
    void clean();
    void quit();
};

#endif // __CENGINE2D_H__
