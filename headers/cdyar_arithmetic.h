#ifndef H_CDYAR_ARITHMETIC
    #define H_CDYAR_ARITHMETIC
    #include "./cdyar_structures.h"
    #include "./cdyar_error.h"
    #include <stdarg.h> //for variadic check_overflow function
    #include <stdlib.h> //for size_t

    void check_sizet_overflow(const size_t count, cdyar_returncode* code, ...);
#endif
