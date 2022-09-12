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

//---- Functions -----
fz_event* fz_event_create(int, bool, int, void*);

#endif // !_FZ_EVENT_H
