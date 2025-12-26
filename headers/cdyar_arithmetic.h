/**
 * @file cdyar_arithmetic.h
 * @brief Safe arithmetic operations with overflow detection
 * 
 * This file provides utility functions for performing arithmetic operations
 * with automatic overflow detection. These are used internally by cdyar to
 * ensure memory calculations don't overflow.
 */

#ifndef H_CDYAR_ARITHMETIC
#define H_CDYAR_ARITHMETIC

#include "./cdyar_error.h"
#include "./cdyar_structures.h"
#include <limits.h> //for INT_MAX
#include <stdarg.h> //for variadic check_overflow function
#include <stdint.h> //for SIZE_MAX
#include <stdlib.h> //for size_t

/**
 * @brief Checks for overflow when multiplying size_t values
 * 
 * This variadic function multiplies multiple size_t values and detects
 * if the result would overflow. This is critical for safe memory allocation
 * calculations where overflow could lead to allocating too little memory.
 * 
 * @param count Number of size_t values to multiply
 * @param code Pointer to return code (set to CDYAR_SIZE_T_OVERFLOW on overflow,
 *             CDYAR_SUCCESSFUL otherwise)
 * @param ... Variable number of size_t values to multiply
 * 
 * @code
 * cdyar_returncode code;
 * cdyar_check_sizet_overflow(3, &code, array_length, element_size, multiplier);
 * if (code == CDYAR_SIZE_T_OVERFLOW) {
 *     // Handle overflow
 * }
 * @endcode
 */
void cdyar_check_sizet_overflow(const size_t count, cdyar_returncode *code,
                                ...);

/**
 * @brief Checks for overflow when multiplying unsigned int values
 * 
 * Similar to cdyar_check_sizet_overflow but for unsigned int types.
 * Multiplies multiple unsigned int values and detects overflow.
 * 
 * @param count Number of unsigned int values to multiply
 * @param code Pointer to return code (set to CDYAR_UINT_OVERFLOW on overflow,
 *             CDYAR_SUCCESSFUL otherwise)
 * @param ... Variable number of unsigned int values to multiply
 * 
 * @code
 * cdyar_returncode code;
 * cdyar_check_uint_overflow(2, &code, base, factor);
 * if (code == CDYAR_UINT_OVERFLOW) {
 *     // Handle overflow
 * }
 * @endcode
 */
void cdyar_check_uint_overflow(const size_t count, cdyar_returncode *code, ...);

/**
 * @brief Computes unsigned integer exponentiation with overflow detection
 * 
 * Calculates base raised to the power of exponent (base^exponent) for
 * unsigned integers, with automatic detection of overflow conditions.
 * Does not support negative exponents.
 * 
 * @param base The base value
 * @param exponent The exponent (must be non-negative)
 * @param outptr Pointer to where the result will be stored
 * @param code Pointer to return code (set to CDYAR_SUCCESSFUL on success,
 *             CDYAR_UINT_OVERFLOW on overflow,
 *             CDYAR_ARITHMETIC_NEGATIVE_EXPONENT if exponent is negative,
 *             CDYAR_ARITHMETIC_NOT_A_NUMBER if result is not a number)
 * 
 * @code
 * unsigned int result;
 * cdyar_returncode code;
 * cdyar_uintpow(2, 10, &result, &code);
 * if (code == CDYAR_SUCCESSFUL) {
 *     // result contains 1024
 * }
 * @endcode
 */
void cdyar_uintpow(const unsigned int base, const unsigned int exponent,
                   unsigned int *outptr, cdyar_returncode *code);

#endif