#ifndef CSIGNALDISPATCHER_H
#define CSIGNALDISPATCHER_H


class CSignalDispatcher
{
private:
    static CSignalDispatcher* s_instance;
    CSignalDispatcher();
    ~CSignalDispatcher();

public:
    CSignalDispatcher(const CSignalDispatcher& other) = delete;
    void operator=(const CSignalDispatcher& other) = delete;

    static CSignalDispatcher* instance();

};

#endif // CSIGNALDISPATCHER_H
