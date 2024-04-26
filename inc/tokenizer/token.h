typedef enum _TokenKind {
  TK_NUM,
  TK_IDENT,
  TK_RESERVED,
} TokenKind;

typedef struct _Token Token;

struct _Token {
  Token *next;
  TokenKind kind;
  char *str;
  int val; // Value or length
};

Token *CreateToken(Token *before_token, TokenKind kind, int val);
