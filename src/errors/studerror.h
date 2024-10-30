#ifndef STUDERR_H
#define STUDERR_H

#include <stdio.h>

#ifdef LOG_ERRORS

#define print_error(msg) printf("studlib: %s\n", msg)

#else

#define print_error(msg) printf("")

#endif

// just an idea
/*typedef enum { SUCCESS, FAILURE } errcode_t;*/

#endif
