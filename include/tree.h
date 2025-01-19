#ifndef TREE_H_
#define TREE_H_

#include "global_consts.h"

enum TreeElemType
{
    CONST,
    OP,
    VAR_ID,
    FUNC_ID,
};

union TreeElemUnion
{
    double value_const;
    OPType value_op;
    int    value_id;
};

#endif
