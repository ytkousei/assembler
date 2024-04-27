#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <utils/print.h>
#include <tokenizer/tokenizer.h>
#include <errno.h>
#include <stdio.h>

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
        Error("%c is not a hexadecimal number\n", *p);
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

      // char *str = malloc(sizeof(char) * (len + 1));
      char *str = calloc(len + 1, sizeof(char));
      strncpy(str, p, len);
      cur = CreateToken(cur, TK_IDENT, len);
      cur->str = str;

      p+=len;
      continue;
    }

    Error("%c\n", *p);
  }

  cur = CreateToken(cur, TK_EOF, 0);

  return token.next;
}
