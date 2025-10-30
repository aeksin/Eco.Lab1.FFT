/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoLab1
 * </сводка>
 *
 * <описание>
 *   Данный исходный код описывает реализацию интерфейсов CEcoLab1
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#include "IEcoSystem1.h"
#include "IEcoInterfaceBus1.h"
#include "IEcoInterfaceBus1MemExt.h"
#include "IdEcoCalculatorA.h"
#include "IdEcoCalculatorB.h"
#include "IdEcoCalculatorD.h"
#include "IdEcoCalculatorE.h"
#include "CEcoLab1.h"
#include "CEcoVector.h"

/*
 *
 * <сводка>
 *   Функция QueryInterface
 * </сводка>
 *
 * <описание>
 *   Функция QueryInterface для интерфейса IEcoLab1
 * </описание>
 *
 */
static int16_t ECOCALLMETHOD CEcoLab1_QueryInterface(/* in */ IEcoLab1Ptr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv) {
    CEcoLab1* pCMe = (CEcoLab1*)me;

    /* Проверка указателей */
    if ( me == 0 || ppv == 0 ) {
        return ERR_ECO_POINTER;
    }

    return pCMe->m_pIUnkOuter->pVTbl->QueryInterface(pCMe->m_pIUnkOuter, riid, ppv);
}

/*
 *
 * <сводка>
 *   Функция AddRef
 * </сводка>
 *
 * <описание>
 *   Функция AddRef для интерфейса IEcoLab1
 * </описание>
 *
 */
static uint32_t ECOCALLMETHOD CEcoLab1_AddRef(/* in */ IEcoLab1Ptr_t me) {
    CEcoLab1* pCMe = (CEcoLab1*)me;

    /* Проверка указателя */
    if ( me == 0 ) {
        return -1; /* ERR_ECO_POINTER */
    }

    return pCMe->m_pIUnkOuter->pVTbl->AddRef(pCMe->m_pIUnkOuter);
}

/*
 *
 * <сводка>
 *   Функция Release
 * </сводка>
 *
 * <описание>
 *   Функция Release для интерфейса IEcoLab1
 * </описание>
 *
 */
static uint32_t ECOCALLMETHOD CEcoLab1_Release(/* in */ IEcoLab1Ptr_t me) {
    CEcoLab1* pCMe = (CEcoLab1*)me;

    /* Проверка указателя */
    if ( me == 0 ) {
        return -1; /* ERR_ECO_POINTER */
    }

    return pCMe->m_pIUnkOuter->pVTbl->Release(pCMe->m_pIUnkOuter);
}

/*
 *
 * <сводка>
 *   Функция QueryInterface
 * </сводка>
 *
 * <описание>
 *   Функция QueryInterface для интерфейса IEcoCalculatorY
 * </описание>
 *
 */
static int16_t ECOCALLMETHOD CEcoLab1_IEcoCalculatorY_QueryInterface(/* in */ IEcoCalculatorYPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv) {
    CEcoLab1* pCMe = (CEcoLab1*)((uint64_t)me - sizeof(IEcoUnknownPtr_t));

    /* Проверка указателей */
    if ( me == 0 || ppv == 0 ) {
        return ERR_ECO_POINTER;
    }

    return pCMe->m_pIUnkOuter->pVTbl->QueryInterface(pCMe->m_pIUnkOuter, riid, ppv);
}

/*
 *
 * <сводка>
 *   Функция AddRef
 * </сводка>
 *
 * <описание>
 *   Функция AddRef для интерфейса IEcoCalculatorY
 * </описание>
 *
 */
static uint32_t ECOCALLMETHOD CEcoLab1_IEcoCalculatorY_AddRef(/* in */ IEcoCalculatorYPtr_t me) {
    CEcoLab1* pCMe = (CEcoLab1*)((uint64_t)me - sizeof(IEcoUnknownPtr_t));

    /* Проверка указателя */
    if ( me == 0 ) {
        return -1; /* ERR_ECO_POINTER */
    }

    return pCMe->m_pIUnkOuter->pVTbl->AddRef(pCMe->m_pIUnkOuter);
}

/*
 *
 * <сводка>
 *   Функция Release
 * </сводка>
 *
 * <описание>
 *   Функция Release для интерфейса IEcoCalculatorY
 * </описание>
 *
 */
static uint32_t ECOCALLMETHOD CEcoLab1_IEcoCalculatorY_Release(/* in */ IEcoCalculatorYPtr_t me) {
    CEcoLab1* pCMe = (CEcoLab1*)((uint64_t)me - sizeof(IEcoUnknownPtr_t));

    /* Проверка указателя */
    if ( me == 0 ) {
        return -1; /* ERR_ECO_POINTER */
    }

    return pCMe->m_pIUnkOuter->pVTbl->Release(pCMe->m_pIUnkOuter);
}

/*
 *
 * <сводка>
 *   Функция Multiplication
 * </сводка>
 *
 * <описание>
 *   Функция Multiplication для интерфейса IEcoCalculatorY
 * </описание>
 *
 */
int32_t ECOCALLMETHOD CEcoLab1_IEcoCalculatorY_Multiplication(/* in */ IEcoCalculatorYPtr_t me, /* in */ int16_t a, /* in */ int16_t b) {
	CEcoLab1* pCMe = (CEcoLab1*)((uint64_t)me - sizeof(IEcoUnknownPtr_t));
    int32_t result = 0;

    /* Проверка указателей */
    if ( me == 0 ) {
        return -1; /* ERR_ECO_POINTER */
    }

	if ( pCMe->m_pIY != 0 ) {
		result = pCMe->m_pIY->pVTbl->Multiplication(pCMe->m_pIY, a, b);
	}

    return result;
}

/*
 *
 * <сводка>
 *   Функция Division
 * </сводка>
 *
 * <описание>
 *   Функция Division для интерфейса IEcoCalculatorY
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CEcoLab1_IEcoCalculatorY_Division(/* in */ IEcoCalculatorYPtr_t me, /* in */ int16_t a, /* in */ int16_t b) {
    CEcoLab1* pCMe = (CEcoLab1*)((uint64_t)me - sizeof(IEcoUnknownPtr_t));
    int16_t result = 0;

    /* Проверка указателей */
    if ( me == 0 ) {
        return -1; /* ERR_ECO_POINTER */
    }

    if ( pCMe->m_pIY != 0 ) {
		result = pCMe->m_pIY->pVTbl->Division(pCMe->m_pIY, a, b);
	}

    return result;
}


/*
 *
 * <сводка>
 *   Функция QueryInterface
 * </сводка>
 *
 * <описание>
 *   Функция QueryInterface для интерфейса IEcoCalculatorX
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CEcoLab1_IEcoCalculatorX_QueryInterface(/* in */ IEcoCalculatorXPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv) {
    CEcoLab1* pCMe = (CEcoLab1*)((uint64_t)me - 2 * sizeof(IEcoUnknownPtr_t));

    /* Проверка указателей */
    if ( me == 0 || ppv == 0 ) {
        return ERR_ECO_POINTER;
    }

    return pCMe->m_pIUnkOuter->pVTbl->QueryInterface(pCMe->m_pIUnkOuter, riid, ppv);
}

/*
 *
 * <сводка>
 *   Функция AddRef
 * </сводка>
 *
 * <описание>
 *   Функция AddRef для интерфейса IEcoCalculatorX
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CEcoLab1_IEcoCalculatorX_AddRef(/* in */ IEcoCalculatorXPtr_t me) {
    CEcoLab1* pCMe = (CEcoLab1*)((uint64_t)me - 2 * sizeof(IEcoUnknownPtr_t));

    /* Проверка указателя */
    if ( me == 0 ) {
        return -1; /* ERR_ECO_POINTER */
    }

    return pCMe->m_pIUnkOuter->pVTbl->AddRef(pCMe->m_pIUnkOuter);
}

/*
 *
 * <сводка>
 *   Функция Release
 * </сводка>
 *
 * <описание>
 *   Функция Release для интерфейса IEcoCalculatorX
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CEcoLab1_IEcoCalculatorX_Release(/* in */ IEcoCalculatorXPtr_t me) {
    CEcoLab1* pCMe = (CEcoLab1*)((uint64_t)me - 2 * sizeof(IEcoUnknownPtr_t));

    /* Проверка указателя */
    if ( me == 0 ) {
        return -1; /* ERR_ECO_POINTER */
    }

    return pCMe->m_pIUnkOuter->pVTbl->Release(pCMe->m_pIUnkOuter);
}

/*
 *
 * <сводка>
 *   Функция Addition
 * </сводка>
 *
 * <описание>
 *   Функция Addition для интерфейса IEcoCalculatorX
 * </описание>
 *
 */
int32_t ECOCALLMETHOD CEcoLab1_IEcoCalculatorX_Addition(/* in */ IEcoCalculatorXPtr_t me, /* in */ int16_t a, /* in */ int16_t b) {
    CEcoLab1* pCMe = (CEcoLab1*)((uint64_t)me - 2 * sizeof(IEcoUnknownPtr_t));
    int32_t result = 0;

    /* Проверка указателей */
    if ( me == 0 ) {
        return -1; /* ERR_ECO_POINTER */
    }

    if ( pCMe->m_pIX != 0 ) {
        result = pCMe->m_pIX->pVTbl->Addition(pCMe->m_pIX, a, b);
    }

    return result;
}

