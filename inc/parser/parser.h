#ifndef _PARSER_H
#define _PARSER_H

#include <parser/node.h>
#include <tokenizer/token.h>

extern char *bin_code;

Node *Label(Node *cur);
Node *Instr(Node *cur);
Node *Parse(Token *token);

#endif
