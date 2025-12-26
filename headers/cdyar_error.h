#ifndef H_CDYAR_ERROR
    #define H_CDYAR_ERROR
    #define CDYAR_ERR_CODE_COUNT 13

    #include <stdio.h> //for fprintf in CDYAR_CHECK_CODE
    #include <stdlib.h>

    typedef struct cdyar_darray cdyar_darray; //declaration for cdyar_status()

    //checking code is not null
    #define CDYAR_CHECK_CODE(code) \
        do { \
            if (!(code)) { \
                fprintf(stderr, "cdyar: FATAL: NULL error code pointer passed to %s\n", __func__); \
                abort(); \
            } \
        } while(0)

    //simple returncode type
    typedef unsigned int cdyar_returncode;

    enum cdyar_errors {
        CDYAR_SUCCESSFUL,
        CDYAR_FAILED, //generic failed return code, use it only when abs. neccessary
        CDYAR_MEMORY_ERROR,
        CDYAR_INVALID_INPUT,
        CDYAR_ARR_OUT_OF_BOUNDS,
        CDYAR_SIZE_T_OVERFLOW,
        CDYAR_UINT_OVERFLOW,
        CDYAR_DYNAMIC_ARR_DOES_NOT_EXIST,
        CDYAR_CORRUPTED_DYNAMIC_ARR,
        CDYAR_ARITHMETIC_NOT_A_NUMBER,
        CDYAR_ARITHMETIC_NEGATIVE_EXPONENT,
        CDYAR_INVALID_DARR_DECLARATION,

    };

    //array that contains all the error messages the correspond to different error codes
    extern const char* CDYAR_ERR_MESSAGES[CDYAR_ERR_CODE_COUNT];

    //functions for printing errors
    const char* cdyar_geterrmsg(cdyar_returncode* code);
    cdyar_returncode cdyar_printerrmsg(cdyar_returncode* code, FILE* destination);
    cdyar_returncode cdyar_printstatus(cdyar_darray* arr, FILE* destination);
#endif
