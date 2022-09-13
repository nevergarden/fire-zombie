#include "Event.hpp"
#include "Types.hpp"
#include <vector>

using namespace FireZombie::Events;

fz_uint8 const Event::ADDED = 0;

std::vector<Event*> Event::eventPool;

Event* Event::fromPool(fz_uint8 type, fz_void *data) {
  if(Event::eventPool.empty())
    return new Event(type, data);
  Event* e = Event::eventPool.back();
  e->reset(type, data);
  Event::eventPool.pop_back();
  return e;
}

fz_void Event::toPool(Event *event) {
  Event::eventPool.push_back(event);
}

fz_void Event::reset(fz_uint8 type) {
  this->type = type;
  this->data = fz_null;
}

fz_void Event::reset(fz_uint8 type, fz_void * data) {
  this->type = type;
  this->data = data;
}

fz_uint8 Event::getType() {
  return this->type;
}

fz_void Event::setType(fz_uint8 type) {
  this->type = type;
}

fz_void* Event::getData() {
  return this->data;
}

fz_void Event::setData(fz_void *data) {
  this->data = data;
}

Event::Event(fz_uint8 type, fz_void* data) {
  this->type = type;
  this->data = data;
}
