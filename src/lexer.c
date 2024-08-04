#include "lexer.h"
#include "util.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <utils.h>

Queue *lexer_parse(char *input) {
  int q_size = 512;
  Queue *tokens_q = malloc(sizeof(Queue) + q_size * sizeof(ParsedToken));
  if (tokens_q == NULL) {
    perror("bluemark: ");
  }
  queue_init(tokens_q, q_size);

  bool reading_str = false;
  char processing_input[strlen(input) + 1];
  processing_input[0] = '\0';
  ParsedToken **last_token_ref;
  for (int i = 0; i < strlen(input); i++) {
    char current = input[i];
    if (!reading_str && current == ' ') {
      continue;
    }
    str_append(processing_input, current);

    Token token = token_identify(processing_input);

    if (reading_str) {
      if (token == TOKEN_QUOTE || token == TOKEN_DOUBLEQUOTE) {
        int start_pos = (*last_token_ref)->start_position + 1;
        int end_pos = i - 1;

        ParsedToken *pt = parsed_token_alloc(TOKEN_STRING, start_pos, end_pos);
        memcpy(pt->value, input + start_pos, end_pos);
        size_t value_len = (end_pos - start_pos) + 1;
        pt->value[value_len] = '\0';
        queue_enqueue(tokens_q, pt);

        ParsedToken *pt2 = parsed_token_alloc(token, i, i);
        strcpy(pt2->value, processing_input);
        queue_enqueue(tokens_q, pt2);

        last_token_ref = NULL;
        reading_str = false;
        processing_input[0] = '\0';
      } else {
        processing_input[0] = '\0';
      }
    } else {
      if (token == TOKEN_UNRECOGNIZED) {
        continue;
      }

      if (token == TOKEN_QUOTE || token == TOKEN_DOUBLEQUOTE) {
        ParsedToken *pt = parsed_token_alloc(token, i, i);
        strcpy(pt->value, processing_input);
        queue_enqueue(tokens_q, pt);
        last_token_ref = &pt;
        reading_str = true;
        processing_input[0] = '\0';
      } else {
        int start_pos = i - (strlen(processing_input) - 1);
        ParsedToken *pt = parsed_token_alloc(token, start_pos, i);
        strcpy(pt->value, processing_input);
        queue_enqueue(tokens_q, pt);
        processing_input[0] = '\0';
      }
    }
  }

  return tokens_q;
}