/*
 *
 * <сводка>
 *   Функция Subtraction
 * </сводка>
 *
 * <описание>
 *   Функция Subtraction для интерфейса IEcoCalculatorX
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CEcoLab1_IEcoCalculatorX_Subtraction(/* in */ IEcoCalculatorXPtr_t me, /* in */ int16_t a, /* in */ int16_t b) {
    CEcoLab1* pCMe = (CEcoLab1*)((uint64_t)me - 2 * sizeof(IEcoUnknownPtr_t));
    int16_t result = 0;

    /* Проверка указателей */
    if ( me == 0 ) {
        return -1; /* ERR_ECO_POINTER */
    }

    if ( pCMe->m_pIX != 0 ) {
        result = pCMe->m_pIX->pVTbl->Subtraction(pCMe->m_pIX, a, b);
    }

    return result;
}

/*
 *
 * <сводка>
 *   Функция NondelegatingQueryInterface
 * </сводка>
 *
 * <описание>
 *   Функция NondelegatingQueryInterface для интерфейса IEcoLab1
 * </описание>
 *
 */
static int16_t ECOCALLMETHOD CEcoLab1_NondelegatingQueryInterface(/* in */ IEcoUnknownPtr_t me, /* in */ const UGUID* riid, /* out */ void** ppv) {
    CEcoLab1* pCMe = (CEcoLab1*)((uint64_t)me - 3 * sizeof(IEcoUnknownPtr_t));

    /* Проверка указателей */
    if ( me == 0 || ppv == 0 ) {
        return ERR_ECO_POINTER;
    }

    /* Проверка и получение запрошенного интерфейса */
    if ( IsEqualUGUID(riid, &IID_IEcoLab1) ) {
        *ppv = &pCMe->m_pVTblIEcoLab1;
        pCMe->m_pVTblIEcoLab1->AddRef((IEcoLab1*)pCMe);
    }
    else if (IsEqualUGUID(riid, &IID_IEcoVector))
    {
        *ppv = &pCMe->m_pVTblIEcoVector;
        pCMe->m_pVTblIEcoLab1->AddRef((IEcoLab1 *)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoCalculatorX) ) {
        if ( pCMe->m_pInnerUnknown != 0 ) {
            pCMe->m_pInnerUnknown->pVTbl->QueryInterface(pCMe->m_pInnerUnknown, riid, ppv);
        }
        else {
            *ppv = &pCMe->m_pVTblX;
            pCMe->m_pVTblIEcoLab1->AddRef((IEcoLab1*)pCMe);
        }
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoCalculatorY) ) {
        *ppv = &pCMe->m_pVTblY;
        pCMe->m_pVTblIEcoLab1->AddRef((IEcoLab1*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoUnknown) ) {
        *ppv = &pCMe->m_pVTblINondelegatingUnk;
        ++pCMe->m_cRef;
    }
    else {
        *ppv = 0;
        return ERR_ECO_NOINTERFACE;
    }
    return ERR_ECO_SUCCESES;
}

/*
 *
 * <сводка>
 *   Функция NondelegatingAddRef
 * </сводка>
 *
 * <описание>
 *   Функция NondelegatingAddRef для интерфейса IEcoLab1
 * </описание>
 *
 */
static uint32_t ECOCALLMETHOD CEcoLab1_NondelegatingAddRef(/* in */ IEcoUnknownPtr_t me) {
    CEcoLab1 *pCMe = (CEcoLab1 *)((uint64_t)me - 3 * sizeof(IEcoUnknownPtr_t));

    /* Проверка указателя */
    if ( me == 0 ) {
        return -1; /* ERR_ECO_POINTER */
    }

    return ++pCMe->m_cRef;
}

/*
 *
 * <сводка>
 *   Функция NondelegatingRelease
 * </сводка>
 *
 * <описание>
 *   Функция NondelegatingRelease для интерфейса IEcoLab1
 * </описание>
 *
 */
