/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   EcoLab1
 * </сводка>
 *
 * <описание>
 *   Данный исходный файл является точкой входа
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */


/* Eco OS */
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"
#include "IdEcoInterfaceBus1.h"
#include "IdEcoFileSystemManagement1.h"
#include "IdEcoLab1.h"
#include "EcoLabDefines.h"
#include "fftw3.h"
#include "complex.h"
#include "time.h"
#include <stdio.h>

#include "IdEcoLab1.h"
#include "CEcoVector.h"
#include "CEcoLab1.h"

void measureFFTW(uint32_t size)
{
    fftw_complex *in, *out;
    fftw_plan p;
    clock_t start = 0;
    clock_t end = 0;
    double total_time = 0;

    in = (fftw_complex *)fftw_malloc(sizeof(fftw_complex) * size);
    out = (fftw_complex *)fftw_malloc(sizeof(fftw_complex) * size);

    p = fftw_plan_dft_1d(size, in, out, FFTW_FORWARD, FFTW_ESTIMATE);

    for (int i = 0; i < size; i++)
    {
        in[i][0] = i;
        in[i][1] = 0;
    }

    start = clock();
    fftw_execute(p);
    end = clock();
    total_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("fftw time is %lf\n", total_time);

    fftw_destroy_plan(p);
    fftw_free(in);
    fftw_free(out);
}

void measureEcoFFT(uint32_t size, IEcoVectorPtr_t pIEcoVector, IEcoLab1Ptr_t pIEcoLab1)
{
    IEcoVector *SourceVector = 0, *ResultVector = 0;
    int16_t result = -1;
    clock_t start = 0;
    clock_t end = 0;
    double total_time = 0;
    SourceVector = pIEcoVector->pVTbl->NewVector(pIEcoVector, type_double, size);
    printf("%x %x\n", SourceVector, ResultVector);
    if (SourceVector == 0)
    {
        goto Release2;
    }

    for (int i = 0; i < size; i++)
    {
        int cu = i;
        result = pIEcoVector->pVTbl->Set(SourceVector, i, &cu, type_int32);
        if (result != 0)
        {
            goto Release2;
        }
    }

    start = clock();
    result = pIEcoLab1->pVTbl->FFT_Vector(pIEcoLab1, SourceVector, &ResultVector);
    end = clock();
    total_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    if (size == 8)
    {
        EcoComplex tmp;
        printf("source vector:\n");
        for (int i = 0; i < size; i++)
        {
            result = SourceVector->pVTbl->Get(SourceVector, i, &tmp, type_complex);
            printf("%lf %lf\n", tmp.real, tmp.imag);
        }

        printf("result vector:\n");
        for (int i = 0; i < size; i++)
        {
            result = SourceVector->pVTbl->Get(ResultVector, i, &tmp, type_complex);
            printf("%lf %lf\n", tmp.real, tmp.imag);
        }
    }

    printf("EcoFFT time is %lf\n", total_time);

    if (result != 0)
    {
        printf("error in fft %d", result);
        goto Release2;
    }

Release2:
    if (SourceVector != 0)
    {
        deleteCEcoVector(SourceVector);
    }
    if (ResultVector != 0)
    {
        deleteCEcoVector(ResultVector);
    }
}

void checkEcoFFT(uint32_t size, IEcoVectorPtr_t pIEcoVector, IEcoLab1Ptr_t pIEcoLab1)
{

    fftw_complex *in, *out;
    fftw_plan p;
    EcoComplex tmp;
    IEcoVector *SourceVector = 0, *ResultVector = 0;
    int16_t result = -1;

    SourceVector = pIEcoVector->pVTbl->NewVector(pIEcoVector, type_double, size);
    if (SourceVector == 0)
    {
        goto Release3;
    }

    for (int i = 0; i < size; i++)
    {
        int cu = i;
        result = pIEcoVector->pVTbl->Set(SourceVector, i, &cu, type_int32);
        if (result != 0)
        {
            goto Release3;
        }
    }

    result = pIEcoLab1->pVTbl->FFT_Vector(pIEcoLab1, SourceVector, &ResultVector);
    if (result != 0)
    {
        printf("error in fft %d", result);
        goto Release3;
    }

    in = (fftw_complex *)fftw_malloc(sizeof(fftw_complex) * size);
    out = (fftw_complex *)fftw_malloc(sizeof(fftw_complex) * size);

    p = fftw_plan_dft_1d(size, in, out, FFTW_FORWARD, FFTW_ESTIMATE);

    for (int i = 0; i < size; i++)
    {
        in[i][0] = i;
        in[i][1] = 0;
    }

    fftw_execute(p);


    for (int i = 0; i < size; i++)
    {
        result = pIEcoVector->pVTbl->Get(ResultVector, i, &tmp, type_complex);
        if (abs(tmp.real - out[i][0])/tmp.real>0.01 || abs(tmp.imag - out[i][1])/tmp.real > 0.01){
            printf("%lf %lf %lf %lf\n",tmp.real, out[i][0], tmp.imag, out[i][1]);
            assert(0);
        }
        
    }



Release3:
    fftw_destroy_plan(p);
    fftw_free(in);
    fftw_free(out);
    if (SourceVector != 0)
    {
        deleteCEcoVector(SourceVector);
    }
    if (ResultVector != 0)
    {
        deleteCEcoVector(ResultVector);
    }
}

