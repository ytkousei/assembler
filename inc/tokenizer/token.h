#ifndef _TOKEN_H
#define _TOKEN_H

typedef enum _TokenKind {
  TK_NUM,
  TK_IDENT,
  TK_RESERVED,
  TK_EOF,
} TokenKind;

typedef struct _Token Token;

struct _Token {
  Token *next;
  TokenKind kind;
  char *str;
  int val; // Value or length
};

Token *CreateToken(Token *before_token, TokenKind kind, int val);

#endif
