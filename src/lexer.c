#include "lexer.h"
#include "tokens.h"
#include "utils.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

Queue *lexer_parse(char *input) {
  int q_size = 512;
  Queue *tokens_q = malloc(sizeof(Queue) + q_size * sizeof(int));
  if (tokens_q == NULL) {
    perror("bluemark: ");
  }
  queue_init(tokens_q, q_size);

  // bool reading_str = false;
  //
  // char *token = strtok(input, " ");
  // while (token) {
  //   for (int i = 0; i < sizeof(Tokens) / sizeof(char *); i++) {
  //     if (strcmp(Tokens[i], token) == 0) {
  //       tokens[*count] = token;
  //       (*count)++;
  //       break;
  //     } else {
  //       if (strlen(token) > 1 && token[0] == '"') {
  //         char buff[strlen(token)];
  //         char *after_quote_str = token + sizeof(char);
  //         memcpy(buff, after_quote_str, strcspn(after_quote_str, "\""));
  //         printf("Buff: %s\n", buff);
  //         // TODO: Handle rest of the string
  //       }
  //       // TODO: Handle two tokens side by side.
  //     }
  //   }
  //   token = strtok(NULL, " ");
  // }

  return tokens_q;
}
