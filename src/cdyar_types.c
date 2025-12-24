#include "../headers/cdyar_types.h"

/*
REMOVED CODE
why -> replacd CDYAR_DEFINE_TYPE_HANDLER specific-type, typehandler function generating macro
    -> with a truly generic typehandler function relying on memcpy instead of explicit typecasts


// Character types
CDYAR_DEFINE_TYPE_HANDLER(char, char)
CDYAR_DEFINE_TYPE_HANDLER(signed char, schar)
CDYAR_DEFINE_TYPE_HANDLER(unsigned char, uchar)

// Integer types
CDYAR_DEFINE_TYPE_HANDLER(short, short)
CDYAR_DEFINE_TYPE_HANDLER(unsigned short, ushort)
CDYAR_DEFINE_TYPE_HANDLER(int, int)
CDYAR_DEFINE_TYPE_HANDLER(unsigned int, uint)
CDYAR_DEFINE_TYPE_HANDLER(long, long)
CDYAR_DEFINE_TYPE_HANDLER(unsigned long, ulong)
CDYAR_DEFINE_TYPE_HANDLER(long long, llong)
CDYAR_DEFINE_TYPE_HANDLER(unsigned long long, ullong)

// Floating-point types
CDYAR_DEFINE_TYPE_HANDLER(float, float)
CDYAR_DEFINE_TYPE_HANDLER(double, double)
CDYAR_DEFINE_TYPE_HANDLER(long double, ldouble)

// Boolean type (C99)
CDYAR_DEFINE_TYPE_HANDLER(_Bool, bool)

// Fixed-width integer types (stdint.h)
CDYAR_DEFINE_TYPE_HANDLER(int8_t, int8)
CDYAR_DEFINE_TYPE_HANDLER(uint8_t, uint8)
CDYAR_DEFINE_TYPE_HANDLER(int16_t, int16)
CDYAR_DEFINE_TYPE_HANDLER(uint16_t, uint16)
CDYAR_DEFINE_TYPE_HANDLER(int32_t, int32)
CDYAR_DEFINE_TYPE_HANDLER(uint32_t, uint32)
CDYAR_DEFINE_TYPE_HANDLER(int64_t, int64)
CDYAR_DEFINE_TYPE_HANDLER(uint64_t, uint64)

// Size and pointer difference types
CDYAR_DEFINE_TYPE_HANDLER(size_t, size)
CDYAR_DEFINE_TYPE_HANDLER(ptrdiff_t, ptrdiff)
CDYAR_DEFINE_TYPE_HANDLER(intptr_t, intptr)
CDYAR_DEFINE_TYPE_HANDLER(uintptr_t, uintptr)
*/

//generic type handler function
void cdyar_generic_typehandler(void *left_ptr, void *right_ptr,
                                   cdyar_flag direction, size_t size, cdyar_returncode *code) {
    /* Check code pointer is valid */
    CDYAR_CHECK_CODE(code);

    /* Validate input pointers */
    if (!left_ptr) {
        *code = CDYAR_INVALID_INPUT;
        return;
    }
    if (!right_ptr) {
        *code = CDYAR_INVALID_INPUT;
        return;
    }

    /* Cast pointers - safe after alignment checks */
    // type *internal_leftptr = (type *)left_ptr;
    // type *internal_rightptr = (type *)right_ptr;

    /* Perform assignment based on direction */
    switch (direction) {
        case CDYAR_DIRECTION_ASSIGN_LEFT_TO_RIGHT:
            memcpy(right_ptr, left_ptr, size);
            break;
        case CDYAR_DIRECTION_ASSIGN_RIGHT_TO_LEFT:
            memcpy(left_ptr, right_ptr, size);
            break;
        default:
            *code = CDYAR_INVALID_INPUT;
            return;
    }

    /* Success */
    *code = CDYAR_SUCCESSFUL;
}
