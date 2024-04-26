#ifndef _PARSER_H
#define _PARSER_H

#include <parser/node.h>
#include <tokenizer/token.h>

Node *Instr();
Node *Parse(Token *token);

#endif
