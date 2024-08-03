#define QUEUE_MAX_SIZE 256

#include <stdbool.h>

typedef struct Queue {
  int items[QUEUE_MAX_SIZE];
  int front;
  int back;
} Queue;

void queue_init(Queue *q);
bool queue_is_empty(Queue *q);
bool queue_is_full(Queue *q);
void queue_enqueue(Queue *q, int value);
void queue_dequeue(Queue *q);
int queue_peek(Queue *q);
