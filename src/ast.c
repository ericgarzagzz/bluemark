#include "ast.h"
#include <stdlib.h>

ASTNode *ast_realloc_children(ASTNode *node);

ASTNode *ast_alloc() {
  ASTNode *node = malloc(sizeof(ASTNode) + sizeof(ASTNode*) * AST_CHILDREN_CAPACITY);
  node->parent = NULL;
  node->value = NULL;
  node->children_size = 0;
  node->children_capacity = AST_CHILDREN_CAPACITY;

  return node;
}

ASTNode *ast_get_root(ASTNode *node) {
  if (node->parent == NULL) {
    return node;
  }

  return ast_get_root(node->parent);
}

void ast_append_children(ASTNode *parent, ASTNode *children) {

  if (parent->children_size == parent->children_capacity) {
    parent = ast_realloc_children(parent);
  }

  children->parent = parent;
  parent->children[parent->children_size] = children;
  parent->children_size++;
}

ASTNode *ast_append_children_value(ASTNode *parent, ParsedToken* children_value) {
  ASTNode *children = ast_alloc();
  children->value = children_value;
  ast_append_children(parent, children);

  return children;
}

ASTNode *ast_realloc_children(ASTNode *node) {
  int new_capacity = node->children_capacity * 2;

  ASTNode *new_node = realloc(node, sizeof(ASTNode) + sizeof(ASTNode*) * new_capacity);
  new_node->children_capacity = new_capacity;

  // Check if realloc() changed the block to other location
  // TODO: Test this code by making realloc() change the memory block location
  if (new_node != node) {
    // Search and replace parent's children reference
    ASTNode *parent = new_node->parent;
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
