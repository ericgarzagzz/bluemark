#include <stdbool.h>

typedef struct {
  int front;
  int back;
  int size;
  int items[];
} Queue;

void queue_init(Queue *q, int size);
bool queue_is_empty(Queue *q);
bool queue_is_full(Queue *q);
void queue_enqueue(Queue *q, int value);
void queue_dequeue(Queue *q);
int queue_peek(Queue *q);
