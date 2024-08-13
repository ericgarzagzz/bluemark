#include "parser.h"

ASTNode *parser_parse(Queue *tokens_q) {
  ASTNode *root_node = ast_alloc();

  while (!queue_is_empty(tokens_q)) {
    ParsedToken *token = queue_peek(tokens_q);
    ast_append_children_value(root_node, token);
    queue_dequeue(tokens_q);
  }

  return root_node;
}
