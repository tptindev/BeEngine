#ifndef __CENGINE_H__
#define __CENGINE_H__

#include "CObjWrapper.h"

class CEngine
{
private:
    static CEngine* s_instance;
    CEngine();
    ~CEngine();

    CObjWrapper<bool> m_running;

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
