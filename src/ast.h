#include "tokens.h"

#define AST_CHILDREN_CAPACITY 128

struct ast_node {
  struct ast_node *parent;
  parsed_token_t *value;
  int children_size;
  int children_capacity;
  struct ast_node *children[];
};

typedef struct ast_node ast_node_t;

ast_node_t *ast_alloc();
ast_node_t *ast_get_root(ast_node_t *node);
void ast_append_children(ast_node_t *parent, ast_node_t *children);
ast_node_t *ast_append_children_value(ast_node_t *parent, parsed_token_t *children_value);
