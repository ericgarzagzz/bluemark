#include "tokens.h"
#include <stdbool.h>

typedef struct {
  int front;
  int back;
  int size;
  ParsedToken *items[];
} Queue;

void queue_init(Queue *q, int size);
bool queue_is_empty(Queue *q);
bool queue_is_full(Queue *q);
void queue_enqueue(Queue *q, ParsedToken *value);
void queue_dequeue(Queue *q);
ParsedToken *queue_peek(Queue *q);
