#ifndef H_CDYAR
#define H_CDYAR

// a quality-of-life single header file that includes all other header files
// some of these inclusions are not neccessary because they are
// automatically included by other header files, but having them doesn't hurt
// and help with clarity.
#include "./cdyar_arithmetic.h"
#include "./cdyar_darray.h"
#include "./cdyar_error.h"
#include "./cdyar_structures.h"
#include "./cdyar_types.h"

// quality-of-life macros that make using cdyar easier
#define NEW_CDYAR(name, type, capacity)                                        \
  cdyar_darray name;                                                           \
  cdyar_narr(sizeof(type), capacity, CDYAR_DEFAULT_RESIZE_POLICY,              \
             cdyar_generic_typehandler, CDYAR_ARR_AUTO_RESIZE, &name);

#endif
