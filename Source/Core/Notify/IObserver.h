#ifndef IOBSERVER_H
#define IOBSERVER_H

#include <stdint.h>

class IObserver
{
private:
    friend class CSignalPool;
protected:
    virtual void onNotify(uint8_t id, void* data) {}; // notify
};

#endif // IOBSERVER_H
