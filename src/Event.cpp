#include "Event.hpp"
#include "Types.hpp"

using namespace FireZombie::Events;

fz_uint8 const Event::ADDED = 0;

Event* Event::fromPool(fz_uint8 type, fz_void *data) {
  if(Event::eventPool.empty())
    return new Event(type, data);
  Event* e = Event::eventPool.back();
  e->reset(type, data);
  Event::eventPool.pop_back();
  return e;
}

void Event::reset(fz_uint8 type) {
  this->type = type;
  this->data = fz_null;
}

void Event::reset(fz_uint8 type, fz_void * data) {
  this->type = type;
  this->data = data;
}


Event::Event(fz_uint8 type, fz_void* data) {
  this->type = type;
  this->data = data;
}

Event::~Event()
{
}
