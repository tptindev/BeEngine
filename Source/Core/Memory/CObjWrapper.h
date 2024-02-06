#ifndef COBJWRAPPER_H
#define COBJWRAPPER_H

#include <utility>

template<typename T>
class CObjWrapper
{
private:
    T* m_data;
public:
    CObjWrapper(): m_data(nullptr){}

    explicit CObjWrapper(T* other): m_data(other){}

    void operator=(T &&value)
    {
        *m_data = value;
    }

    T value()
    {
        return *m_data;
    }
};

#endif // COBJWRAPPER_H
