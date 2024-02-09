#ifndef IOBSERVER_H
#define IOBSERVER_H

#include <stdint.h>

class IObserver
{
protected:
    virtual void onNotify(uint8_t id, void* data) = 0; // notify
};

#endif // IOBSERVER_H
