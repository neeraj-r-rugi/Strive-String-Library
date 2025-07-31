#ifndef STRIVE_NUMERALS_H
    #define STRIVE_NUMERALS_H
    //System Headers
    #include <stdint.h>
    #include <stdlib.h>
    #include <limits.h>
    #include <inttypes.h>
    #include <float.h>
    #include <stdio.h>
    #include <stddef.h>

    // Defining fixed width signed integers.
    #define i8      int8_t
    #define i16     int16_t
    #define i32     int32_t
    #define i64     int64_t

    // Defining fixed width un-signed integers.
    #define ui8     uint8_t
    #define ui16    uint16_t
    #define ui32    uint32_t
    #define ui64    uint64_t

    //Defining fixed width decimal/floating point values
    typedef float           f32;
    typedef double          f64;
    typedef long double     flong;

/*----------------------------------------------------------------------------*/
//Function Declaration
void print_type_info(void);
#endif