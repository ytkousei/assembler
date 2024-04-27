#ifndef _PARSER_H
#define _PARSER_H

#include <parser/node.h>
#include <tokenizer/token.h>

Node *Label(Node *cur, Token *next);
Node *Instr(Node *cur);
Node *Parse(Token *token);

#endif
