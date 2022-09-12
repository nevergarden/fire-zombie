#include <stdbool.h>
#include <stdlib.h>

#include "firezombie.h"

fz_event* fz_event_create(int type, bool bubbles, int data_size, void * data) {
  fz_event * event = malloc(sizeof(fz_event));
  event->type = type;
  event->bubbles = bubbles;
  event->data_size = data_size;
  event->data = data;

  return event;
}
