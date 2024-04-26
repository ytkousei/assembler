#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include <tokenizer/tokenizer.h>

Token *Tokenize(char *p) {
  Token token;
  token.next = 0;
  Token *cur = &token;
  while (*p) {
    if (isspace(*p)) {
      p++;
      continue;
    }

    switch (*p) {
      case ',':
      case ':':
        cur = CreateToken(cur, TK_RESERVED, *p);
        p++;
        continue;
    }

    if (isdigit(*p)) {
      cur = CreateToken(cur, TK_NUM, strtol(p, &p, 10));
      continue;
    }

    if (isalpha(*p)) {
      int len = 1;
      while(isalpha(p[len]) || isdigit(p[len])) {
        len++;
      }

      char *str = malloc(len + 1);

      strncpy(str, p, len);
      cur = CreateToken(cur, TK_IDENT, len);
      cur->str = str;

      p+=len;
      continue;
    }
  }

  return token.next;
}
