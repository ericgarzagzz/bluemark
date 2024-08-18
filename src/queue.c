#include "queue.h"

void queue_init(queue_t *q, int size) {
  q->front = -1;
  q->back = 0;
  q->size = size;
}

bool queue_is_empty(queue_t *q) { return q->front == q->back - 1; }

bool queue_is_full(queue_t *q) { return q->back == q->size; }

void queue_enqueue(queue_t *q, parsed_token_t *value) {
  if (queue_is_full(q)) {
    return;
  }

  q->items[q->back] = value;
  q->back++;
}

void queue_dequeue(queue_t *q) {
  if (queue_is_empty(q)) {
    return;
  }

  q->front++;
}

parsed_token_t *queue_peek(queue_t *q) {
  if (queue_is_empty(q)) {
    return 0;
  }

  return q->items[q->front + 1];
}
