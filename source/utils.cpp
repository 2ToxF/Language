#include <stdlib.h>
#include <sys/stat.h>

#include "utils.h"

const int UTF16_CORRECTION_COEF = 2;

CodeError Fsize(const char* file_name, int* input_buffer_length)
{
    struct stat input_file_stat = {};
    if (stat(file_name, &input_file_stat) != 0)
        return FILLING_FILE_STAT_ERR;

    *input_buffer_length = input_file_stat.st_size / UTF16_CORRECTION_COEF + 1;
    return NO_ERR;
}


void* MyRecalloc(void* mem_ptr, size_t new_size, size_t num_of_used_bytes)
{
    mem_ptr = realloc(mem_ptr, new_size);
    memset((char*) mem_ptr + num_of_used_bytes, 0, new_size - num_of_used_bytes);
    return mem_ptr;
}
