#ifndef __CENGINE_H__
#define __CENGINE_H__

#include "CObject.h"
#include "CTimer.h"

class CRenderer2D;
class CEngine: public CObject
{
private:
    static CEngine* s_instance;
    static bool s_running;
    explicit CEngine(CObject* parent = nullptr);
    ~CEngine();

    CRenderer2D* m_renderer;
    CTimer m_timer;

private:
    void handle_events();
    void update(float dt);
    void render();

public:
    CEngine(CEngine &&) = delete;
    CEngine &operator=(CEngine &&) = delete;
    CEngine(CEngine &other) = delete;
    void operator=(const CEngine &) = delete;
    static CEngine *instance();

    bool initialize(const char* title, float width, float height);
    void registerEvent();
    void loop();
    void clean();
    void quit();
};

#endif // __CENGINE_H__
