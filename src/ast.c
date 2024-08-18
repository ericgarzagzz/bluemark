#include "ast.h"
#include <stdlib.h>

ast_node_t *ast_realloc_children(ast_node_t *node);

ast_node_t *ast_alloc() {
  ast_node_t *node = malloc(sizeof(ast_node_t) + sizeof(ast_node_t*) * AST_CHILDREN_CAPACITY);
  node->parent = NULL;
  node->value = NULL;
  node->children_size = 0;
  node->children_capacity = AST_CHILDREN_CAPACITY;

  return node;
}

ast_node_t *ast_get_root(ast_node_t *node) {
  if (node->parent == NULL) {
    return node;
  }

  return ast_get_root(node->parent);
}

void ast_append_children(ast_node_t *parent, ast_node_t *children) {

  if (parent->children_size == parent->children_capacity) {
    parent = ast_realloc_children(parent);
  }

  children->parent = parent;
  parent->children[parent->children_size] = children;
  parent->children_size++;
}

ast_node_t *ast_append_children_value(ast_node_t *parent, parsed_token_t* children_value) {
  ast_node_t *children = ast_alloc();
  children->value = children_value;
  ast_append_children(parent, children);

  return children;
}

ast_node_t *ast_realloc_children(ast_node_t *node) {
  int new_capacity = node->children_capacity * 2;

  ast_node_t *new_node = realloc(node, sizeof(ast_node_t) + sizeof(ast_node_t*) * new_capacity);
  new_node->children_capacity = new_capacity;

  // Check if realloc() changed the block to other location
  // TODO: Test this code by making realloc() change the memory block location
  if (new_node != node) {
    // Search and replace parent's children reference
    ast_node_t *parent = new_node->parent;
    for (int i = 0; i < parent->children_size; i++) {
      if (parent->children[i] == node) {
        parent->children[i] = new_node;
      }
    }

    // Replace children's parent reference
    for (int i = 0; i < new_node->children_size; i++) {
      new_node->children[i]->parent = new_node;
    }
  }

  return new_node;
}