static uint32_t ECOCALLMETHOD CEcoLab1_NondelegatingRelease(/* in */ IEcoUnknownPtr_t me) {
    CEcoLab1* pCMe = (CEcoLab1*)((uint64_t)me - 3 * sizeof(IEcoUnknownPtr_t));

    /* Проверка указателя */
    if ( me == 0 ) {
        return -1; /* ERR_ECO_POINTER */
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if ( pCMe->m_cRef == 0 ) {
        if ( pCMe->m_pInnerUnknown != 0 ) {
            /* Предотвращение рекурсивного вызова */
            if ( pCMe->m_pInnerUnknown->pVTbl->Release(pCMe->m_pInnerUnknown) == 0 ) {
                pCMe->m_pInnerUnknown = 0;
            }
            else {
                pCMe->m_cRef = 1;
            }
        }
        if ( pCMe->m_cRef == 0 ) {
            deleteCEcoLab1((IEcoLab1*)pCMe);
        }
        return 0;
    }
    return pCMe->m_cRef;
}

/*
 *
 * <сводка>
 *   Функция Init
 * </сводка>
 *
 * <описание>
 *   Функция инициализации экземпляра
 * </описание>
 *
 */
int16_t ECOCALLMETHOD initCEcoLab1(/* in */ IEcoLab1Ptr_t me, /* in */ IEcoUnknownPtr_t pIUnkSystem){
    if (me == 0)
    {
        return ERR_ECO_POINTER;
    }

    return ERR_ECO_SUCCESES;
}



EcoComplex complexAdd(const EcoComplex *a, const EcoComplex *b)
{
    EcoComplex res;
    res.real = a->real + b->real;
    res.imag = a->imag + b->imag;
    return res;
}

EcoComplex complexSub(const EcoComplex *a, const EcoComplex *b)
{
    EcoComplex res;
    res.real = a->real - b->real;
    res.imag = a->imag - b->imag;
    return res;
}

EcoComplex complexMul(const EcoComplex *a, const EcoComplex *b)
{
    EcoComplex res;
    res.real = a->real * b->real - a->imag * b->imag;
    res.imag = a->real * b->imag + a->imag * b->real;
    return res;
}

#define CORDIC_ITERATIONS 32

static double atan_table[CORDIC_ITERATIONS] = {
    0.7853981633974483,   0.4636476090008061,   0.24497866312686414,
    0.12435499454676144,  0.06241880999595735,  0.031239833430268277,
    0.015623728620476831, 0.007812341060101111, 0.0039062301319669718,
    0.0019531225164788188, 0.0009765621895593195, 0.0004882812111948983,
    0.00024414062014936177, 0.00012207031189367021, 6.103515617420877e-05,
    3.0517578115526096e-05, 1.5258789061315762e-05, 7.62939453110197e-06,
    3.814697265606496e-06, 1.907348632810187e-06, 9.536743164059608e-07,
    4.7683715820308884e-07, 2.3841857910155797e-07, 1.1920928955078068e-07,
    5.960464477539055e-08, 2.9802322387695303e-08, 1.4901161193847655e-08,
    7.450580596923828e-09, 3.725290298461914e-09, 1.862645149230957e-09,
    9.313225746154785e-10, 4.656612873077393e-10
};

static const double CORDIC_GAIN_32 = 0.6072529350088812561694;

static void cordic(double theta, double *sin_val, double *cos_val)
{
    theta = fmod(theta, 2.0 * ECO_PI);
    if (theta > ECO_PI) {
        theta -= 2.0 * ECO_PI;
    } else if (theta < -ECO_PI) {
        theta += 2.0 * ECO_PI;
    }
    
    int sign = 1;
    if (theta < -ECO_PI / 2) {
        theta += ECO_PI;
        sign = -1;
    } else if (theta > ECO_PI / 2) {
        theta -= ECO_PI;
        sign = -1;
    }

    double x = 1.0;
    double y = 0.0;
    double z = theta;

    for (int i = 0; i < CORDIC_ITERATIONS; i++)
    {
        double d = (z >= 0) ? 1.0 : -1.0;
        double x_new = x - d * y * (1.0 / (1UL << i)); 
        double y_new = y + d * x * (1.0 / (1UL << i));
        z = z - d * atan_table[i];

        x = x_new;
        y = y_new;
    }

    *cos_val = sign * x * CORDIC_GAIN_32;
    *sin_val = sign * y * CORDIC_GAIN_32;
}

static double ecoSin(double x)
{
    double sin_val, cos_val;
    cordic(x, &sin_val, &cos_val);
    return sin_val;
}

static double ecoCos(double x)
{
    double sin_val, cos_val;
    cordic(x, &sin_val, &cos_val);
    return cos_val;
}

static int16_t ECOCALLMETHOD CEcoLab1_FFT_Vector(/* in */ IEcoLab1Ptr_t me, /* in */ IEcoVectorPtr_t input, /* out */ IEcoVectorPtr_t *output)
{
    CEcoLab1 *pCMe = (CEcoLab1 *)me;

    uint32_t n = input->pVTbl->GetSize(input);
    uint64_t log = 1;
    while (log < n)
    {
        log *= 2;
    }
    if (*output == 0)
    {
        *output = pCMe->m_pVTblIEcoVector->NewVector(input, type_complex, log);
        if (*output == 0)
        {
            return ERR_ECO_OUTOFMEMORY;
        }
    }

    IEcoVectorPtr_t result = *output;
    if (result->pVTbl->GetType(result) != type_complex)
    {
        return ERR_ECO_INVALIDARG;
    }
    for (int i = 0; i < n; i++)
    {
        EcoComplex tmp;
        input->pVTbl->Get(input, i, &tmp, type_complex);
        result->pVTbl->Set(result, i, &tmp, type_complex);
    }

    for (int i = n; i < log; i++)
    {
        EcoComplex tmp;
        tmp.imag = 0;
        tmp.real = 0;
        result->pVTbl->Set(result, i, &tmp, type_complex);
    }

    n = log;
    for (uint64_t i = 1, j = 0; i < n; i++)
    {
        uint64_t bit = n >> 1;
        for (; j >= bit; bit >>= 1)
        {
            j -= bit;
        }
        j += bit;
        if (i < j)
        {
            EcoComplex tmp1, tmp2;
            result->pVTbl->Get(result, i, &tmp1, type_complex);
            result->pVTbl->Get(result, j, &tmp2, type_complex);
            result->pVTbl->Set(result, i, &tmp2, type_complex);
            result->pVTbl->Set(result, j, &tmp1, type_complex);
        }
    }
    for (uint64_t len = 2; len <= n; len <<= 1)
    {
        double angle = ((double)(-2 * ECO_PI)) / len;
        EcoComplex wlen;
        wlen.real = ecoCos(angle);
        wlen.imag = ecoSin(angle);
        for (int i = 0; i < n; i += len)
        {
            EcoComplex w;
            w.real = 1;
            w.imag = 0;
            for (int j = 0; j < len / 2; j++)
            {
                EcoComplex u, v, tmp;
                result->pVTbl->Get(result, i + j, &u, type_complex);
                result->pVTbl->Get(result, i + j + len / 2, &v, type_complex);
                v = complexMul(&v, &w);
                tmp = complexAdd(&u, &v);
                result->pVTbl->Set(result, i + j, &tmp, type_complex);
                tmp = complexSub(&u, &v);
                result->pVTbl->Set(result, i + j + len / 2, &tmp, type_complex);
                w = complexMul(&w, &wlen);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        EcoComplex tmp;
        input->pVTbl->Get(result, i, &tmp, type_complex);
    }
    for (int i = 0; i < n; i++)
    {
        EcoComplex tmp;
        input->pVTbl->Get(*output, i, &tmp, type_complex);
    }

    return ERR_ECO_SUCCESES;
}

static int16_t ECOCALLMETHOD CEcoVector_Set(/* in */ IEcoVectorPtr_t me, /* in */ uint32_t index, /* in */ void *value, EcoDataType_e valueType)
{
    CEcoVector *pCMe = (CEcoVector *)me;
    if (me == 0 || value == 0)
    {
        return ERR_ECO_POINTER;
    }
    if (index >= pCMe->m_Size || pCMe->m_pData == 0 || pCMe->m_ElementSize == 0)
    {
        return ERR_ECO_POINTER;
    }
    void *dest = (pCMe->m_pData + index * (pCMe->m_ElementSize));
    EcoDataType_e destType = pCMe->m_Type;
    switch (destType)
    {
    case type_complex:
    {
        switch (valueType)
        {
        case type_complex:
            *(EcoComplex *)dest = *(EcoComplex *)value;
            break;
        case type_double:
            (*(EcoComplex *)dest).real = *(double *)value;
            break;
        case type_single:
            (*(EcoComplex *)dest).real = *(float *)value;
            break;
        case type_int8:
            (*(EcoComplex *)dest).real = *(int8_t *)value;
            break;
        case type_int16:
            (*(EcoComplex *)dest).real = *(int16_t *)value;
            break;
        case type_int32:
            (*(EcoComplex *)dest).real = *(int32_t *)value;
            break;
        case type_uint8:
            (*(EcoComplex *)dest).real = *(uint8_t *)value;
            break;
        case type_uint16:
            (*(EcoComplex *)dest).real = *(uint16_t *)value;
            break;
        case type_uint32:
            (*(EcoComplex *)dest).real = *(uint32_t *)value;
            break;
        case type_logical:
            (*(EcoComplex *)dest).real = *(uint8_t *)value;
            break;
        default:
            return ERR_ECO_INVALIDARG;
        }
        break;
    }

    case type_double:
    {
        switch (valueType)
        {
        case type_complex:
            *(double *)dest = (*(EcoComplex *)value).real;
            break;
        case type_double:
            *(double *)dest = *(double *)value;
            break;
        case type_single:
            *(double *)dest = (double)*(float *)value;
            break;
        case type_int8:
            *(double *)dest = (double)*(int8_t *)value;
            break;
        case type_int16:
            *(double *)dest = (double)*(int16_t *)value;
            break;
        case type_int32:
            *(double *)dest = (double)*(int32_t *)value;
            break;
        case type_uint8:
            *(double *)dest = (double)*(uint8_t *)value;
            break;
        case type_uint16:
            *(double *)dest = (double)*(uint16_t *)value;
            break;
        case type_uint32:
            *(double *)dest = (double)*(uint32_t *)value;
            break;
        case type_logical:
            *(double *)dest = *(uint8_t *)value ? 1.0 : 0.0;
            break;
        default:
            return ERR_ECO_INVALIDARG;
        }
        break;
    }

    case type_single:
    {
        switch (valueType)
        {
        case type_complex:
            *(float *)dest = (float)(*(EcoComplex *)value).real;
            break;
        case type_double:
            *(float *)dest = (float)*(double *)value;
            break;
        case type_single:
            *(float *)dest = *(float *)value;
            break;
        case type_int8:
            *(float *)dest = (float)*(int8_t *)value;
            break;
        case type_int16:
            *(float *)dest = (float)*(int16_t *)value;
            break;
        case type_int32:
            *(float *)dest = (float)*(int32_t *)value;
            break;
        case type_uint8:
            *(float *)dest = (float)*(uint8_t *)value;
            break;
        case type_uint16:
            *(float *)dest = (float)*(uint16_t *)value;
            break;
        case type_uint32:
            *(float *)dest = (float)*(uint32_t *)value;
            break;
        case type_logical:
            *(float *)dest = *(uint8_t *)value ? 1.0f : 0.0f;
            break;
        default:
            return ERR_ECO_INVALIDARG;
        }
        break;
    }

    case type_int8:
    {
        switch (valueType)
        {
        case type_complex:
        {
            double real_val = (*(EcoComplex *)value).real;
            if (real_val >= INT8_MIN && real_val <= INT8_MAX)
            {
                *(int8_t *)dest = (int8_t)real_val;
            }
            else
            {
                return ERR_ECO_INVALIDARG;
            }
        }
        break;
        case type_double:
            if (*(double *)value >= INT8_MIN && *(double *)value <= INT8_MAX)
            {
                *(int8_t *)dest = (int8_t)*(double *)value;
            }
            else
            {
                return ERR_ECO_INVALIDARG;
            }
            break;
        case type_single:
            if (*(float *)value >= INT8_MIN && *(float *)value <= INT8_MAX)
            {
                *(int8_t *)dest = (int8_t)*(float *)value;
            }
            else
            {
                return ERR_ECO_INVALIDARG;
            }
            break;
        case type_int8:
            *(int8_t *)dest = *(int8_t *)value;
            break;
        case type_int16:
            if (*(int16_t *)value >= INT8_MIN && *(int16_t *)value <= INT8_MAX)
            {
                *(int8_t *)dest = (int8_t)*(int16_t *)value;
            }
            else
            {
                return ERR_ECO_INVALIDARG;
            }
            break;
        case type_int32:
            if (*(int32_t *)value >= INT8_MIN && *(int32_t *)value <= INT8_MAX)
            {
                *(int8_t *)dest = (int8_t)*(int32_t *)value;
            }
            else
            {
                return ERR_ECO_INVALIDARG;
            }
            break;
        case type_uint8:
            if (*(uint8_t *)value <= INT8_MAX)
            {
                *(int8_t *)dest = (int8_t)*(uint8_t *)value;
            }
            else
            {
                return ERR_ECO_INVALIDARG;
            }
            break;
        case type_uint16:
            if (*(uint16_t *)value <= INT8_MAX)
            {
                *(int8_t *)dest = (int8_t)*(uint16_t *)value;
            }
            else
            {
                return ERR_ECO_INVALIDARG;
            }
            break;
        case type_uint32:
            if (*(uint32_t *)value <= INT8_MAX)
            {
                *(int8_t *)dest = (int8_t)*(uint32_t *)value;
            }
            else
            {
                return ERR_ECO_INVALIDARG;
            }
            break;
        case type_logical:
            *(int8_t *)dest = *(int8_t *)value ? 1 : 0;
            break;
        default:
            return ERR_ECO_INVALIDARG;
        }
        break;
    }

    case type_int16:
    {
        switch (valueType)
        {
        case type_complex:
        {
            double real_val = (*(EcoComplex *)value).real;
            if (real_val >= INT16_MIN && real_val <= INT16_MAX)
            {
                *(int16_t *)dest = (int16_t)real_val;
            }
            else
            {
                return ERR_ECO_INVALIDARG;
            }
        }
        break;
        case type_double:
            if (*(double *)value >= INT16_MIN && *(double *)value <= INT16_MAX)
            {
                *(int16_t *)dest = (int16_t)*(double *)value;
            }
            else
            {
                return ERR_ECO_INVALIDARG;
            }
            break;
        case type_single:
            if (*(float *)value >= INT16_MIN && *(float *)value <= INT16_MAX)
            {
                *(int16_t *)dest = (int16_t)*(float *)value;
            }
            else
            {
                return ERR_ECO_INVALIDARG;
            }
            break;
        case type_int8:
            *(int16_t *)dest = (int16_t)*(int8_t *)value;
            break;
        case type_int16:
            *(int16_t *)dest = *(int16_t *)value;
            break;
        case type_int32:
            if (*(int32_t *)value >= INT16_MIN && *(int32_t *)value <= INT16_MAX)
            {
                *(int16_t *)dest = (int16_t)*(int32_t *)value;
            }
            else
            {
                return ERR_ECO_INVALIDARG;
            }
            break;
        case type_uint8:
            *(int16_t *)dest = (int16_t)*(uint8_t *)value;
            break;
        case type_uint16:
            if (*(uint16_t *)value <= INT16_MAX)
            {
                *(int16_t *)dest = (int16_t)*(uint16_t *)value;
            }
            else
            {
                return ERR_ECO_INVALIDARG;
            }
            break;
        case type_uint32:
            if (*(uint32_t *)value <= INT16_MAX)
            {
                *(int16_t *)dest = (int16_t)*(uint32_t *)value;
            }
            else
            {
                return ERR_ECO_INVALIDARG;
            }
            break;
        case type_logical:
            *(int16_t *)dest = *(int8_t *)value ? 1 : 0;
            break;
        default:
            return ERR_ECO_INVALIDARG;
        }
        break;
    }

    case type_int32:
    {
        switch (valueType)
        {
        case type_complex:
        {
            double real_val = (*(EcoComplex *)value).real;
            if (real_val >= INT32_MIN && real_val <= INT32_MAX)
            {
                *(int32_t *)dest = (int32_t)real_val;
            }
            else
            {
                return ERR_ECO_INVALIDARG;
            }
        }
        break;
        case type_double:
            if (*(double *)value >= INT32_MIN && *(double *)value <= INT32_MAX)
            {
                *(int32_t *)dest = (int32_t)*(double *)value;
            }
            else
            {
            }
            break;
        case type_single:
            if (*(float *)value >= INT32_MIN && *(float *)value <= INT32_MAX)
            {
                *(int32_t *)dest = (int32_t)*(float *)value;
            }
            else
            {
                return ERR_ECO_INVALIDARG;
            }
            break;
        case type_int8:
            *(int32_t *)dest = (int32_t)*(int8_t *)value;
            break;
        case type_int16:
            *(int32_t *)dest = (int32_t)*(int16_t *)value;
            break;
        case type_int32:
            *(int32_t *)dest = *(int32_t *)value;
            break;
        case type_uint8:
            *(int32_t *)dest = (int32_t)*(uint8_t *)value;
            break;
        case type_uint16:
            *(int32_t *)dest = (int32_t)*(uint16_t *)value;
            break;
        case type_uint32:
            if (*(uint32_t *)value <= INT32_MAX)
            {
                *(int32_t *)dest = (int32_t)*(uint32_t *)value;
            }
            else
            {
                return ERR_ECO_INVALIDARG;
            }
            break;
        case type_logical:
            *(int32_t *)dest = *(int8_t *)value ? 1 : 0;
            break;
        default:
            return ERR_ECO_INVALIDARG;
        }
        break;
    }

    case type_uint8:
    {
        switch (valueType)
        {
        case type_complex:
        {
            double real_val = (*(EcoComplex *)value).real;
            if (real_val >= 0 && real_val <= UINT8_MAX)
            {
                *(uint8_t *)dest = (uint8_t)real_val;
            }
            else
            {
                return ERR_ECO_INVALIDARG;
            }
        }
        break;
        case type_double:
            if (*(double *)value >= 0 && *(double *)value <= UINT8_MAX)
            {
                *(uint8_t *)dest = (uint8_t)*(double *)value;
            }
            else
            {
                return ERR_ECO_INVALIDARG;
            }
            break;
        case type_single:
            if (*(float *)value >= 0 && *(float *)value <= UINT8_MAX)
            {
                *(uint8_t *)dest = (uint8_t)*(float *)value;
            }
            else
            {
                return ERR_ECO_INVALIDARG;
            }
            break;
        case type_int8:
            if (*(int8_t *)value >= 0)
            {
                *(uint8_t *)dest = (uint8_t)*(int8_t *)value;
            }
            else
            {
                return ERR_ECO_INVALIDARG;
            }
            break;
        case type_int16:
            if (*(int16_t *)value >= 0 && *(int16_t *)value <= UINT8_MAX)
            {
                *(uint8_t *)dest = (uint8_t)*(int16_t *)value;
            }
            else
            {
                return ERR_ECO_INVALIDARG;
            }
            break;
        case type_int32:
            if (*(int32_t *)value >= 0 && *(int32_t *)value <= UINT8_MAX)
            {
                *(uint8_t *)dest = (uint8_t)*(int32_t *)value;
            }
            else
            {
                return ERR_ECO_INVALIDARG;
            }
            break;
        case type_uint8:
            *(uint8_t *)dest = *(uint8_t *)value;
            break;
        case type_uint16:
            if (*(uint16_t *)value <= UINT8_MAX)
            {
                *(uint8_t *)dest = (uint8_t)*(uint16_t *)value;
            }
            else
            {
                return ERR_ECO_INVALIDARG;
            }
            break;
        case type_uint32:
            if (*(uint32_t *)value <= UINT8_MAX)
            {
                *(uint8_t *)dest = (uint8_t)*(uint32_t *)value;
            }
            else
            {
                return ERR_ECO_INVALIDARG;
            }
            break;
        case type_logical:
            *(uint8_t *)dest = *(int8_t *)value ? 1 : 0;
            break;
        default:
            return ERR_ECO_INVALIDARG;
        }
        break;
    }

    case type_uint16:
    {
        switch (valueType)
        {
        case type_complex:
        {
            double real_val = (*(EcoComplex *)value).real;
            if (real_val >= 0 && real_val <= UINT16_MAX)
            {
                *(uint16_t *)dest = (uint16_t)real_val;
            }
            else
            {
                return ERR_ECO_INVALIDARG;
            }
        }
        break;
        case type_double:
            if (*(double *)value >= 0 && *(double *)value <= UINT16_MAX)
            {
                *(uint16_t *)dest = (uint16_t)*(double *)value;
            }
            else
            {
                return ERR_ECO_INVALIDARG;
            }
            break;
        case type_single:
            if (*(float *)value >= 0 && *(float *)value <= UINT16_MAX)
            {
                *(uint16_t *)dest = (uint16_t)*(float *)value;
            }
            else
            {
                return ERR_ECO_INVALIDARG;
            }
            break;
        case type_int8:
            if (*(int8_t *)value >= 0)
            {
                *(uint16_t *)dest = (uint16_t)*(int8_t *)value;
            }
            else
            {
                return ERR_ECO_INVALIDARG;
            }
            break;
        case type_int16:
            if (*(int16_t *)value >= 0)
            {
                *(uint16_t *)dest = (uint16_t)*(int16_t *)value;
            }
            else
            {
                return ERR_ECO_INVALIDARG;
            }
            break;
        case type_int32:
            if (*(int32_t *)value >= 0 && *(int32_t *)value <= UINT16_MAX)
            {
                *(uint16_t *)dest = (uint16_t)*(int32_t *)value;
            }
            else
            {
                return ERR_ECO_INVALIDARG;
            }
            break;
        case type_uint8:
            *(uint16_t *)dest = (uint16_t)*(uint8_t *)value;
            break;
        case type_uint16:
            *(uint16_t *)dest = *(uint16_t *)value;
            break;
        case type_uint32:
            if (*(uint32_t *)value <= UINT16_MAX)
            {
                *(uint16_t *)dest = (uint16_t)*(uint32_t *)value;
            }
            else
            {
                return ERR_ECO_INVALIDARG;
            }
            break;
        case type_logical:
            *(uint16_t *)dest = *(int8_t *)value ? 1 : 0;
            break;
        default:
            return ERR_ECO_INVALIDARG;
        }
        break;
    }

    case type_uint32:
    {
        switch (valueType)
        {
        case type_complex:
        {
            double real_val = (*(EcoComplex *)value).real;
            if (real_val >= 0 && real_val <= UINT32_MAX)
            {
                *(uint32_t *)dest = (uint32_t)real_val;
            }
            else
            {
                return ERR_ECO_INVALIDARG;
            }
        }
        break;
        case type_double:
            if (*(double *)value >= 0 && *(double *)value <= UINT32_MAX)
            {
                *(uint32_t *)dest = (uint32_t)*(double *)value;
            }
            else
            {
                return ERR_ECO_INVALIDARG;
            }
            break;
        case type_single:
            if (*(float *)value >= 0 && *(float *)value <= UINT32_MAX)
            {
                *(uint32_t *)dest = (uint32_t)*(float *)value;
            }
            else
            {
                return ERR_ECO_INVALIDARG;
            }
            break;
        case type_int8:
            if (*(int8_t *)value >= 0)
            {
                *(uint32_t *)dest = (uint32_t)*(int8_t *)value;
            }
            else
            {
                return ERR_ECO_INVALIDARG;
            }
            break;
        case type_int16:
            if (*(int16_t *)value >= 0)
            {
                *(uint32_t *)dest = (uint32_t)*(int16_t *)value;
            }
            else
            {
                return ERR_ECO_INVALIDARG;
            }
            break;
        case type_int32:
            if (*(int32_t *)value >= 0)
            {
                *(uint32_t *)dest = (uint32_t)*(int32_t *)value;
            }
            else
            {
                return ERR_ECO_INVALIDARG;
            }
            break;
        case type_uint8:
            *(uint32_t *)dest = (uint32_t)*(uint8_t *)value;
            break;
        case type_uint16:
            *(uint32_t *)dest = (uint32_t)*(uint16_t *)value;
            break;
        case type_uint32:
            *(uint32_t *)dest = *(uint32_t *)value;
            break;
        case type_logical:
            *(uint32_t *)dest = *(int8_t *)value ? 1 : 0;
            break;
        default:
            return ERR_ECO_INVALIDARG;
        }
        break;
    }

    case type_logical:
    {
        switch (valueType)
        {
        case type_complex:
            *(int8_t *)dest = ((*(EcoComplex *)value).real != 0.0) || ((*(EcoComplex *)value).imag != 0.0);
            break;
        case type_double:
            *(int8_t *)dest = (*(double *)value != 0.0);
            break;
        case type_single:
            *(int8_t *)dest = (*(float *)value != 0.0f);
            break;
        case type_int8:
            *(int8_t *)dest = (*(int8_t *)value != 0);
            break;
        case type_int16:
            *(int8_t *)dest = (*(int16_t *)value != 0);
            break;
        case type_int32:
            *(int8_t *)dest = (*(int32_t *)value != 0);
            break;
        case type_uint8:
            *(int8_t *)dest = (*(uint8_t *)value != 0);
            break;
        case type_uint16:
            *(int8_t *)dest = (*(uint16_t *)value != 0);
            break;
        case type_uint32:
            *(int8_t *)dest = (*(uint32_t *)value != 0);
            break;
        case type_logical:
            *(int8_t *)dest = *(int8_t *)value;
            break;
        default:
            return ERR_ECO_INVALIDARG;
        }
        break;
    }

    default:
        return ERR_ECO_INVALIDARG;
    }

    return ERR_ECO_SUCCESES;
}

static int16_t ECOCALLMETHOD CEcoVector_Get(/* in */ IEcoVectorPtr_t me, /* in */ uint32_t index, /* out */ void *dest, EcoDataType_e destType)
{
    CEcoVector *pCMe = (CEcoVector *)me;
    if (me == 0 || dest == 0)
    {
        return ERR_ECO_POINTER;
    }
    if (index >= pCMe->m_Size || pCMe->m_pData == 0 || pCMe->m_ElementSize == 0)
    {
        return ERR_ECO_POINTER;
    }

    void *value = (pCMe->m_pData + index * (pCMe->m_ElementSize));
    EcoDataType_e valueType = pCMe->m_Type;
    switch (destType)
    {
    case type_complex:
    {
        switch (valueType)
        {
        case type_complex:
            *(EcoComplex *)dest = *(EcoComplex *)value;
            break;
        case type_double:
            (*(EcoComplex *)dest).real = *(double *)value;
            break;
        case type_single:
            (*(EcoComplex *)dest).real = *(float *)value;
            break;
        case type_int8:
            (*(EcoComplex *)dest).real = *(int8_t *)value;
            break;
        case type_int16:
            (*(EcoComplex *)dest).real = *(int16_t *)value;
            break;
        case type_int32:
            (*(EcoComplex *)dest).real = *(int32_t *)value;
            break;
        case type_uint8:
            (*(EcoComplex *)dest).real = *(uint8_t *)value;
            break;
        case type_uint16:
            (*(EcoComplex *)dest).real = *(uint16_t *)value;
            break;
        case type_uint32:
            (*(EcoComplex *)dest).real = *(uint32_t *)value;
            break;
        case type_logical:
            (*(EcoComplex *)dest).real = *(uint8_t *)value;
            break;
        default:
            return ERR_ECO_INVALIDARG;
        }
        break;
    }

    case type_double:
    {
        switch (valueType)
        {
        case type_complex:
            *(double *)dest = (*(EcoComplex *)value).real;
            break;
        case type_double:
            *(double *)dest = *(double *)value;
            break;
        case type_single:
            *(double *)dest = (double)*(float *)value;
            break;
        case type_int8:
            *(double *)dest = (double)*(int8_t *)value;
            break;
        case type_int16:
            *(double *)dest = (double)*(int16_t *)value;
            break;
        case type_int32:
            *(double *)dest = (double)*(int32_t *)value;
            break;
        case type_uint8:
            *(double *)dest = (double)*(uint8_t *)value;
            break;
        case type_uint16:
            *(double *)dest = (double)*(uint16_t *)value;
            break;
        case type_uint32:
            *(double *)dest = (double)*(uint32_t *)value;
            break;
        case type_logical:
            *(double *)dest = *(uint8_t *)value ? 1.0 : 0.0;
            break;
        default:
            return ERR_ECO_INVALIDARG;
        }
        break;
    }

    case type_single:
    {
        switch (valueType)
        {
        case type_complex:
            *(float *)dest = (float)(*(EcoComplex *)value).real;
            break;
        case type_double:
            *(float *)dest = (float)*(double *)value;
            break;
        case type_single:
            *(float *)dest = *(float *)value;
            break;
        case type_int8:
            *(float *)dest = (float)*(int8_t *)value;
            break;
        case type_int16:
            *(float *)dest = (float)*(int16_t *)value;
            break;
        case type_int32:
            *(float *)dest = (float)*(int32_t *)value;
            break;
        case type_uint8:
            *(float *)dest = (float)*(uint8_t *)value;
            break;
        case type_uint16:
            *(float *)dest = (float)*(uint16_t *)value;
            break;
        case type_uint32:
            *(float *)dest = (float)*(uint32_t *)value;
            break;
        case type_logical:
            *(float *)dest = *(uint8_t *)value ? 1.0f : 0.0f;
            break;
        default:
            return ERR_ECO_INVALIDARG;
        }
        break;
    }

    case type_int8:
    {
        switch (valueType)
        {
        case type_complex:
        {
            double real_val = (*(EcoComplex *)value).real;
            if (real_val >= INT8_MIN && real_val <= INT8_MAX)
            {
                *(int8_t *)dest = (int8_t)real_val;
            }
            else
            {
                return ERR_ECO_INVALIDARG;
            }
        }
        break;
        case type_double:
            if (*(double *)value >= INT8_MIN && *(double *)value <= INT8_MAX)
            {
                *(int8_t *)dest = (int8_t)*(double *)value;
            }
            else
            {
                return ERR_ECO_INVALIDARG;
            }
            break;
        case type_single:
            if (*(float *)value >= INT8_MIN && *(float *)value <= INT8_MAX)
            {
                *(int8_t *)dest = (int8_t)*(float *)value;
            }
            else
            {
                return ERR_ECO_INVALIDARG;
            }
            break;
        case type_int8:
            *(int8_t *)dest = *(int8_t *)value;
            break;
        case type_int16:
            if (*(int16_t *)value >= INT8_MIN && *(int16_t *)value <= INT8_MAX)
            {
                *(int8_t *)dest = (int8_t)*(int16_t *)value;
            }
            else
            {
                return ERR_ECO_INVALIDARG;
            }
            break;
        case type_int32:
            if (*(int32_t *)value >= INT8_MIN && *(int32_t *)value <= INT8_MAX)
            {
                *(int8_t *)dest = (int8_t)*(int32_t *)value;
            }
            else
            {
                return ERR_ECO_INVALIDARG;
            }
            break;
        case type_uint8:
            if (*(uint8_t *)value <= INT8_MAX)
            {
                *(int8_t *)dest = (int8_t)*(uint8_t *)value;
            }
            else
            {
                return ERR_ECO_INVALIDARG;
            }
            break;
        case type_uint16:
            if (*(uint16_t *)value <= INT8_MAX)
            {
                *(int8_t *)dest = (int8_t)*(uint16_t *)value;
            }
            else
            {
                return ERR_ECO_INVALIDARG;
            }
            break;
        case type_uint32:
            if (*(uint32_t *)value <= INT8_MAX)
            {
                *(int8_t *)dest = (int8_t)*(uint32_t *)value;
            }
            else
            {
                return ERR_ECO_INVALIDARG;
            }
            break;
        case type_logical:
            *(int8_t *)dest = *(int8_t *)value ? 1 : 0;
            break;
        default:
            return ERR_ECO_INVALIDARG;
        }
        break;
    }

    case type_int16:
    {
        switch (valueType)
        {
        case type_complex:
        {
            double real_val = (*(EcoComplex *)value).real;
            if (real_val >= INT16_MIN && real_val <= INT16_MAX)
            {
                *(int16_t *)dest = (int16_t)real_val;
            }
            else
            {
                return ERR_ECO_INVALIDARG;
            }
        }
        break;
        case type_double:
            if (*(double *)value >= INT16_MIN && *(double *)value <= INT16_MAX)
            {
                *(int16_t *)dest = (int16_t)*(double *)value;
            }
            else
            {
                return ERR_ECO_INVALIDARG;
            }
            break;
        case type_single:
            if (*(float *)value >= INT16_MIN && *(float *)value <= INT16_MAX)
            {
                *(int16_t *)dest = (int16_t)*(float *)value;
            }
            else
            {
                return ERR_ECO_INVALIDARG;
            }
            break;
        case type_int8:
            *(int16_t *)dest = (int16_t)*(int8_t *)value;
            break;
        case type_int16:
            *(int16_t *)dest = *(int16_t *)value;
            break;
        case type_int32:
            if (*(int32_t *)value >= INT16_MIN && *(int32_t *)value <= INT16_MAX)
            {
                *(int16_t *)dest = (int16_t)*(int32_t *)value;
            }
            else
            {
                return ERR_ECO_INVALIDARG;
            }
            break;
        case type_uint8:
            *(int16_t *)dest = (int16_t)*(uint8_t *)value;
            break;
        case type_uint16:
            if (*(uint16_t *)value <= INT16_MAX)
            {
                *(int16_t *)dest = (int16_t)*(uint16_t *)value;
            }
            else
            {
                return ERR_ECO_INVALIDARG;
            }
            break;
        case type_uint32:
            if (*(uint32_t *)value <= INT16_MAX)
            {
                *(int16_t *)dest = (int16_t)*(uint32_t *)value;
            }
            else
            {
                return ERR_ECO_INVALIDARG;
            }
            break;
        case type_logical:
            *(int16_t *)dest = *(int8_t *)value ? 1 : 0;
            break;
        default:
            return ERR_ECO_INVALIDARG;
        }
        break;
    }

    case type_int32:
    {
        switch (valueType)
        {
        case type_complex:
        {
            double real_val = (*(EcoComplex *)value).real;
            if (real_val >= INT32_MIN && real_val <= INT32_MAX)
            {
                *(int32_t *)dest = (int32_t)real_val;
            }
            else
            {
                return ERR_ECO_INVALIDARG;
            }
        }
        break;
        case type_double:
            if (*(double *)value >= INT32_MIN && *(double *)value <= INT32_MAX)
            {
                *(int32_t *)dest = (int32_t)*(double *)value;
            }
            else
            {
            }
            break;
        case type_single:
            if (*(float *)value >= INT32_MIN && *(float *)value <= INT32_MAX)
            {
                *(int32_t *)dest = (int32_t)*(float *)value;
            }
            else
            {
                return ERR_ECO_INVALIDARG;
            }
            break;
        case type_int8:
            *(int32_t *)dest = (int32_t)*(int8_t *)value;
            break;
        case type_int16:
            *(int32_t *)dest = (int32_t)*(int16_t *)value;
            break;
        case type_int32:
            *(int32_t *)dest = *(int32_t *)value;
            break;
        case type_uint8:
            *(int32_t *)dest = (int32_t)*(uint8_t *)value;
            break;
        case type_uint16:
            *(int32_t *)dest = (int32_t)*(uint16_t *)value;
            break;
        case type_uint32:
            if (*(uint32_t *)value <= INT32_MAX)
            {
                *(int32_t *)dest = (int32_t)*(uint32_t *)value;
            }
            else
            {
                return ERR_ECO_INVALIDARG;
            }
            break;
        case type_logical:
            *(int32_t *)dest = *(int8_t *)value ? 1 : 0;
            break;
        default:
            return ERR_ECO_INVALIDARG;
        }
        break;
    }

    case type_uint8:
    {
        switch (valueType)
        {
        case type_complex:
        {
            double real_val = (*(EcoComplex *)value).real;
            if (real_val >= 0 && real_val <= UINT8_MAX)
            {
                *(uint8_t *)dest = (uint8_t)real_val;
            }
            else
            {
                return ERR_ECO_INVALIDARG;
            }
        }
        break;
        case type_double:
            if (*(double *)value >= 0 && *(double *)value <= UINT8_MAX)
            {
                *(uint8_t *)dest = (uint8_t)*(double *)value;
            }
            else
            {
                return ERR_ECO_INVALIDARG;
            }
            break;
        case type_single:
            if (*(float *)value >= 0 && *(float *)value <= UINT8_MAX)
            {
                *(uint8_t *)dest = (uint8_t)*(float *)value;
            }
            else
            {
                return ERR_ECO_INVALIDARG;
            }
            break;
        case type_int8:
            if (*(int8_t *)value >= 0)
            {
                *(uint8_t *)dest = (uint8_t)*(int8_t *)value;
            }
            else
            {
                return ERR_ECO_INVALIDARG;
            }
            break;
        case type_int16:
            if (*(int16_t *)value >= 0 && *(int16_t *)value <= UINT8_MAX)
            {
                *(uint8_t *)dest = (uint8_t)*(int16_t *)value;
            }
            else
            {
                return ERR_ECO_INVALIDARG;
            }
            break;
        case type_int32:
            if (*(int32_t *)value >= 0 && *(int32_t *)value <= UINT8_MAX)
            {
                *(uint8_t *)dest = (uint8_t)*(int32_t *)value;
            }
            else
            {
                return ERR_ECO_INVALIDARG;
            }
            break;
        case type_uint8:
            *(uint8_t *)dest = *(uint8_t *)value;
            break;
        case type_uint16:
            if (*(uint16_t *)value <= UINT8_MAX)
            {
                *(uint8_t *)dest = (uint8_t)*(uint16_t *)value;
            }
            else
            {
                return ERR_ECO_INVALIDARG;
            }
            break;
        case type_uint32:
            if (*(uint32_t *)value <= UINT8_MAX)
            {
                *(uint8_t *)dest = (uint8_t)*(uint32_t *)value;
            }
            else
            {
                return ERR_ECO_INVALIDARG;
            }
            break;
        case type_logical:
            *(uint8_t *)dest = *(int8_t *)value ? 1 : 0;
            break;
        default:
            return ERR_ECO_INVALIDARG;
        }
        break;
    }

    case type_uint16:
    {
        switch (valueType)
        {
        case type_complex:
        {
            double real_val = (*(EcoComplex *)value).real;
            if (real_val >= 0 && real_val <= UINT16_MAX)
            {
                *(uint16_t *)dest = (uint16_t)real_val;
            }
            else
            {
                return ERR_ECO_INVALIDARG;
            }
        }
        break;
        case type_double:
            if (*(double *)value >= 0 && *(double *)value <= UINT16_MAX)
            {
                *(uint16_t *)dest = (uint16_t)*(double *)value;
            }
            else
            {
                return ERR_ECO_INVALIDARG;
            }
            break;
        case type_single:
            if (*(float *)value >= 0 && *(float *)value <= UINT16_MAX)
            {
                *(uint16_t *)dest = (uint16_t)*(float *)value;
            }
            else
            {
                return ERR_ECO_INVALIDARG;
            }
            break;
        case type_int8:
            if (*(int8_t *)value >= 0)
            {
                *(uint16_t *)dest = (uint16_t)*(int8_t *)value;
            }
            else
            {
                return ERR_ECO_INVALIDARG;
            }
            break;
        case type_int16:
            if (*(int16_t *)value >= 0)
            {
                *(uint16_t *)dest = (uint16_t)*(int16_t *)value;
            }
            else
            {
                return ERR_ECO_INVALIDARG;
            }
            break;
        case type_int32:
            if (*(int32_t *)value >= 0 && *(int32_t *)value <= UINT16_MAX)
            {
                *(uint16_t *)dest = (uint16_t)*(int32_t *)value;
            }
            else
            {
                return ERR_ECO_INVALIDARG;
            }
            break;
        case type_uint8:
            *(uint16_t *)dest = (uint16_t)*(uint8_t *)value;
            break;
        case type_uint16:
            *(uint16_t *)dest = *(uint16_t *)value;
            break;
        case type_uint32:
            if (*(uint32_t *)value <= UINT16_MAX)
            {
                *(uint16_t *)dest = (uint16_t)*(uint32_t *)value;
            }
            else
            {
                return ERR_ECO_INVALIDARG;
            }
            break;
        case type_logical:
            *(uint16_t *)dest = *(int8_t *)value ? 1 : 0;
            break;
        default:
            return ERR_ECO_INVALIDARG;
        }
        break;
    }

    case type_uint32:
    {
        switch (valueType)
        {
        case type_complex:
        {
            double real_val = (*(EcoComplex *)value).real;
            if (real_val >= 0 && real_val <= UINT32_MAX)
            {
                *(uint32_t *)dest = (uint32_t)real_val;
            }
            else
            {
                return ERR_ECO_INVALIDARG;
            }
        }
        break;
        case type_double:
            if (*(double *)value >= 0 && *(double *)value <= UINT32_MAX)
            {
                *(uint32_t *)dest = (uint32_t)*(double *)value;
            }
            else
            {
                return ERR_ECO_INVALIDARG;
            }
            break;
        case type_single:
            if (*(float *)value >= 0 && *(float *)value <= UINT32_MAX)
            {
                *(uint32_t *)dest = (uint32_t)*(float *)value;
            }
            else
            {
                return ERR_ECO_INVALIDARG;
            }
            break;
        case type_int8:
            if (*(int8_t *)value >= 0)
            {
                *(uint32_t *)dest = (uint32_t)*(int8_t *)value;
            }
            else
            {
                return ERR_ECO_INVALIDARG;
            }
            break;
        case type_int16:
            if (*(int16_t *)value >= 0)
            {
                *(uint32_t *)dest = (uint32_t)*(int16_t *)value;
            }
            else
            {
                return ERR_ECO_INVALIDARG;
            }
            break;
        case type_int32:
            if (*(int32_t *)value >= 0)
            {
                *(uint32_t *)dest = (uint32_t)*(int32_t *)value;
            }
            else
            {
                return ERR_ECO_INVALIDARG;
            }
            break;
        case type_uint8:
            *(uint32_t *)dest = (uint32_t)*(uint8_t *)value;
            break;
        case type_uint16:
            *(uint32_t *)dest = (uint32_t)*(uint16_t *)value;
            break;
        case type_uint32:
            *(uint32_t *)dest = *(uint32_t *)value;
            break;
        case type_logical:
            *(uint32_t *)dest = *(int8_t *)value ? 1 : 0;
            break;
        default:
            return ERR_ECO_INVALIDARG;
        }
        break;
    }

    case type_logical:
    {
        switch (valueType)
        {
        case type_complex:
            *(int8_t *)dest = ((*(EcoComplex *)value).real != 0.0) || ((*(EcoComplex *)value).imag != 0.0);
            break;
        case type_double:
            *(int8_t *)dest = (*(double *)value != 0.0);
            break;
        case type_single:
            *(int8_t *)dest = (*(float *)value != 0.0f);
            break;
        case type_int8:
            *(int8_t *)dest = (*(int8_t *)value != 0);
            break;
        case type_int16:
            *(int8_t *)dest = (*(int16_t *)value != 0);
            break;
        case type_int32:
            *(int8_t *)dest = (*(int32_t *)value != 0);
            break;
        case type_uint8:
            *(int8_t *)dest = (*(uint8_t *)value != 0);
            break;
        case type_uint16:
            *(int8_t *)dest = (*(uint16_t *)value != 0);
            break;
        case type_uint32:
            *(int8_t *)dest = (*(uint32_t *)value != 0);
            break;
        case type_logical:
            *(int8_t *)dest = *(int8_t *)value;
            break;
        default:
            return ERR_ECO_INVALIDARG;
        }
        break;
    }

    default:
        return ERR_ECO_INVALIDARG;
    }

    return ERR_ECO_SUCCESES;
}

static uint32_t ECOCALLMETHOD CEcoVector_GetSize(/* in */ IEcoVectorPtr_t me)
{
    CEcoVector *pCMe = (CEcoVector *)me;
    if (me == 0)
    {
        return 0; /* ERR_ECO_POINTER */
    }
    return pCMe->m_Size;
}

static EcoDataType_e ECOCALLMETHOD CEcoVector_GetType(/* in */ IEcoVectorPtr_t me)
{
    CEcoVector *pCMe = (CEcoVector *)me;
    if (me == 0)
    {
        return 0; /* ERR_ECO_POINTER */
    }
    return pCMe->m_Type;
}

static IEcoVector *ECOCALLMETHOD CEcoVector_NewVector(/* in */ IEcoVectorPtr_t me, /* in */ EcoDataType_e type, /* in */ uint32_t size)
{
    CEcoVector *pCMe = (CEcoVector *)me;
    IEcoVector *pIVector = 0;
    CEcoVector *pVec = 0;
    size_t elemSize = 0;
    /* Проверка аргументов */
    if (me == 0 || pCMe->m_pIMem == 0)
    {
        return 0;
    }

    /* Определяем размер одного элемента */
    switch (type)
    {
    case type_complex:
        elemSize = sizeof(EcoComplex);
        break;
    case type_double:
        elemSize = sizeof(double);
        break;
    case type_single:
        elemSize = sizeof(float);
        break;
    case type_int8:
        elemSize = sizeof(char);
        break;
    case type_int16:
        elemSize = sizeof(int16_t);
        break;
    case type_int32:
        elemSize = sizeof(int32_t);
        break;
    case type_uint8:
        elemSize = sizeof(int8_t);
        break;
    case type_uint16:
        elemSize = sizeof(uint16_t);
        break;
    case type_uint32:
        elemSize = sizeof(uint32_t);
        break;
    case type_logical:
        elemSize = sizeof(int16_t);
        break;
    default:
        return 0;
    }
    /* Создаём экземпляр CEcoVector */
    if (createCEcoVector((IEcoUnknown *)pCMe->m_pISys, 0, &pIVector) != 0 || pIVector == 0)
    {
        return 0;
    }

    /* Инициализация состояния вектора */
    pVec = (CEcoVector *)pIVector;
    pVec->m_Type = type;
    pVec->m_ElementSize = elemSize;
    pVec->m_Size = size;

    /* Выделяем память под данные */
    pVec->m_pData = pVec->m_pIMem->pVTbl->Alloc(pVec->m_pIMem, elemSize * size);
    if (pVec->m_pData == 0)
    {
        pIVector->pVTbl->Release(pIVector);
        return 0;
    }
    return pIVector;
}



/* Виртуальная таблица IEcoLab1 */
IEcoLab1VTbl g_x277FC00C35624096AFCFC125B94EEC90VTbl = {
    CEcoLab1_QueryInterface,
    CEcoLab1_AddRef,
    CEcoLab1_Release,
    CEcoLab1_FFT_Vector
};

/* Виртуальная таблица IEcoCalculatorY */
IEcoCalculatorYVTbl g_xBD6414C29096423EA90C04D77AFD1CADVTbl = {
    CEcoLab1_IEcoCalculatorY_QueryInterface,
    CEcoLab1_IEcoCalculatorY_AddRef,
    CEcoLab1_IEcoCalculatorY_Release,
    CEcoLab1_IEcoCalculatorY_Multiplication,
    CEcoLab1_IEcoCalculatorY_Division
};

/* Виртуальная таблица IEcoCalculatorX */
IEcoCalculatorXVTbl g_x9322111622484742AE0682819447843DVTbl = {
    CEcoLab1_IEcoCalculatorX_QueryInterface,
    CEcoLab1_IEcoCalculatorX_AddRef,
    CEcoLab1_IEcoCalculatorX_Release,
    CEcoLab1_IEcoCalculatorX_Addition,
    CEcoLab1_IEcoCalculatorX_Subtraction
};

IEcoVectorVTbl g_x2D7CF91456894BE2831ABE05729C48F6VTbl = {
    (int16_t(ECOCALLMETHOD *)(IEcoVectorPtr_t, const UGUID *, voidptr_t *))CEcoLab1_QueryInterface,
    (uint32_t(ECOCALLMETHOD *)(IEcoVectorPtr_t))CEcoLab1_AddRef,
    (uint32_t(ECOCALLMETHOD *)(IEcoVectorPtr_t))CEcoLab1_Release,
    CEcoVector_NewVector,
    CEcoVector_Set,
    CEcoVector_Get,
    CEcoVector_GetSize,
    CEcoVector_GetType
};

/* Create Virtual Table IEcoNondelegatingUnknown */
IEcoUnknownVTbl g_x000000000000000000000000000000AAVTblUnk = {
    CEcoLab1_NondelegatingQueryInterface,
    CEcoLab1_NondelegatingAddRef,
    CEcoLab1_NondelegatingRelease
};

/*
 *
 * <сводка>
 *   Функция Create
 * </сводка>
 *
 * <описание>
 *   Функция создания экземпляра
 * </описание>
 *
 */
int16_t ECOCALLMETHOD createCEcoLab1(/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* out */ IEcoLab1Ptr_t* ppIEcoLab1){   
    int16_t result = -1;
    IEcoSystem1* pISys = 0;
    IEcoInterfaceBus1* pIBus = 0;
    IEcoInterfaceBus1MemExt* pIMemExt = 0;
    IEcoMemoryAllocator1* pIMem = 0;
    CEcoLab1* pCMe = 0;
    UGUID* rcid = (UGUID*)&CID_EcoMemoryManager1;
	
    /* Проверка указателей */
    if ( ppIEcoLab1 == 0 || pIUnkSystem == 0 ) {
        return result; /* ERR_ECO_POINTER */
    }
    /* Получение системного интерфейса приложения */
    result = pIUnkSystem->pVTbl->QueryInterface(pIUnkSystem, &GID_IEcoSystem, (void **)&pISys);

    /* Проверка */
    if (result != 0 && pISys == 0)
    {
        return result;
    }

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pISys->pVTbl->QueryInterface(pISys, &IID_IEcoInterfaceBus1, (void **)&pIBus);

    /* Получение идентификатора компонента для работы с памятью */
    result = pIBus->pVTbl->QueryInterface(pIBus, &IID_IEcoInterfaceBus1MemExt, (void **)&pIMemExt);
    if (result == 0 && pIMemExt != 0)
    {
        rcid = (UGUID *)pIMemExt->pVTbl->get_Manager(pIMemExt);
        pIMemExt->pVTbl->Release(pIMemExt);
    }

    /* Получение интерфейса распределителя памяти */
    result = pIBus->pVTbl->QueryComponent(pIBus, rcid, 0, &IID_IEcoMemoryAllocator1, (voidptr_t*) &pIMem);

        /* Проверка */
    if (result != 0 && pIMem == 0)
    {
        /* Освобождение системного интерфейса в случае ошибки */
        pISys->pVTbl->Release(pISys);
        return result;
    }

    /* Выделение памяти для данных экземпляра */
    pCMe = (CEcoLab1*)pIMem->pVTbl->Alloc(pIMem, sizeof(CEcoLab1));

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = pISys;

    /* Сохранение указателя на интерфейс для работы с памятью */
    pCMe->m_pIMem = pIMem;

    /* Установка счетчика ссылок на компонент */
    pCMe->m_cRef = 1;

    /* Создание таблицы функций интерфейса IEcoLab1 */
    pCMe->m_pVTblIEcoLab1 = &g_x277FC00C35624096AFCFC125B94EEC90VTbl;
    pCMe->m_pVTblX = &g_x9322111622484742AE0682819447843DVTbl;
    pCMe->m_pVTblY = &g_xBD6414C29096423EA90C04D77AFD1CADVTbl;
    pCMe->m_pVTblIEcoVector = &g_x2D7CF91456894BE2831ABE05729C48F6VTbl;
    pCMe->m_pVTblINondelegatingUnk = &g_x000000000000000000000000000000AAVTblUnk;

    pCMe->m_pIX = 0;
    pCMe->m_pIY = 0;
    pCMe->m_pInnerUnknown = 0;

    pCMe->m_pIUnkOuter = 0;

    /* Если не агрегируется, использовать неделигирующий интерфейс IEcoUnknown */
    if (pIUnkOuter != 0) {
        pCMe->m_pIUnkOuter = pIUnkOuter;
        *ppIEcoLab1 = (IEcoLab1*)&pCMe->m_pVTblINondelegatingUnk;
    } else {
        pCMe->m_pIUnkOuter = (IEcoUnknown*)&pCMe->m_pVTblINondelegatingUnk;
        *ppIEcoLab1 = (IEcoLab1*)pCMe;
    }

    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoCalculatorD, 0, &IID_IEcoCalculatorY, (void**) &pCMe->m_pIY);
    if ( result != 0 || pCMe->m_pIY == 0 ) {
        result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoCalculatorE, 0, &IID_IEcoCalculatorY, (void**) &pCMe->m_pIY);
	}
	result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoCalculatorB, (IEcoUnknown*)pCMe, &IID_IEcoUnknown, (void**) &pCMe->m_pInnerUnknown);
    if ( result != 0 || pCMe->m_pInnerUnknown == 0 ) {
        result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoCalculatorA, 0, &IID_IEcoCalculatorX, (void**) &pCMe->m_pIX);
    }

    /* Освобождение */
    pIBus->pVTbl->Release(pIBus);

    return ERR_ECO_SUCCESES;
}

