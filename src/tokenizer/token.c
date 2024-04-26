#include <tokenizer/token.h>
#include <stdlib.h>

Token *CreateToken(Token *cur, TokenKind kind, int val) {
  Token *token = malloc(sizeof(Token));
  cur->next = token;
  token->kind = kind;
  token->val = val;
  return token;
}