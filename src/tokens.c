#include "tokens.h"
#include <stdlib.h>
#include <string.h>

token_t token_identify(const char *str) {
  if (strcmp(str, "Html") == 0) {
    return TOKEN_HTML_TAG;
  } else if (strcmp(str, "Head") == 0) {
    return TOKEN_HEAD_TAG;
  } else if (strcmp(str, "Body") == 0) {
    return TOKEN_BODY_TAG;
  } else if (strcmp(str, "Title") == 0) {
    return TOKEN_TITLE_TAG;
  } else if (strcmp(str, "Meta") == 0) {
    return TOKEN_META_TAG;
  } else if (strcmp(str, "Div") == 0) {
    return TOKEN_DIV_TAG;
  } else if (strcmp(str, "H1") == 0) {
    return TOKEN_H1_TAG;
  } else if (strcmp(str, "P") == 0) {
    return TOKEN_P_TAG;
  } else if (strcmp(str, "A") == 0) {
    return TOKEN_A_TAG;
  } else if (strcmp(str, "{") == 0) {
    return TOKEN_BRACE_OPEN;
  } else if (strcmp(str, "}") == 0) {
    return TOKEN_BRACE_CLOSE;
  } else if (strcmp(str, "[") == 0) {
    return TOKEN_BRACKET_OPEN;
  } else if (strcmp(str, "]") == 0) {
    return TOKEN_BRACKET_CLOSE;
  } else if (strcmp(str, "(") == 0) {
    return TOKEN_PARENTHESIS_OPEN;
  } else if (strcmp(str, ")") == 0) {
    return TOKEN_PARENTHESIS_CLOSE;
  } else if (strcmp(str, "\"") == 0) {
    return TOKEN_DOUBLEQUOTE;
  } else if (strcmp(str, "'") == 0) {
    return TOKEN_QUOTE;
  }

  return TOKEN_UNRECOGNIZED;
}

parsed_token_t *parsed_token_alloc(token_t token, int start_pos, int end_pos) {
  parsed_token_t *pt = malloc(sizeof(parsed_token_t));
  pt->token = token;
  pt->start_position = start_pos;
  pt->end_position = end_pos;
  pt->value[0] = '\0';
  return pt;
}
