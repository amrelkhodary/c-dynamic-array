/**
 * @file cdyar_structures.h
 * @brief Basic data structures and type definitions used throughout cdyar
 * 
 * This file defines fundamental types used across the cdyar library,
 * including boolean and flag types. It serves as a common dependency
 * for other header files.
 */

#ifndef H_CDYAR_STRUCTURES
    #define H_CDYAR_STRUCTURES
    
    //#include "./cdyar_darray.h" //caused a circular dependency error so it had to commented out
                                  //initially it was added to make the darray type available
                                  //will just declare the type here in its place
    
    /**
     * @brief Forward declaration of cdyar_darray structure
     * 
     * This forward declaration breaks circular dependencies between headers.
     * The full definition is in cdyar_darray.h
     */
    struct cdyar_darray;
    
    #include "./cdyar_error.h"
    
    /**
     * @enum cdyar_bool
     * @brief Simple boolean type for C
     * 
     * Provides a boolean type for use in cdyar functions before C99's
     * stdbool.h or when you prefer a custom boolean type.
     */
    typedef enum cdyar_bool {
        cdyar_false,  /**< Boolean false value (0) */
        cdyar_true    /**< Boolean true value (1) */
    } cdyar_bool;
    
    /**
     * @typedef cdyar_flag
     * @brief Type for binary flags and bit fields
     * 
     * Used to store combinations of binary flags that control various
     * aspects of dynamic array behavior. Flags can be combined using
     * bitwise OR operations.
     * 
     * @code
     * cdyar_flag flags = CDYAR_ARR_AUTO_RESIZE | OTHER_FLAG;
     * @endcode
     */
    typedef unsigned int cdyar_flag;
    
#endif