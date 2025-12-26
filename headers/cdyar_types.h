/**
 * @file cdyar_types.h
 * @brief Type handling system for generic type operations in cdyar
 * 
 * This file defines the type handling mechanism that allows cdyar to work
 * with arbitrary data types through void pointers and generic operations.
 */

#ifndef H_CDYAR_TYPES
#define H_CDYAR_TYPES
#include "./cdyar_structures.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h> //for memcpy

/**
 * @enum cdyar_directions
 * @brief Specifies the direction of assignment in type handler operations
 * 
 * Used by type handler functions to determine which pointer should be
 * assigned to which during copy operations.
 */
enum cdyar_directions {
  CDYAR_DIRECTION_ASSIGN_LEFT_TO_RIGHT,  /**< Assign left pointer value to right pointer */
  CDYAR_DIRECTION_ASSIGN_RIGHT_TO_LEFT,  /**< Assign right pointer value to left pointer */
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

/**
 * @typedef cdyar_typehandler
 * @brief Function pointer type for handling generic type operations
 * 
 * Type handler functions are responsible for copying data between two
 * void pointers based on the specified direction and size. This allows
 * the dynamic array to work with any data type.
 * 
 * @param left_voidptr Pointer to the left operand
 * @param right_voidptr Pointer to the right operand
 * @param direction Direction of assignment (left-to-right or right-to-left)
 * @param size Size in bytes of the data type being handled
 * @param code Pointer to return code for error reporting
 */
typedef void (*cdyar_typehandler)(void *left_voidptr, void *right_voidptr,
                                  cdyar_flag direction, size_t size, cdyar_returncode *code);

/**
 * @brief Generic type handler implementation using memcpy
 * 
 * This is the default type handler that works with any data type by
 * performing byte-wise copying using memcpy. It replaces the previous
 * macro-based approach with type-specific handlers.
 * 
 * @param left_ptr Pointer to the left operand
 * @param right_ptr Pointer to the right operand
 * @param direction Direction of the assignment operation
 * @param size Size in bytes of the data to copy
 * @param code Pointer to return code (set to CDYAR_SUCCESSFUL on success,
 *             CDYAR_INVALID_INPUT if pointers are NULL or direction is invalid)
 */
void cdyar_generic_typehandler(void *left_ptr, void *right_ptr,
                               cdyar_flag direction, size_t size,
                               cdyar_returncode *code);
#endif