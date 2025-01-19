#ifndef LEX_ANALISER_H_
#define LEX_ANALISER_H_

#include "global_consts.h"

enum TokenType
{
    CONST,
    OP,
    ID,
};

struct IdStruct
{
    int begin_var_idx;
    int len_var;
};

union TokenElemUnion
{
    double   value_const;
    OPType   value_op;
    IdStruct value_id;
};

struct Token_t
{
    TokenType      type;
    TokenElemUnion value;
};

CodeError LexicalAnalise(const char* const file_buffer);

#endif
