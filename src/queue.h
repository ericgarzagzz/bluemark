#ifndef QUEUE_H
#define QUEUE_H

#include "tokens.h"
#include <stdbool.h>

typedef struct queue {
  int front;
  int back;
  int size;
  parsed_token_t *items[];
} queue_t;

void queue_init(queue_t *self, int size);
bool queue_is_empty(queue_t *self);
bool queue_is_full(queue_t *self);
void queue_enqueue(queue_t *self, parsed_token_t *value);
void queue_dequeue(queue_t *self);
parsed_token_t *queue_peek(queue_t *self);

#endif
