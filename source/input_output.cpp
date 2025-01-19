#include "stdio.h"

#include "input_output.h"


CodeError MyFread(wchar_t** input_buffer, int* input_buffer_length, const char* input_file_name)
{
    CodeError code_err = NO_ERR;

    FILE* input_fptr = fopen(input_file_name, "r");
    if (input_fptr == NULL)
    {
        printf(RED "ERROR: can't open file \"%s\"" WHT "\n", input_file_name);
        return FILE_NOT_OPENED_ERR;
    }

    if ((code_err = Fsize(input_file_name, input_buffer_length)) != NO_ERR)
        return code_err;

    *input_buffer = (char*) calloc(*input_buffer_length, sizeof(char));
    long long unsigned int success_read_string_length = fread(*input_buffer, 1, *input_buffer_length - 1, input_fptr);
    if (success_read_string_length != (long long unsigned int) (*input_buffer_length - 1))
        return WRONG_INPUT_BUFSIZE_ERR;

    fclose(input_fptr); input_fptr = NULL;
    return code_err;
}


#define ERR_DESCR_(error)                                   \
    case (error):                                           \
        printf("\n\n" RED "CODE_ERROR: " #error WHT "\n");  \
        break

void PrintCodeError(CodeError code_error)
{
    switch(code_error)
    {
        case NO_ERR:
            printf("\n\n" GRN "Code was completed without errors" WHT "\n");
            break;

        ERR_DESCR_(FILE_NOT_OPENED_ERR);
        ERR_DESCR_(FILLING_FILE_STAT_ERR);
        ERR_DESCR_(WRONG_INPUT_BUFSIZE_ERR);

        ERR_DESCR_(NO_MEMORY_FOR_TOKENS_ERR);

        default:
            printf("\n\n" RED "CODE_ERROR: UNKNOWN_ERROR" WHT "\n");
            break;
    }
}

#undef ERR_DESCR_
