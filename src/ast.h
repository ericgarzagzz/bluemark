#include "tokens.h"

#define AST_CHILDREN_CAPACITY 128

struct _ASTNode {
  struct _ASTNode *parent;
  ParsedToken *value;
  int children_size;
  int children_capacity;
  struct _ASTNode *children[];
};

typedef struct _ASTNode ASTNode;

ASTNode *ast_alloc();
ASTNode *ast_get_root(ASTNode *node);
void ast_append_children(ASTNode *parent, ASTNode *children);
ASTNode *ast_append_children_value(ASTNode *parent, ParsedToken* children_value);
