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

void fz_event_delete(fz_event* event, void (*free_func)(void *)) {
  if(free_func != NULL && event->data != NULL)
    free_func(event->data);
  free(event);
}
