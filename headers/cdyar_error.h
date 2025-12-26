/**
 * @file cdyar_error.h
 * @brief Error handling and reporting system for cdyar
 * 
 * This file defines error codes, error checking macros, and functions
 * for error reporting and diagnostics.
 */

#ifndef H_CDYAR_ERROR
    #define H_CDYAR_ERROR
    
    /** @brief Total number of error codes defined in the library */
    #define CDYAR_ERR_CODE_COUNT 13
    
    #include <stdio.h> //for fprintf in CDYAR_CHECK_CODE
    #include <stdlib.h>
    
    /** @brief Forward declaration of cdyar_darray for cdyar_status() */
    typedef struct cdyar_darray cdyar_darray;
    
    /**
     * @brief Macro to validate error code pointer is not NULL
     * 
     * This macro checks if the error code pointer is NULL before attempting
     * to use it. If NULL, it prints an error message and aborts the program.
     * Use this at the beginning of functions that accept error code pointers.
     * 
     * @param code Pointer to error code to validate
     */
    #define CDYAR_CHECK_CODE(code) \
        do { \
            if (!(code)) { \
                fprintf(stderr, "cdyar: FATAL: NULL error code pointer passed to %s\n", __func__); \
                abort(); \
            } \
        } while(0)
    
    /**
     * @typedef cdyar_returncode
     * @brief Type for function return codes and error status
     * 
     * All cdyar functions that can fail return a value of this type.
     * Check against the cdyar_errors enum to determine what happened.
     */
    typedef unsigned int cdyar_returncode;
    
    /**
     * @enum cdyar_errors
     * @brief Enumeration of all possible error codes
     * 
     * These error codes are returned by cdyar functions to indicate
     * the result of operations. CDYAR_SUCCESSFUL indicates success.
     */
    enum cdyar_errors {
        CDYAR_SUCCESSFUL,                    /**< Operation completed successfully */
        CDYAR_FAILED,                        /**< Generic failure (use only when necessary) */
        CDYAR_MEMORY_ERROR,                  /**< Memory allocation or deallocation failed */
        CDYAR_INVALID_INPUT,                 /**< Invalid input parameter provided */
        CDYAR_ARR_OUT_OF_BOUNDS,            /**< Array index out of bounds */
        CDYAR_SIZE_T_OVERFLOW,              /**< size_t arithmetic overflow detected */
        CDYAR_UINT_OVERFLOW,                /**< Unsigned integer overflow detected */
        CDYAR_DYNAMIC_ARR_DOES_NOT_EXIST,   /**< Array pointer is NULL or uninitialized */
        CDYAR_CORRUPTED_DYNAMIC_ARR,        /**< Array structure is corrupted or invalid */
        CDYAR_ARITHMETIC_NOT_A_NUMBER,      /**< Arithmetic operation resulted in NaN */
        CDYAR_ARITHMETIC_NEGATIVE_EXPONENT, /**< Negative exponent not supported */
        CDYAR_INVALID_DARR_DECLARATION,     /**< Invalid dynamic array declaration */
    };
    
    /**
     * @brief Array of human-readable error messages
     * 
     * This array contains descriptive error messages corresponding to each
     * error code in cdyar_errors. Index matches the error code value.
     */
    extern const char* CDYAR_ERR_MESSAGES[CDYAR_ERR_CODE_COUNT];
    
    /**
     * @brief Gets the error message string for an error code
     * 
     * Returns a human-readable string describing the error. The returned
     * string is statically allocated and should not be freed.
     * 
     * @param code Pointer to the error code
     * @return Pointer to error message string, or NULL if code is invalid
     */
    const char* cdyar_geterrmsg(cdyar_returncode* code);
    
    /**
     * @brief Prints an error message to a file stream
     * 
     * Writes a formatted error message to the specified output stream
     * (typically stderr or a log file).
     * 
     * @param code Pointer to the error code to print
     * @param destination File stream where the message will be written
     * @return CDYAR_SUCCESSFUL on success, error code on failure
     */
    cdyar_returncode cdyar_printerrmsg(cdyar_returncode* code, FILE* destination);
    
    /**
     * @brief Prints the complete status of a dynamic array
     * 
     * Outputs diagnostic information about the array including its length,
     * capacity, type size, flags, and current error state. Useful for
     * debugging and monitoring array state.
     * 
     * @param arr Pointer to the dynamic array
     * @param destination File stream where the status will be written
     * @return CDYAR_SUCCESSFUL on success, error code on failure
     */
    cdyar_returncode cdyar_printstatus(cdyar_darray* arr, FILE* destination);
#endif