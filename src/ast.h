#include "tokens.h"

#define AST_CHILDREN_CAPACITY 128

// NOTE: Should only be heap-allocated due to internal implementation (realloc is used).
typedef struct ast_node {
  struct ast_node *parent;
  parsed_token_t *value;
  int children_size;
  int children_capacity;
  struct ast_node *children[];
} ast_node_t;

void ast_init(ast_node_t *self);
ast_node_t *ast_get_root(ast_node_t *self);
void ast_append_children(ast_node_t *self, ast_node_t *children);
ast_node_t *ast_append_children_value(ast_node_t *self, parsed_token_t *value);
void ast_print(ast_node_t *node, int depth);
