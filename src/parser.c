#include "parser.h"
#include "queue.h"
#include <stdlib.h>

ast_node_t *parser_parse(queue_t *tokens_q) {
  ast_node_t *root_node = malloc(sizeof(ast_node_t) + sizeof(ast_node_t *) * AST_CHILDREN_CAPACITY);
  ast_init(root_node);

  while (!queue_is_empty(tokens_q)) {
    parsed_token_t *token = queue_peek(tokens_q);
    ast_append_children_value(root_node, token);
    queue_dequeue(tokens_q);
  }

  return root_node;
}
