/**
 * @file cdyar.h
 * @brief Main header file for the cdyar (C Dynamic Array) library
 * 
 * This is a convenience header that includes all other cdyar headers.
 * Include this single file to access all cdyar functionality.
 * 
 * @mainpage cdyar - C Dynamic Array Library
 * 
 * @section intro_sec Introduction
 * 
 * cdyar is a generic dynamic array library for C that provides:
 * - Type-safe dynamic arrays that work with any data type
 * - Automatic memory management and resizing
 * - Configurable resize policies
 * - Comprehensive error handling
 * - Quality-of-life macros for common operations
 * 
 * @section usage_sec Basic Usage
 * 
 * @code
 * #include "cdyar.h"
 * 
 * // Create a dynamic array of integers with capacity 10
 * NEW_CDYAR(my_array, int, 10);
 * 
 * // Set and get values
 * int value = 42;
 * cdyar_set(&my_array, 0, &value);
 * cdyar_get(&my_array, 0, &value);
 * 
 * // Clean up
 * DELETE_CDYAR(&my_array);
 * @endcode
 */

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

#endif