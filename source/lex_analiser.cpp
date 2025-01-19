#include <stdlib.h>

#include "lex_analiser.h"
#include "utils.h"

const int START_TOKENS_BUFFER_LEN   = 32;
const int TOKENS_BUFFER_RESIZE_COEF = 2;


CodeError LexicalAnalise(const char* const file_buffer, Token_t** p_tokens_buffer)
{
    Token_t* tokens_buffer = *p_tokens_buffer;

    int file_idx = 0, tokens_idx = 0;
    int tokens_buffer_len = START_TOKENS_BUFFER_LEN;

    tokens_buffer = (Token_t*) calloc(tokens_buffer_len, sizeof(Token_t));
    if (tokens_buffer == NULL)
        return NO_MEMORY_FOR_TOKENS_ERR;

    while (file_buffer[file_idx] != '\0')
    {
        if (tokens_idx >= tokens_buffer_len)
        {
            tokens_buffer_len *= TOKENS_BUFFER_RESIZE_COEF;
            tokens_buffer = (Token_t*) MyRecalloc(tokens_buffer, TOKENS_BUFFER_RESIZE_COEF, tokens_idx);

            if (tokens_buffer == NULL)
                return NO_MEMORY_FOR_TOKENS_ERR;
        }

        if ()
    }
}
