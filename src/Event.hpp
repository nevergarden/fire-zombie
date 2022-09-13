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
    static fz_void toPool(Event* event);
    
    fz_uint8 getType();
    fz_void setType(fz_uint8 type);

    fz_void* getData();
    fz_void setData(fz_void* data);

protected:
    fz_uint8 type;
    fz_void* data;

private:
    Event(fz_uint8 type, fz_void* data);
    fz_void reset(fz_uint8 type);
    fz_void reset(fz_uint8 type, fz_void* data);
    static std::vector<Event*> eventPool;
};
}
}
