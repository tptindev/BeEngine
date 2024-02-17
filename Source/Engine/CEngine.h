#ifndef __CENGINE_H__
#define __CENGINE_H__

#include "CObject.h"
#include "CTimer.h"

class CEngine: public CObject
{
private:
    static CEngine* s_instance;
    static bool s_running;
    explicit CEngine(CObject* parent = nullptr);
    ~CEngine();

    CTimer m_timer;

public:
    CEngine(CEngine &&) = delete;
    CEngine &operator=(CEngine &&) = delete;
    CEngine(CEngine &other) = delete;
    void operator=(const CEngine &) = delete;
    static CEngine *instance();

    bool initialize();
    void loop();
    void clean();
    void quit();
};

#endif // __CENGINE_H__
