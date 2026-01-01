/**
 * @file cdyar_darray.h
 * @brief Dynamic array implementation with automatic resizing and type safety
 *
 * This file provides the core dynamic array functionality including creation,
 * destruction, element access, and automatic memory management.
 */

#ifndef H_CDYAR_DARRAY
#define H_CDYAR_DARRAY

/** @brief Default resize policy (NULL uses internal default behavior) */
#define CDYAR_DEFAULT_RESIZE_POLICY NULL

/** @brief Number of binary flags available for dynamic arrays */
#define CDYAR_DARRAY_FLAG_COUNT 2

#include "./cdyar_arithmetic.h" //for check_sizet_overflow called in cdyar_default_resize_policy
#include "./cdyar_error.h" //to be able to use cdyar_returncode type + to access error return codes
#include "./cdyar_structures.h" //for cdyar_flag
#include "./cdyar_types.h"
#include <math.h>   //for internal function
#include <stdlib.h> //to be able to use size_t

/**
 * @enum cdyar_darray_binflags
 * @brief Binary flags that control dynamic array behavior
 *
 * These flags can be combined using bitwise OR to enable multiple features.
 */
enum cdyar_darray_binflags {
  /** Automatically resize the array when accessing out-of-bounds indices */
  CDYAR_ARR_AUTO_RESIZE = 0b1,
};

/**
 * @typedef cdyar_resizepolicy
 * @brief Function pointer type for custom resize policy implementations
 *
 * Resize policies determine how the array's capacity changes when it needs
 * to grow. Custom policies can implement different growth strategies
 * (e.g., doubling, linear growth, etc.).
 *
 * @param arr Pointer to the dynamic array to resize
 * @param code Pointer to return code for error reporting
 */
typedef void (*cdyar_resizepolicy)(struct cdyar_darray *arr,
                                   cdyar_returncode *code);

/**
 * @struct cdyar_darray
 * @brief Dynamic array structure with automatic memory management
 *
 * This structure represents a dynamically-sized array that can grow
 * automatically and works with any data type through type handlers.
 */
typedef struct cdyar_darray {
  void *elements;              /**< Pointer to the array's data buffer */
  size_t length;               /**< Number of elements currently in the array */
  size_t capacity;             /**< Maximum number of elements the array can hold */
  size_t typesize;             /**< Size in bytes of each element */
  cdyar_flag flags;            /**< Binary flags controlling array behavior */
  cdyar_resizepolicy policy;   /**< Function pointer to resize policy */
  cdyar_typehandler handler;   /**< Function pointer to type handler */
  cdyar_returncode *code;      /**< Pointer to return code for error tracking */
} cdyar_darray;

/**
 * @brief Creates a new dynamic array
 *
 * Allocates and initializes a new dynamic array with the specified parameters.
 * The array must be destroyed with cdyar_darr() when no longer needed.
 *
 * @param typesize Size in bytes of each element
 * @param capacity Initial capacity (number of elements to allocate space for)
 * @param policy Resize policy function, or CDYAR_DEFAULT_RESIZE_POLICY for default
 * @param handler Type handler function for copying elements
 * @param flags Binary flags controlling array behavior (see cdyar_darray_binflags)
 * @param outptr Pointer to cdyar_darray structure to initialize
 * @return CDYAR_SUCCESSFUL on success, error code otherwise
 */
cdyar_returncode cdyar_narr(const size_t typesize, const size_t capacity,
                            const cdyar_resizepolicy policy,
                            const cdyar_typehandler handler,
                            const cdyar_flag flags, cdyar_darray *outptr);

/**
 * @brief Destroys a dynamic array and frees its memory
 *
 * Deallocates the array's internal buffer and resets all fields.
 * After calling this function, the array should not be used unless
 * reinitialized with cdyar_narr().
 *
 * @param arr Pointer to the dynamic array to destroy
 * @return CDYAR_SUCCESSFUL on success, error code otherwise
 */
cdyar_returncode cdyar_darr(cdyar_darray *arr);

/**
 * @brief Sets an element at the specified index
 *
 * Copies the value pointed to by valueptr into the array at the given index.
 * If CDYAR_ARR_AUTO_RESIZE flag is set and index is out of bounds, the array
 * will automatically resize to accommodate the new element.
 *
 * @param arr Pointer to the dynamic array
 * @param index Index where the element should be stored
 * @param valueptr Pointer to the value to copy into the array
 * @return CDYAR_SUCCESSFUL on success, CDYAR_ARR_OUT_OF_BOUNDS if index is
 *         invalid and auto-resize is disabled, or other error code
 */
cdyar_returncode
cdyar_set(cdyar_darray *arr, const size_t index,
          void *valueptr);

cdyar_returncode
cdyar_rm(cdyar_darray* arr, const size_t index);

/**
 * @brief Gets an element at the specified index
 *
 * Copies the element at the given index into the memory pointed to by outptr.
 * Performs bounds checking to ensure the index is valid.
 *
 * @param arr Pointer to the dynamic array
 * @param index Index of the element to retrieve
 * @param outptr Pointer to memory where the element will be copied
 * @return CDYAR_SUCCESSFUL on success, CDYAR_ARR_OUT_OF_BOUNDS if index is
 *         out of bounds, or other error code
 */
cdyar_returncode cdyar_get(const cdyar_darray *arr, const size_t index,
                           void *outptr);

/**
 * @brief Sets the flags for a dynamic array
 *
 * Updates the behavior flags of the array. Flags can be combined using
 * bitwise OR to enable multiple features simultaneously.
 *
 * @param arr Pointer to the dynamic array
 * @param flags New flags value (see cdyar_darray_binflags)
 * @return CDYAR_SUCCESSFUL on success, error code otherwise
 */
cdyar_returncode cdyar_setflags(cdyar_darray *arr, const cdyar_flag flags);

/**
 * @brief Sets the resize policy for a dynamic array
 *
 * Changes the function used to determine how the array grows when it needs
 * more capacity. Pass CDYAR_DEFAULT_RESIZE_POLICY to use the default policy.
 *
 * @param arr Pointer to the dynamic array
 * @param policy New resize policy function pointer
 * @return CDYAR_SUCCESSFUL on success, error code otherwise
 */
cdyar_returncode cdyar_setpolicy(cdyar_darray *arr,
                                 const cdyar_resizepolicy policy);
#endif
