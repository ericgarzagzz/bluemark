#include "queue.h"
#include <stdlib.h>

typedef enum Token {
  HTML_TAG,
  HEAD_TAG,
  BODY_TAG,
  TITLE_TAG,
  META_TAG,
  DIV_TAG,
  H1_TAG,
  P_TAG,
  A_TAG,
  BRACKET_OPEN,
  BRACKET_CLOSE,
  BRACE_OPEN,
  BRACE_CLOSE,
  PARENTHESIS_OPEN,
  PARENTHESIS_CLOSE
} Token;

Queue *read_tokens(char *input);
