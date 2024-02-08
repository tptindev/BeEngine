#ifndef CPOOLSIGNALS_H
#define CPOOLSIGNALS_H


class CPoolSignals
{
private:
    static CPoolSignals* s_instance;
    CPoolSignals();
    ~CPoolSignals();

public:
    CPoolSignals(const CPoolSignals& other) = delete;
    void operator=(const CPoolSignals& other) = delete;

    static CPoolSignals* instance();

};

#endif // CPOOLSIGNALS_H
