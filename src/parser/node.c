#include <stdlib.h>
#include <parser/node.h>

Node *CreateNode(Node *cur, NodeKind kind, char *str) {
  Node *node = malloc(sizeof(Node));
  node->kind = kind;
  node->str = str;
  cur->next = node;
  return node;
}
