#ifndef TOKENS_H
#define TOKENS_H

typedef enum token {
  TOKEN_HTML_TAG = 0,
  TOKEN_HEAD_TAG = 1,
  TOKEN_BODY_TAG = 2,
  TOKEN_TITLE_TAG = 3,
  TOKEN_META_TAG = 4,
  TOKEN_DIV_TAG = 5,
  TOKEN_H1_TAG = 6,
  TOKEN_P_TAG = 7,
  TOKEN_A_TAG = 8,
  TOKEN_BRACKET_OPEN = 9,
  TOKEN_BRACKET_CLOSE = 10,
  TOKEN_BRACE_OPEN = 11,
  TOKEN_BRACE_CLOSE = 12,
  TOKEN_PARENTHESIS_OPEN = 13,
  TOKEN_PARENTHESIS_CLOSE = 14,
  TOKEN_DOUBLEQUOTE = 15,
  TOKEN_QUOTE = 16,
  TOKEN_STRING = 17,
  TOKEN_UNRECOGNIZED = 18
} token_t;

typedef struct parsed_token {
  token_t token;
  int start_position;
  int end_position;
  char value[2048];
} parsed_token_t;

token_t token_identify(const char *str);
void parsed_token_init(parsed_token_t *self);

#endif
