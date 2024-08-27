#include "queue.h"
#include <string.h>

void queue_init(queue_t *self, int size) {
  memset(self, 0, sizeof(queue_t));

  self->front = -1;
  self->back = 0;
  self->size = size;
}

bool queue_is_empty(queue_t *self) { return self->front == self->back - 1; }

bool queue_is_full(queue_t *self) { return self->back == self->size; }

void queue_enqueue(queue_t *self, parsed_token_t *value) {
  if (queue_is_full(self)) {
    return;
  }

  self->items[self->back] = value;
  self->back++;
}

void queue_dequeue(queue_t *self) {
  if (queue_is_empty(self)) {
    return;
  }

  self->front++;
}

parsed_token_t *queue_peek(queue_t *self) {
  if (queue_is_empty(self)) {
    return 0;
  }

  return self->items[self->front + 1];
}