/*
 *
 * <сводка>
 *   Функция EcoMain
 * </сводка>
 *
 * <описание>
 *   Функция EcoMain - точка входа
 * </описание>
 *
 */
int16_t EcoMain(IEcoUnknown* pIUnk) {
    int16_t result = -1;
    /* Указатель на системный интерфейс */
    IEcoSystem1* pISys = 0;
    /* Указатель на интерфейс работы с системной интерфейсной шиной */
    IEcoInterfaceBus1* pIBus = 0;
    /* Указатель на интерфейс работы с памятью */
    IEcoMemoryAllocator1* pIMem = 0;
    /* Указатели на тестируемые интерфейсы IEcoLab1 */
    IEcoLab1 *pIEcoLab1 = 0, *pOtherIEcoLab1 = 0;
    IEcoVector *pIEcoVector = 0;
    uint32_t size = 1;
    uint32_t max_size = 1 << 15;
    uint32_t max_check_size = 1 << 4;
    
    /* Проверка и создание системного интрефейса */
    if (pISys == 0) {
        result = pIUnk->pVTbl->QueryInterface(pIUnk, &GID_IEcoSystem, (void **)&pISys);
        if (result != 0 && pISys == 0) {
        /* Освобождение системного интерфейса в случае ошибки */
            goto Release;
        }
    }

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pISys->pVTbl->QueryInterface(pISys, &IID_IEcoInterfaceBus1, (void **)&pIBus);
    if (result != 0 || pIBus == 0) {
        /* Освобождение в случае ошибки */
        goto Release;
    }

#ifdef ECO_LIB
    /* Регистрация статического компонента для работы со списком */
    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoLab1, (IEcoUnknown*)GetIEcoComponentFactoryPtr_1F5DF16EE1BF43B999A434ED38FE8F3A);
    
    if (result != 0 ) {
        /* Освобождение в случае ошибки */
        goto Release;
    }
#endif

    /* Получение интерфейса управления памятью */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoMemoryManager1, 0, &IID_IEcoMemoryAllocator1, (void**) &pIMem);

    /* Проверка */
    if (result != 0 || pIMem == 0) {
        /* Освобождение системного интерфейса в случае ошибки */
        goto Release;
    }
    /* Получение тестируемого интерфейса */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoLab1, 0, &IID_IEcoLab1, (void**) &pIEcoLab1);
    if (result != 0 || pIEcoLab1 == 0) {
        printf("%d", result);
        /* Освобождение интерфейсов в случае ошибки */
        goto Release;
    }
    result = pIEcoLab1->pVTbl->QueryInterface(pIEcoLab1, &IID_IEcoVector, (void **)&pIEcoVector);
    if (result != 0 || pIEcoVector == 0)
    {
        /* Освобождение интерфейсов в случае ошибки */
        goto Release;
    }

    while (size < max_size)
    {
        printf("size is %d\n", size);
        measureFFTW(size);
        measureEcoFFT(size, pIEcoVector, pIEcoLab1);
        size <<= 1;
    }
    size = 1;
    while (size < max_check_size){
        printf("size %ld max size  %ld\n",size, max_check_size);
        checkEcoFFT(size, pIEcoVector, pIEcoLab1);
        size <<=1;
    }

Release:

    /* Освобождение интерфейса для работы с интерфейсной шиной */
    if (pIBus != 0) pIBus->pVTbl->Release(pIBus);

    /* Освобождение интерфейса работы с памятью */
    if (pIMem != 0) pIMem->pVTbl->Release(pIMem);

    /* Освобождение тестируемого интерфейса */
    if (pIEcoLab1 != 0) pIEcoLab1->pVTbl->Release(pIEcoLab1);

    /* Освобождение системного интерфейса */
    if (pISys != 0) pISys->pVTbl->Release(pISys);

    return result;
}
