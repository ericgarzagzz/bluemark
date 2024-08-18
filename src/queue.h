#ifndef QUEUE_H
#define QUEUE_H

#include "tokens.h"
#include <stdbool.h>

struct queue {
  int front;
  int back;
  int size;
  parsed_token_t *items[];
};

typedef struct queue queue_t;

void queue_init(queue_t *q, int size);
bool queue_is_empty(queue_t *q);
bool queue_is_full(queue_t *q);
void queue_enqueue(queue_t *q, parsed_token_t *value);
void queue_dequeue(queue_t *q);
parsed_token_t *queue_peek(queue_t *q);

#endif
