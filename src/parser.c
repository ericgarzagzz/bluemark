#include "parser.h"
#include "queue.h"

ast_node_t *parser_parse(queue_t *tokens_q) {
  ast_node_t *root_node = ast_alloc();

  while (!queue_is_empty(tokens_q)) {
    parsed_token_t *token = queue_peek(tokens_q);
    ast_append_children_value(root_node, token);
    queue_dequeue(tokens_q);
  }

  return root_node;
}
