#include "lexer.h"
#include "tokens.h"
#include "util.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <utils.h>

queue_t *lexer_parse(char *input) {
  int q_size = 512;
  queue_t *tokens_q = malloc(sizeof(queue_t) + q_size * sizeof(parsed_token_t));
  if (tokens_q == NULL) {
    perror("bluemark: ");
  }
  queue_init(tokens_q, q_size);

  bool reading_str = false;
  char processing_input[strlen(input) + 1];
  processing_input[0] = '\0';
  parsed_token_t **last_token_ref;
  for (int i = 0; i < strlen(input); i++) {
    char current = input[i];
    if (!reading_str && current == ' ') {
      continue;
    }
    str_append(processing_input, current);

    token_t token = token_identify(processing_input);

    if (reading_str) {
      if (token == TOKEN_QUOTE || token == TOKEN_DOUBLEQUOTE) {
        int start_pos = (*last_token_ref)->start_position + 1;
        int end_pos = i - 1;

        parsed_token_t *pt = malloc(sizeof(parsed_token_t));
        parsed_token_init(pt);
        pt->token = TOKEN_STRING;
        pt->start_position = start_pos;
        pt->end_position = end_pos;

        memcpy(pt->value, input + start_pos, end_pos);
        size_t value_len = (end_pos - start_pos) + 1;
        pt->value[value_len] = '\0';
        queue_enqueue(tokens_q, pt);

        parsed_token_t *pt2 = malloc(sizeof(parsed_token_t));
        parsed_token_init(pt2);
        pt2->token = token;
        pt2->start_position = i;
        pt2->end_position = i;

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
        parsed_token_t *pt = malloc(sizeof(parsed_token_t));
        parsed_token_init(pt);
        pt->token = token;
        pt->start_position = i;
        pt->end_position = i;

        strcpy(pt->value, processing_input);
        queue_enqueue(tokens_q, pt);
        last_token_ref = &pt;
        reading_str = true;
        processing_input[0] = '\0';
      } else {
        int start_pos = i - (strlen(processing_input) - 1);
        parsed_token_t *pt = malloc(sizeof(parsed_token_t));
        parsed_token_init(pt);
        pt->token = token;
        pt->start_position = start_pos;
        pt->end_position = i;

        strcpy(pt->value, processing_input);
        queue_enqueue(tokens_q, pt);
        processing_input[0] = '\0';
      }
    }
  }

  return tokens_q;
}
