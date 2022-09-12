#ifndef _FZ_EVENT_H
#define _FZ_EVENT_H

// ----- Structures -----
/*! \brief Firezombie event type.
 * 
 *  The events are sent through dispatcher and used by the listeners.
 */
typedef struct fz_event_s {
  int type;
  bool bubbles;
  int data_size;
  void* data;
} fz_event;

typedef struct fz_event_listener_s {
  int id;
  void (*function)();
} fz_event_listener;

typedef struct fz_event_dispatcher_s {

} fz_event_dispatcher;

//---- Functions -----
fz_event* fz_event_create(int, bool, int, void*);
void fz_event_delete(fz_event*, void (*)(void *));

#endif // !_FZ_EVENT_H
