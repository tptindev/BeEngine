#ifndef __CENGINE_H__
#define __CENGINE_H__

class CEngine
{
private:
    static CEngine* s_instance;
    CEngine();

public:
    CEngine(CEngine &other) = delete;
    void operator=(const CEngine &) = delete;
    ~CEngine();
    static CEngine* instance();

    bool initialize();
    void loop();
    void clean();
    void quit();
};

#endif // __CENGINE_H__
