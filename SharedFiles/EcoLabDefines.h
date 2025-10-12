
#ifndef __I_ECOLAB_DEFINES_H__
#define __I_ECOLAB_DEFINES_H__
#include "IEcoBase1.h"

typedef enum ECO_DATA_TYPE{
    type_complex,
    type_double,
    type_single,
    type_int8,
    type_int16,
    type_int32,
    type_uint8,
    type_uint16,
    type_uint32,
    type_logical
} EcoDataType_e;

// Complex number structure for FFT

typedef struct EcoComplex {
    double real;
    double imag;
} EcoComplex;

#ifndef ECO_PI
#define ECO_PI 3.14159265358979323846
#endif

#endif
