#include <stdio.h>
#include <parser/parser.h>
#include <utils.h>

char *bin_code;
Token *token;

void Label() {
}

void Instr() {
  InstructionToBin(token->str);

  // Node *node = CreateNode(cur, NK_INSTR, token->str);
  if (token->next) {
    token = token->next;
    // node->instr = CreateInstruction(IT_RET);
    while(token->next) {
      Token *next = token->next;
      if (next->kind == TK_RESERVED && (next->val == '\n' || next->val == ';')) {
        break;
      }

      if (next->kind == TK_NUM || next->kind == TK_IDENT) {
      }

      token = next;
    }
  } else {
    // node->instr = CreateInstruction(IT_RET);
    token = token->next;
  }
  // return node;
}

void Parse(Token *_token) {
  token = _token;

  while (token) {
    switch (token->kind) {
      case TK_IDENT:
        Token *next = _token->next;
        if (next->kind == TK_RESERVED && next->val == ':') {
          Label();
        }
        Instr();
        continue;
    }
    Error("error");
  }
}
