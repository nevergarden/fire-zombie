#ifndef _FZ_EVENT_H
#define _FZ_EVENT_H

typedef struct fz_event_s {
  int id;
  bool bubbles;
  int data_size;
  void* data;
} fz_event;

#endif // !_FZ_EVENT_H