/*
 *
 * <сводка>
 *   Функция Delete
 * </сводка>
 *
 * <описание>
 *   Функция освобождения экземпляра
 * </описание>
 *
 */
void ECOCALLMETHOD deleteCEcoLab1(/* in */ IEcoLab1Ptr_t pIEcoLab1) {
    CEcoLab1* pCMe = (CEcoLab1*)pIEcoLab1;
    IEcoMemoryAllocator1* pIMem = 0;

    if ( pIEcoLab1 != 0 ) {
        pIMem = pCMe->m_pIMem;
        /* Освобождение */
        if ( pCMe->m_pIX != 0 ) {
            pCMe->m_pIX->pVTbl->Release(pCMe->m_pIX);
        }
        if ( pCMe->m_pIY != 0 ) {
            pCMe->m_pIY->pVTbl->Release(pCMe->m_pIY);
        }
        if ( pCMe->m_pISys != 0 ) {
            pCMe->m_pISys->pVTbl->Release(pCMe->m_pISys);
        }
        pIMem->pVTbl->Free(pIMem, pCMe);
        pIMem->pVTbl->Release(pIMem);
    }
}

/*
 *
 * <сводка>
 *   Функция Init
 * </сводка>
 *
 * <описание>
 *   Функция инициализации экземпляра
 * </описание>
 *
 */
