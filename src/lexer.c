#include "lexer.h"
#include "utils.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

Queue *read_tokens(char *input) {
  Queue *tokens_q = malloc(sizeof(struct Queue));
  if (tokens_q == NULL) {
    perror("bluemark: ");
  }
  queue_init(tokens_q);

  queue_enqueue(tokens_q, HTML_TAG);
  queue_enqueue(tokens_q, BRACE_OPEN);
  queue_enqueue(tokens_q, BRACE_CLOSE);

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
