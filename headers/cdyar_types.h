#ifndef H_CDYAR_TYPES
#define H_CDYAR_TYPES
#include "./cdyar_structures.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h> //for memcpy

// directions for cdyar_typehandler functions
enum cdyar_directions {
  CDYAR_DIRECTION_ASSIGN_LEFT_TO_RIGHT,
  CDYAR_DIRECTION_ASSIGN_RIGHT_TO_LEFT,
};

/*
REMOVED CODE
why -> replacd CDYAR_DEFINE_TYPE_HANDLER specific-type, typehandler function generating macro
    -> with a truly generic typehandler function relying on memcpy instead of explicit typecasts


// macro for creating typehandler functions
#define CDYAR_DEFINE_TYPE_HANDLER(type, suffix)                                \
  void cdyar_##suffix##_typehandler(void *left_ptr, void *right_ptr,           \
                                    cdyar_flag direction,                      \
                                    cdyar_returncode *code) {                  \
    CDYAR_CHECK_CODE(code);                                                    \
                                                                               \
    if (!left_ptr) {                                                           \
      *code = CDYAR_INVALID_INPUT;                                             \
      return;                                                                  \
    }                                                                          \
    if (!right_ptr) {                                                          \
      *code = CDYAR_INVALID_INPUT;                                             \
      return;                                                                  \
    }                                                                          \
                                                                               \
    if ((uintptr_t)left_ptr % _Alignof(type) != 0) {                           \
      *code = CDYAR_INVALID_INPUT;                                             \
      return;                                                                  \
    }                                                                          \
    if ((uintptr_t)right_ptr % _Alignof(type) != 0) {                          \
      *code = CDYAR_INVALID_INPUT;                                             \
      return;                                                                  \
    }                                                                          \
                                                                               \
    type *internal_leftptr = (type *)left_ptr;                                 \
    type *internal_rightptr = (type *)right_ptr;                               \
                                                                               \
    switch (direction) {                                                       \
    case CDYAR_DIRECTION_ASSIGN_LEFT_TO_RIGHT:                                 \
      *internal_rightptr = *internal_leftptr;                                  \
      break;                                                                   \
    case CDYAR_DIRECTION_ASSIGN_RIGHT_TO_LEFT:                                 \
      *internal_leftptr = *internal_rightptr;                                  \
      break;                                                                   \
    default:                                                                   \
      *code = CDYAR_INVALID_INPUT;                                             \
      return;                                                                  \
    }                                                                          \
                                                                               \
    *code = CDYAR_SUCCESSFUL;                                                  \
  }

 */



// typehandler function type
// casts both pointers to a specific type, assigns one to the other
// depending on direction passed
typedef void (*cdyar_typehandler)(void *left_voidptr, void *right_voidptr,
                                  cdyar_flag direction, size_t size, cdyar_returncode *code);

// generic typehandler
void cdyar_generic_typehandler(void *left_ptr, void *right_ptr,
                               cdyar_flag direction, size_t size,
                               cdyar_returncode *code);
#endif
