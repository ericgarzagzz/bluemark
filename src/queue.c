#include "queue.h"

void queue_init(Queue *q, int size) {
  q->front = -1;
  q->back = 0;
  q->size = size;
}

bool queue_is_empty(Queue *q) { return q->front == q->back - 1; }

bool queue_is_full(Queue *q) { return q->back == q->size; }

void queue_enqueue(Queue *q, int value) {
  if (queue_is_full(q)) {
    return;
  }

  q->items[q->back] = value;
  q->back++;
}

void queue_dequeue(Queue *q) {
  if (queue_is_empty(q)) {
    return;
  }

  q->front++;
}

int queue_peek(Queue *q) {
  if (queue_is_empty(q)) {
    return -1;
  }

  return q->items[q->front + 1];
}
