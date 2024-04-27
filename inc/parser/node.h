#ifndef _NODE_H
#define _NODE_H

#include <parser/instruction.h>

typedef enum _NodeKind {
  NK_LABEL,
  NK_INSTR,
} NodeKind;

typedef struct _Node Node;

struct _Node {
  NodeKind kind;
  Node *next;
  char *str;
  Param *param;
};

Node *CreateNode(Node *cur, NodeKind kind, char *str);

#endif
