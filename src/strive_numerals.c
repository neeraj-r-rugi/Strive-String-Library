#include "strive_numerals.h"

/*----------------------------------------------------------------------------*/
//Function Definition
void print_type_info(void) {
    printf("=== Standard Integer Types ===\n");
    printf("char:                 %d to %d\n", CHAR_MIN, CHAR_MAX);
    printf("unsigned char:        0 to %u\n", UCHAR_MAX);
    printf("short:                %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("unsigned short:       0 to %u\n", USHRT_MAX);
    printf("int:                  %d to %d\n", INT_MIN, INT_MAX);
    printf("unsigned int:         0 to %u\n", UINT_MAX);
    printf("long:                 %ld to %ld\n", LONG_MIN, LONG_MAX);
    printf("unsigned long:        0 to %lu\n", ULONG_MAX);
    printf("long long:            %lld to %lld\n", LLONG_MIN, LLONG_MAX);
    printf("unsigned long long:   0 to %llu\n\n", ULLONG_MAX);

    printf("=== Fixed-Width Integer Types (stdint.h) ===\n");
    printf("int8_t:               %" PRId8  " to %" PRId8  "\n", INT8_MIN, INT8_MAX);
    printf("uint8_t:              0 to %" PRIu8  "\n", UINT8_MAX);
    printf("int16_t:              %" PRId16 " to %" PRId16 "\n", INT16_MIN, INT16_MAX);
    printf("uint16_t:             0 to %" PRIu16 "\n", UINT16_MAX);
    printf("int32_t:              %" PRId32 " to %" PRId32 "\n", INT32_MIN, INT32_MAX);
    printf("uint32_t:             0 to %" PRIu32 "\n", UINT32_MAX);
    printf("int64_t:              %" PRId64 " to %" PRId64 "\n", INT64_MIN, INT64_MAX);
    printf("uint64_t:             0 to %" PRIu64 "\n", UINT64_MAX);

    printf("\n=== Size and Pointer Types ===\n");
    printf("size_t:               0 to %zu\n", (size_t)-1);
    printf("intptr_t:             %" PRIdPTR " to %" PRIdPTR "\n", INTPTR_MIN, INTPTR_MAX);
    printf("uintptr_t:            0 to %" PRIuPTR "\n\n", UINTPTR_MAX);

    printf("=== Floating Point Types ===\n");
    printf("float:       min: %e  max: %e  precision: %d digits\n",
           FLT_MIN, FLT_MAX, FLT_DIG);
    printf("double:      min: %e  max: %e  precision: %d digits\n",
           DBL_MIN, DBL_MAX, DBL_DIG);
    printf("long double: min: %Le max: %Le precision: %d digits\n",
           LDBL_MIN, LDBL_MAX, LDBL_DIG);
}