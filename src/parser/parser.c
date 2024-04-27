#include <stdio.h>
#include <parser/parser.h>
#include <utils/print.h>

Token *token;

Node *Label(Node *cur, Token *next) {
  next = next->next;
  if(next->kind == TK_RESERVED && (next->val == '\n' || next->val == ';')) {
    Node *node = CreateNode(cur, NK_LABEL, token->str);
    token = next->next;
    return node;
  } else {
    Error("Error: expected a '\\n' or ';'\n");
  }
}

Node *Instr(Node *cur) {
  Node *node = CreateNode(cur, NK_INSTR, token->str);
  Param param;

  Param *pcur;
  pcur->next = &param;
  node->param = &param;

  is_next = 1;

  while(token->next) {
    Token *next = token->next;
    if (next->kind == TK_RESERVED && (next->val == '\n' || next->val == ';')) {
      if(token->kind == TK_RESERVED && token->val == ',') Error("Error: expected a register name or number\n");
      token = next->next;
      break;
    }

    if (next->kind == TK_NUM) {
      pcur = CreateParam(pcur, PK_NUM, next->val);
      token = next;
      continue;
    }

    if(next->kind == TK_IDENT) {
      pcur = CreateParam(pcur, PK_REG, 0);
      pcur->str = next->str;
      token = next;
      continue;
    }

    if (next->kind == TK_RESERVED && next->val == ',') {
      if(is_next) Error("Error: expected a register name or number\n");
      is_next = 1;
      token = next;
      continue;
    }

    if(next->kind == TK_RESERVED) {
      Error("Error: not expected a %c\n", next->val);
    }
    if(next->kind == TK_EOF) {
      Error("Error: expected declaration or statement at end of input\n");
    }
  }

  if(is_next) {
    Error("test");
  }

  CreateParam(pcur, PK_EOF, 0);

  return node;
}

Node *Parse(Token *_token) {
  Node node;
  node.next = 0;
  Node *cur = &node;

  token = _token;

  while (token->next) {
    switch (token->kind) {
      case TK_IDENT:
        Token *next = token->next;
        if (next->kind == TK_RESERVED && next->val == ':') {
          cur = Label(cur, next);
          continue;
        }
        cur = Instr(cur);
        continue;
    }
    Error("error: \n");
  }

  return node.next;
}