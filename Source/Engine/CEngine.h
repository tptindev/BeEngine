#ifndef __CENGINE_H__
#define __CENGINE_H__

#include "CObject.h"

class CEngine: public CObject
{
private:
    static CEngine* s_instance;
    explicit CEngine(CObject* parent = nullptr);
    ~CEngine();

    bool m_running;

public:
    CEngine(CEngine &other) = delete;
    void operator=(const CEngine &) = delete;
    static CEngine* instance();

    bool initialize();
    void loop();
    void clean();
    void quit();
};

#endif // __CENGINE_H__
