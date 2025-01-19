#ifndef UTILS_H_
#define UTILS_H_

#include "global_consts.h"

CodeError Fsize      (const char* file_name, int* input_buffer_length);
void*     MyRecalloc (void* mem_ptr, size_t new_size, size_t endof_used_mem);


#endif
