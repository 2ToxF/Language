#ifndef GLOBAL_CONSTS_H_
#define GLOBAL_CONSTS_H_

enum CodeError
{
    NO_ERR,

    FILE_NOT_OPENED_ERR,
    FILLING_FILE_STAT_ERR,
    WRONG_INPUT_BUFSIZE_ERR,

    NO_MEMORY_FOR_TOKENS_ERR,
};

const char        END_OF_CODE_STR = '?';
const char        END_OF_OP_STR = '~';
const char        FUNC_SPLIT_STR = '@';

const char        CLOSE_ANGLE_BRACKET_STR = '>';
const char        OPEN_ANGLE_BRACKET_STR = '<';

const char        CLOSE_ROUND_BRACKET_STR = ')';
const char        OPEN_ROUND_BRACKET_STR = '(';

const char        CLOSE_IF_WHILE_BODY_STR = '\\';
const char        OPEN_IF_WHILE_BODY_STR = '/';

const char* const FUNC_DEF_STR = "КАЙФОЛОМ";
const char* const VAR_DEF_STR = "РАБОТЯГА";

const char* const IF_OP_STR = "ЧЕКНИ";
const char* const WHILE_OP_STR = "ПРОБЕГИСЬ";

const char        ADD_STR = '+';
const char        SUB_STR = '-';
const char        DIV_STR = '\\';
const char        MUL_STR = '*';
const char        POW_STR = '^';

const char* const INPUT_OP_STR = "ПРОЧИТАЙ_ПЖ";
const char* const OUTPUT_OP_STR = "НАПЕЧАТАЙ_ПЖ";

enum OPType // TODO: подумать над разделением на виды операций
{
    END_OF_CODE,
    END_OF_OP,
    FUNC_SPLIT,

    CLOSE_ANGLE_BRACKET,
    OPEN_ANGLE_BRACKET,

    CLOSE_ROUND_BRACKET,
    OPEN_ROUND_BRACKET,

    CLOSE_IF_WHILE_BODY,
    OPEN_IF_WHILE_BODY,

    FUNC_DEF,
    VAR_DEF,

    IF_OP,
    WHILE_OP,

    ADD,
    SUB,
    DIV,
    MUL,
    POW,

    INPUT_OP,
    OUTPUT_OP,
};

#endif
