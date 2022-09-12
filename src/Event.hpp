#pragma once

#include <map>
#include <vector>
#include "Types.hpp"

namespace FireZombie {
namespace Events {
class Event
{
public:
    static fz_uint8 const ADDED;
    static Event* fromPool(fz_uint8 type, fz_void* data);
    ~Event();
protected:
    fz_uint8 type;
    fz_void* data;

private:
    Event(fz_uint8 type, fz_void* data);
    void reset(fz_uint8 type);
    void reset(fz_uint8 type, fz_void* data);
    static std::vector<Event*> eventPool;
};
}
}