int16_t ECOCALLMETHOD initCEcoVector(/*in*/ IEcoVectorPtr_t me, /* in */ struct IEcoUnknown *pIUnkSystem)
{
    CEcoVector *pCMe = (CEcoVector *)me;
    IEcoInterfaceBus1 *pIBus = 0;
    int16_t result = -1;
    /* Проверка указателей */
    if (me == 0)
    {
        return result;
    }

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = (IEcoSystem1 *)pIUnkSystem;

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pCMe->m_pISys->pVTbl->QueryInterface(pCMe->m_pISys, &IID_IEcoInterfaceBus1, (void **)&pIBus);

    /* Проверка указателей */
    if (me == 0)
    {
        return result;
    }

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = (IEcoSystem1 *)pIUnkSystem;

    /* Освобождение */
    pIBus->pVTbl->Release(pIBus);

    return result;
}

/*
 *
 * <сводка>
 *   Функция Create
 * </сводка>
 *
 * <описание>
 *   Функция создания экземпляра
 * </описание>
 *
 */
int16_t ECOCALLMETHOD createCEcoVector(/* in */ IEcoUnknown *pIUnkSystem, /* in */ IEcoUnknown *pIUnkOuter, /* out */ IEcoVector **ppIEcoVector)
{
    int16_t result = -1;
    IEcoSystem1 *pISys = 0;
    IEcoInterfaceBus1 *pIBus = 0;
    IEcoInterfaceBus1MemExt *pIMemExt = 0;
    IEcoMemoryAllocator1 *pIMem = 0;
    CEcoVector *pCMe = 0;
    UGUID *rcid = (UGUID *)&CID_EcoMemoryManager1;

    /* Проверка указателей */
    if (ppIEcoVector == 0 || pIUnkSystem == 0)
    {
        return result;
    }

    pISys = ((IEcoSystem1*)pIUnkSystem);
    /* Получение системного интерфейса приложения */
    // result = pIUnkSystem->pVTbl->QueryInterface(pIUnkSystem, &GID_IEcoSystem1, (void **)&pISys);

    /* Проверка */
    if (result != 0 && pISys == 0)
    {
        return result;
    }

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pISys->pVTbl->QueryInterface(pISys, &IID_IEcoInterfaceBus1, (void **)&pIBus);

    /* Получение идентификатора компонента для работы с памятью */
    result = pIBus->pVTbl->QueryInterface(pIBus, &IID_IEcoInterfaceBus1MemExt, (void **)&pIMemExt);
    if (result == 0 && pIMemExt != 0)
    {
        rcid = (UGUID *)pIMemExt->pVTbl->get_Manager(pIMemExt);
        pIMemExt->pVTbl->Release(pIMemExt);
    }

    /* Получение интерфейса распределителя памяти */
    pIBus->pVTbl->QueryComponent(pIBus, rcid, 0, &IID_IEcoMemoryAllocator1, (void **)&pIMem);

    /* Проверка */
    if (result != 0 && pIMem == 0)
    {
        /* Освобождение системного интерфейса в случае ошибки */
        pISys->pVTbl->Release(pISys);
        return result;
    }

    /* Выделение памяти для данных экземпляра */
    pCMe = (CEcoVector *)pIMem->pVTbl->Alloc(pIMem, sizeof(CEcoVector));

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = pISys;

    /* Сохранение указателя на интерфейс для работы с памятью */
    pCMe->m_pIMem = pIMem;

    /* Установка счетчика ссылок на компонент */
    pCMe->m_cRef = 1;

    /* Создание таблицы функций интерфейса IEcoVector */
    pCMe->m_pVTblIEcoVector = &g_x2D7CF91456894BE2831ABE05729C48F6VTbl;

    /* Инициализация данных */
    pCMe->m_Size = 0;
    pCMe->m_Type = 0;
    pCMe->m_ElementSize = 0;
    pCMe->m_pData = 0;

    /* Возврат указателя на интерфейс */
    *ppIEcoVector = (IEcoVector *)pCMe;

    /* Освобождение */
    pIBus->pVTbl->Release(pIBus);

    return 0;
}

/*
 *
 * <сводка>
 *   Функция Delete
 * </сводка>
 *
 * <описание>
 *   Функция освобождения экземпляра
 * </описание>
 *
 */
void ECOCALLMETHOD deleteCEcoVector(/* in */ IEcoVector *pIEcoVector)
{
    CEcoVector *pCMe = (CEcoVector *)pIEcoVector;
    IEcoMemoryAllocator1 *pIMem = 0;

    if (pIEcoVector != 0)
    {
        pIMem = pCMe->m_pIMem;

        if (pCMe->m_pData != 0)
        {
            pIMem->pVTbl->Free(pIMem, pCMe->m_pData);
        }

        pIMem->pVTbl->Free(pIMem, pCMe);
        pIMem->pVTbl->Release(pIMem);
    }
}

