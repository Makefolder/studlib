#ifndef STUDERR_H
#define STUDERR_H

#ifdef LOG_ERRORS

#define print_error(msg) frpintf(stderr, "studlib: %s\n", msg)

#else

#define print_error(msg) fprintf(stderr, "")

#endif

// just an idea
/*typedef enum { SUCCESS, FAILURE } statuscode_t;*/

#endif
