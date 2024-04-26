#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <utils.h>
#include <tokenizer/tokenizer.h>
#include <errno.h>

Token *Tokenize(char *p) {
  Token token;
  token.next = 0;
  Token *cur = &token;
  while (*p) {
    switch (*p) {
      case ',':
      case ':':
      case ';':
      case '\n':
        cur = CreateToken(cur, TK_RESERVED, *p);
        p++;
        continue;
    }

    if (isspace(*p)) {
      p++;
      continue;
    }

    if (*p == '0' && *(p+1) == 'x') {
      p+=2;

      if(isxdigit(*p)) {
        int num = strtol(p, &p, 16);
        cur = CreateToken(cur, TK_NUM, num);
        continue;
      }else {
        Error("%c is not a hexadecimal number", *p);
      }
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

    Error("%c", *p);
  }

  return token.next;
}
