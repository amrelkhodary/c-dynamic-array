#include "../headers/cdyar_arithmetic.h"
#include <stdarg.h>
#include <stdint.h>

void check_sizet_overflow(const size_t count, cdyar_returncode* code, ...) {
    //check code is not null
    CDYAR_CHECK_CODE(code);

    //check that count doesn't equal zero
    if(count == 0) {
        *code=CDYAR_INVALID_INPUT;
        return;
    }

    //macros required for variadic func to work
    va_list args;
    va_start(args, code);

    //keep multiplying until overflow is found
    size_t temp_product = 1;
    size_t left = count;
    size_t next;
    while(left != 0) {
       //get the next number to multiply, if it is zero, return (because there would be no overflow)
       next = va_arg(args, size_t);
       if(next == 0) {
          va_end(args);
          *code=CDYAR_SUCCESSFUL;
          return;
       }

       //check for overflow
       if(temp_product > (SIZE_MAX / next) ) {
          va_end(args);
          *code=CDYAR_SIZE_T_OVERFLOW;
          return;
       }

       //update loop variables
       temp_product *= next;
       left--;
    }

    //va_end is a required macro
    //indicate success
    va_end(args);
    *code=CDYAR_SUCCESSFUL;
}
