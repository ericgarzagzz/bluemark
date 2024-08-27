#include "ast.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ast_node_t *ast_realloc_children(ast_node_t *self);

void ast_init(ast_node_t *self) {
  memset(self, 0, sizeof(ast_node_t));
  self->parent = NULL;
  self->value = NULL;
  self->children_size = 0;
  self->children_capacity = AST_CHILDREN_CAPACITY;
}

ast_node_t *ast_get_root(ast_node_t *self) {
  if (self->parent == NULL) {
    return self;
  }

  return ast_get_root(self->parent);
}

void ast_append_children(ast_node_t *self, ast_node_t *children) {

  if (self->children_size == self->children_capacity) {
    self = ast_realloc_children(self);
  }

  children->parent = self;
  self->children[self->children_size] = children;
  self->children_size++;
}

ast_node_t *ast_append_children_value(ast_node_t *self, parsed_token_t* value) {
  ast_node_t *children = malloc(sizeof(ast_node_t) + sizeof(ast_node_t*) * AST_CHILDREN_CAPACITY);
  ast_init(children);

  children->value = value;
  ast_append_children(self, children);

  return children;
}

void ast_print(ast_node_t *node, int depth) {
  if (node == NULL) {
    return;
  }

  for (int i = 0; i < depth; i++) {
    printf("  ");
  }
  printf("%s\n", node->value->value);

  for (int i = 0; i < node->children_size; i++) {
    ast_print(node->children[i], depth + 1);
  }
}

ast_node_t *ast_realloc_children(ast_node_t *self) {
  int new_capacity = self->children_capacity * 2;

  ast_node_t *new_node = realloc(self, sizeof(ast_node_t) + sizeof(ast_node_t*) * new_capacity);
  new_node->children_capacity = new_capacity;

  // Check if realloc() changed the block to other location
  // TODO: Test this code by making realloc() change the memory block location
  if (new_node != self) {
    // Search and replace parent's children reference
    ast_node_t *parent = new_node->parent;
    for (int i = 0; i < parent->children_size; i++) {
      if (parent->children[i] == self) {
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
