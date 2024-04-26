#include <stdio.h>
#include <parser/parser.h>
#include <utils.h>

Token *token;

Node *label() {
}

Node *Instr(Node *cur) {
  Node *node = CreateNode(cur, NK_INSTR, token->str);
  token = token->next;
  return node;
}

Node *Parse(Token *_token) {
  token = _token;

  Node node;
  node.next = 0;
  Node *cur = &node;

  while (token) {
    switch (token->kind) {
      case TK_IDENT:
        // Token *ntoken = _token->next;
        // if (ntoken->kind == TK_RESERVED && ntoken->val == ':') {
        //   label(token);
        // }
        Instr(cur);
        continue;
    }
    Error("error");
  }
}
