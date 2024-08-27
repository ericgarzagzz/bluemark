#include "parser.h"
#include "queue.h"
#include "tokens.h"
#include <stdlib.h>

ast_node_t *parser_parse(queue_t *tokens_q) {
  ast_node_t *root_node = malloc(sizeof(ast_node_t) + sizeof(ast_node_t *) * AST_CHILDREN_CAPACITY);
  ast_init(root_node);

  bool reading_children = false;

  ast_node_t *current_node = root_node;
  while (!queue_is_empty(tokens_q)) {
    parsed_token_t *token = queue_peek(tokens_q);

    if (token->token == TOKEN_BRACE_OPEN) {
      reading_children = true;
    } else if (token->token == TOKEN_BRACE_CLOSE) {
      reading_children = false;
      current_node = current_node->parent;
    } else if (reading_children) {
      current_node = ast_append_children_value(current_node, token);
    } else if (current_node->value == NULL){
      current_node->value = token;
    } else {
      current_node = current_node->parent;
      current_node = ast_append_children_value(current_node, token);
    }

    queue_dequeue(tokens_q);
  }

  return root_node;
}
