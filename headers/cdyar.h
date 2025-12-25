#ifndef H_CDYAR
#define H_CDYAR

// a quality-of-life single header file that includes all other header files
// some of these inclusions are not neccessary because they are
// automatically included by other header files, but having them doesn't hurt
// and helps with clarity.
#include "./cdyar_arithmetic.h"
#include "./cdyar_darray.h"
#include "./cdyar_error.h"
#include "./cdyar_structures.h"
#include "./cdyar_types.h"
#include "./cdyar_macros.h"

// quality-of-life macros that make using cdyar easier


#endif

/*
 * cdyar<type, size> arr
    #define cdyar create_arr() \
                  #define cdyar
   -->create_arr("<type, size> name");
 */
