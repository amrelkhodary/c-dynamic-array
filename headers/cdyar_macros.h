/**
 * @file cdyar_macros.h
 * @brief Convenience macros for simplified dynamic array usage
 * 
 * This file provides quality-of-life macros that simplify the creation
 * and destruction of dynamic arrays with sensible defaults.
 */

#ifndef H_CDYAR_MACROS
#define H_CDYAR_MACROS

/**
 * @brief Creates a new dynamic array on the stack with default settings
 * 
 * This macro simplifies array creation by using default settings:
 * - Default resize policy
 * - Generic type handler
 * - Auto-resize enabled
 * 
 * @param name Variable name for the array
 * @param type Data type of elements (e.g., int, double, struct MyStruct)
 * @param capacity Initial capacity of the array
 * 
 * @code
 * NEW_CDYAR(my_array, int, 100);
 * // my_array is now ready to use
 * @endcode
 */
#define NEW_CDYAR(name, type, capacity)                                        \
  cdyar_darray name;                                                           \
  cdyar_narr(sizeof(type), capacity, CDYAR_DEFAULT_RESIZE_POLICY,              \
             cdyar_generic_typehandler, CDYAR_ARR_AUTO_RESIZE, &name);

/**
 * @brief Creates a new dynamic array on the heap with default settings
 * 
 * This macro allocates a dynamic array on the heap, which is useful when:
 * - The array needs to outlive the current scope
 * - The array is very large
 * - You want to pass ownership of the array to another function
 * 
 * Remember to free both the array contents (with DELETE_CDYAR_ONHEAP) and
 * the structure itself when done.
 * 
 * @param name Pointer variable name for the array
 * @param type Data type of elements (e.g., int, double, struct MyStruct)
 * @param capacity Initial capacity of the array
 * 
 * @code
 * NEW_CDYAR_ONHEAP(my_array, int, 100);
 * // my_array is a pointer to cdyar_darray
 * DELETE_CDYAR_ONHEAP(my_array);
 * @endcode
 */
#define NEW_CDYAR_ONHEAP(name, type, capacity)                                 \
  cdyar_darray *name = malloc(sizeof(cdyar_darray));                           \
  cdyar_narr(sizeof(type), capacity, CDYAR_DEFAULT_RESIZE_POLICY,              \
             cdyar_generic_typehandler, CDYAR_ARR_AUTO_RESIZE, name);

/**
 * @brief Destroys a stack-allocated dynamic array
 * 
 * Frees the internal buffer of the array. Use this for arrays created
 * with NEW_CDYAR.
 * 
 * @param name Pointer to the array to destroy
 * 
 * @code
 * NEW_CDYAR(my_array, int, 100);
 * // ... use the array ...
 * DELETE_CDYAR(&my_array);
 * @endcode
 */
#define DELETE_CDYAR(name) cdyar_darr(name)

/**
 * @brief Destroys a heap-allocated dynamic array
 * 
 * Frees both the internal buffer and the array structure itself.
 * Use this for arrays created with NEW_CDYAR_ONHEAP.
 * 
 * @param name Pointer to the array to destroy
 * 
 * @code
 * NEW_CDYAR_ONHEAP(my_array, int, 100);
 * // ... use the array ...
 * DELETE_CDYAR_ONHEAP(my_array);
 * @endcode
 */
#define DELETE_CDYAR_ONHEAP(name) cdyar_darr(name); free(name)

#endif