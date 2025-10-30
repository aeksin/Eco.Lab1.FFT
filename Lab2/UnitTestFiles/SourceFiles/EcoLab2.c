/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   EcoLab2
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
#include "IdEcoLab2.h"

#include "IEcoLab1.h"
#include "IdEcoLab1.h"

#include "IEcoCalculatorX.h"
#include "IEcoCalculatorY.h"
#include "IdEcoCalculatorA.h"
#include "IdEcoCalculatorB.h"
#include "IdEcoCalculatorD.h"
#include "IdEcoCalculatorE.h"

#include <stdio.h>

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
    
    /* Указатели на тестируемые интерфейсы */
    IEcoLab2 *pIEcoLab2 = 0, *pIEcoLab2_2 = 0;
    IEcoCalculatorX *pIX = 0, *pIX_2 = 0;
    IEcoCalculatorY *pIY = 0, *pIY_2 = 0;
    IEcoLab1 *pIEcoLab1 = 0, *pIEcoLab1_2 = 0;
    /* Указатель на неизвестный интерфейс */
    IEcoUnknown *pIUnknown = 0, *pIUnknown_2 = 0;

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
    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoLab2, (IEcoUnknown*)GetIEcoComponentFactoryPtr_D42A9B8EF376491CB32985C1F3A6E0B4);
    if (result != 0 ) {
        /* Освобождение в случае ошибки */
        goto Release;
    }
	result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoLab1, (IEcoUnknown*)GetIEcoComponentFactoryPtr_5B7DD38BA68441A7A64BFB30D47FE35B);
    if ( result != 0 ) {
        /* Освобождение в случае ошибки */
        goto Release;
    }
    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoCalculatorA, (IEcoUnknown*)GetIEcoComponentFactoryPtr_4828F6552E4540E78121EBD220DC360E);
    if ( result != 0 ) {
        /* Освобождение в случае ошибки */
        goto Release;
    }
    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoCalculatorB, (IEcoUnknown*)GetIEcoComponentFactoryPtr_AE202E543CE54550899603BD70C62565);
    if ( result != 0 ) {
        /* Освобождение в случае ошибки */
        goto Release;
    }
    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoCalculatorD, (IEcoUnknown*)GetIEcoComponentFactoryPtr_3A8E44677E82475CB4A3719ED8397E61);
    if ( result != 0 ) {
        /* Освобождение в случае ошибки */
        goto Release;
    }
    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoCalculatorE, (IEcoUnknown*)GetIEcoComponentFactoryPtr_872FEF1DE3314B87AD44D1E7C232C2F0);
    if ( result != 0 ) {
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
        printf("ошибка при запросе компонента EcoLab1\n");
        /* Освобождение интерфейсов в случае ошибки */
        goto Release;
    }



    uint32_t successful = 0;
    uint32_t unsuccessful = 0;

    printf("Тестирование механизма включения/агрегирования для компонента EcoLab1\n");

    
    printf("\n");
    if (pIEcoLab1->pVTbl->QueryInterface(pIEcoLab1, &IID_IEcoUnknown, (void**)&pIUnknown) == 0 && pIUnknown) {
        printf("Запрос интерфейса IEcoUnknown через интерфейс IEcoLab1 успешен\n\n");

        if (pIUnknown->pVTbl->QueryInterface(pIUnknown, &IID_IEcoCalculatorX, (void**)&pIX_2) == 0 && pIX_2) {
            printf("Запрос интерфейса IEcoCalculatorX через интерфейс IEcoUnknown успешен\n");
            if (pIX_2->pVTbl->Addition(pIX_2, 1, 2) == 1+2){
                printf("результат сложения через интерфейс совпадает с результатом обычного сложения: 1 + 2 = %d\n",pIX_2->pVTbl->Addition(pIX_2, 1, 2));
            }
            if (pIX_2->pVTbl->Subtraction(pIX_2, 7, 3) == 7-3){
                printf("результат вычитания через интерфейс совпадает с результатом обычного вычитания: 7 - 3 = %d\n",pIX_2->pVTbl->Subtraction(pIX_2, 7, 3));
            }
            pIX_2->pVTbl->Release(pIX_2);
            successful++;
        } else {
            printf("ошибка при запросе интерфейса IEcoCalculatorX через интерфейс IEcoUnknown\n");
            unsuccessful++;
        }

        if (pIUnknown->pVTbl->QueryInterface(pIUnknown, &IID_IEcoCalculatorY, (void**)&pIY_2) == 0 && pIY_2) {
            printf("Запрос интерфейса IEcoCalculatorY через интерфейс IEcoUnknown успешен\n");
            if (pIY_2->pVTbl->Multiplication(pIY_2, 4, 7) == 28){
                printf("результат умножения через интерфейс совпадает с результатом обычного умножения: 4 * 7 = %d\n",pIY_2->pVTbl->Multiplication(pIY_2, 4, 7));
            }
            if (pIY_2->pVTbl->Division(pIY_2, 28, 4) == 7){
                printf("результат деления через интерфейс совпадает с результатом обычного деления: 28 / 4 = %d\n",pIY_2->pVTbl->Division(pIY_2, 28, 4));
            }
            pIY_2->pVTbl->Release(pIY_2);
            successful++;
        } else {
            printf("ошибка при запросе интерфейса IEcoCalculatorY через интерфейс IEcoUnknown\n");
            unsuccessful++;
        }

        result =  pIUnknown->pVTbl->QueryInterface(pIUnknown, &IID_IEcoLab1, (void**)&pIEcoLab1_2);
        if ( result == 0 && pIEcoLab1_2) {
            printf("Запрос интерфейса IEcoLab1 через интерфейс IEcoUnknown успешен\n");
            pIEcoLab1_2->pVTbl->Release(pIEcoLab1_2);
            successful++;
        } else {
            printf("ошибка при запросе интерфейса IEcoLab1 через интерфейс IEcoUnknown\n");
            unsuccessful++;
        }

        result =  pIUnknown->pVTbl->QueryInterface(pIUnknown, &IID_IEcoUnknown, (void**)&pIUnknown_2);
        if ( result == 0 && pIUnknown_2) {
            printf("Запрос интерфейса IEcoUnknown через интерфейс IEcoUnknown успешен\n");
            pIUnknown_2->pVTbl->Release(pIUnknown_2);
            successful++;
        } else {
            printf("ошибка при запросе интерфейса IEcoUnknown через интерфейс IEcoUnknown\n");
            unsuccessful++;
        }

        pIUnknown->pVTbl->Release(pIUnknown);
        successful++;
    } else {
        printf("ошибка при запросе интерфейса IEcoUnknown через интерфейс IEcoLab1\n");
        unsuccessful++;
    }

    printf("\n");
    if (pIEcoLab1->pVTbl->QueryInterface(pIEcoLab1, &IID_IEcoCalculatorX, (void**)&pIX) == 0 && pIX) {
        printf("Запрос интерфейса IEcoCalculatorX через интерфейс IEcoLab1 успешен\n\n");

        if (pIX->pVTbl->Addition(pIX, 1, 2) == 1+2){
            printf("результат сложения через интерфейс совпадает с результатом обычного сложения: 1 + 2 = %d\n",pIX->pVTbl->Addition(pIX, 1, 2));
        }
        if (pIX->pVTbl->Subtraction(pIX, 7, 3) == 7-3){
            printf("результат вычитания через интерфейс совпадает с результатом обычного вычитания: 7 - 3 = %d\n",pIX->pVTbl->Subtraction(pIX, 7, 3));
        }

        if (pIX->pVTbl->QueryInterface(pIX, &IID_IEcoUnknown, (void**)&pIUnknown_2) == 0 && pIUnknown_2) {
            printf("Запрос интерфейса IEcoUnknown через интерфейс IEcoCalculatorX успешен\n");
            pIUnknown_2->pVTbl->Release(pIUnknown_2);
            successful++;
        } else {
            printf("ошибка при запросе интерфейса IEcoUnknown через интерфейс IEcoCalculatorX\n");
            unsuccessful++;
        }

        if (pIX->pVTbl->QueryInterface(pIX, &IID_IEcoCalculatorY, (void**)&pIY_2) == 0 && pIY_2) {
            printf("Запрос интерфейса IEcoCalculatorY через интерфейс IEcoCalculatorX успешен\n");
            if (pIY_2->pVTbl->Multiplication(pIY_2, 4, 7) == 28){
                printf("результат умножения через интерфейс совпадает с результатом обычного умножения: 4 * 7 = %d\n",pIY_2->pVTbl->Multiplication(pIY_2, 4, 7));
            }
            if (pIY_2->pVTbl->Division(pIY_2, 28, 4) == 7){
                printf("результат деления через интерфейс совпадает с результатом обычного деления: 28 / 4 = %d\n",pIY_2->pVTbl->Division(pIY_2, 28, 4));
            }
            pIY_2->pVTbl->Release(pIY_2);
            successful++;
        } else {
            printf("ошибка при запросе интерфейса IEcoCalculatorY через интерфейс IEcoCalculatorX\n");
            unsuccessful++;
        }

        result = pIX->pVTbl->QueryInterface(pIX, &IID_IEcoLab1, (void**)&pIEcoLab1_2);
        if ( result == 0 && pIEcoLab1_2) {
            printf("Запрос интерфейса IEcoLab1 через интерфейс IEcoCalculatorX успешен\n");
            pIEcoLab1_2->pVTbl->Release(pIEcoLab1_2);
            successful++;
        } else {
            printf("ошибка при запросе интерфейса IEcoLab1 через интерфейс IEcoCalculatorX\n");
            unsuccessful++;
        }


        result =  pIX->pVTbl->QueryInterface(pIX, &IID_IEcoCalculatorX, (void**)&pIX_2);
        if ( result == 0 && pIX_2) {
            printf("Запрос интерфейса IEcoCalculatorX через интерфейс IEcoCalculatorX успешен\n");
            pIX_2->pVTbl->Release(pIX_2);
            successful++;
        } else {
            printf("ошибка при запросе интерфейса IEcoCalculatorX через интерфейс IEcoCalculatorX\n");
            unsuccessful++;
        }

        pIX->pVTbl->Release(pIX);
        successful++;
    } else {
        printf("ошибка при запросе интерфейса IEcoCalculatorX через интерфейс IEcoLab2\n");
        unsuccessful++;
    }

    printf("\n");
    if (pIEcoLab1->pVTbl->QueryInterface(pIEcoLab1, &IID_IEcoCalculatorY, (void**)&pIY) == 0 && pIY) {
        printf("Запрос интерфейса IEcoCalculatorY через интерфейс IEcoLab1 успешен\n\n");

        if (pIY->pVTbl->Multiplication(pIY, 4, 7) == 28){
            printf("результат умножения через интерфейс совпадает с результатом обычного умножения: 4 * 7 = %d\n",pIY->pVTbl->Multiplication(pIY_2, 4, 7));
        }
        if (pIY->pVTbl->Division(pIY, 28, 4) == 7){
            printf("результат деления через интерфейс совпадает с результатом обычного деления: 28 / 4 = %d\n",pIY->pVTbl->Division(pIY_2, 28, 4));
        }

        if (pIY->pVTbl->QueryInterface(pIY, &IID_IEcoUnknown, (void**)&pIUnknown_2) == 0 && pIUnknown_2) {
            printf("Запрос интерфейса IEcoUnknown через интерфейс IEcoCalculatorY успешен\n");
            pIUnknown_2->pVTbl->Release(pIUnknown_2);
            successful++;
        } else {
            printf("ошибка при запросе интерфейса IEcoUnknown через интерфейс IEcoCalculatorY\n");
            unsuccessful++;
        }

        if (pIY->pVTbl->QueryInterface(pIY, &IID_IEcoCalculatorX, (void**)&pIX_2) == 0 && pIX_2) {
            printf("Запрос интерфейса IEcoCalculatorX через интерфейс IEcoCalculatorY успешен\n");
            if (pIX_2->pVTbl->Addition(pIX_2, 1, 2) == 1+2){
            printf("результат сложения через интерфейс совпадает с результатом обычного сложения: 1 + 2 = %d\n",pIX_2->pVTbl->Addition(pIX, 1, 2));
            }
            if (pIX_2->pVTbl->Subtraction(pIX_2, 7, 3) == 7-3){
                printf("результат вычитания через интерфейс совпадает с результатом обычного вычитания: 7 - 3 = %d\n",pIX_2->pVTbl->Subtraction(pIX, 7, 3));
            }
            pIX_2->pVTbl->Release(pIX_2);
            successful++;
        } else {
            printf("ошибка при запросе интерфейса IEcoCalculatorX через интерфейс IEcoCalculatorY\n");
            unsuccessful++;
        }

        result = pIY->pVTbl->QueryInterface(pIY, &IID_IEcoLab1, (void**)&pIEcoLab1_2);
        if ( result == 0 && pIEcoLab1_2) {
            printf("Запрос интерфейса IEcoLab1 через интерфейс IEcoCalculatorY успешен\n");
            pIEcoLab1_2->pVTbl->Release(pIEcoLab1_2);
            successful++;
        } else {
            printf("ошибка при запросе интерфейса IEcoLab1 через интерфейс IEcoCalculatorY\n");
            unsuccessful++;
        }

        result =  pIY->pVTbl->QueryInterface(pIY, &IID_IEcoCalculatorY, (void**)&pIY_2);
        if ( result == 0 && pIY_2) {
            printf("Запрос интерфейса IEcoCalculatorY через интерфейс IEcoCalculatorY успешен\n");
            pIY_2->pVTbl->Release(pIY_2);
            successful++;
        } else {
            printf("ошибка при запросе интерфейса IEcoCalculatorY через интерфейс IEcoCalculatorY\n");
            unsuccessful++;
        }


        pIY->pVTbl->Release(pIY);
        successful++;
    } else {
        printf("ошибка при запросе интерфейса IEcoCalculatorY через интерфейс IEcoLab2\n");
        unsuccessful++;
    }


    printf("\n");
    if (pIEcoLab1->pVTbl->QueryInterface(pIEcoLab1, &IID_IEcoLab1, (void**)&pIEcoLab1) == 0 && pIEcoLab1) {
        printf("Запрос интерфейса IEcoLab1 через интерфейс IEcoLab1 успешен\n\n");

        if (pIEcoLab1->pVTbl->QueryInterface(pIEcoLab1, &IID_IEcoCalculatorX, (void**)&pIX_2) == 0 && pIX_2) {
            printf("Запрос интерфейса IEcoCalculatorX через интерфейс IEcoLab1 успешен\n");
            if (pIX_2->pVTbl->Addition(pIX_2, 1, 2) == 1+2){
                printf("результат сложения через интерфейс совпадает с результатом обычного сложения: 1 + 2 = %d\n",pIX_2->pVTbl->Addition(pIX_2, 1, 2));
            }
            if (pIX_2->pVTbl->Subtraction(pIX_2, 7, 3) == 7-3){
                printf("результат вычитания через интерфейс совпадает с результатом обычного вычитания: 7 - 3 = %d\n",pIX_2->pVTbl->Subtraction(pIX_2, 7, 3));
            }
            pIX_2->pVTbl->Release(pIX_2);
            successful++;
        } else {
            printf("ошибка при запросе интерфейса IEcoCalculatorX через интерфейс IEcoLab1\n");
            unsuccessful++;
        }

        if (pIEcoLab1->pVTbl->QueryInterface(pIEcoLab1, &IID_IEcoCalculatorY, (void**)&pIY_2) == 0 && pIY_2) {
            printf("Запрос интерфейса IEcoCalculatorY через интерфейс IEcoLab1 успешен\n");
            if (pIY_2->pVTbl->Multiplication(pIY_2, 4, 7) == 28){
                printf("результат умножения через интерфейс совпадает с результатом обычного умножения: 4 * 7 = %d\n",pIY_2->pVTbl->Multiplication(pIY_2, 4, 7));
            }
            if (pIY_2->pVTbl->Division(pIY_2, 28, 4) == 7){
                printf("результат деления через интерфейс совпадает с результатом обычного деления: 28 / 4 = %d\n",pIY_2->pVTbl->Division(pIY_2, 28, 4));
            }
            pIY_2->pVTbl->Release(pIY_2);
            successful++;
        } else {
            printf("ошибка при запросе интерфейса IEcoCalculatorY через интерфейс IEcoLab1\n");
            unsuccessful++;
        }

        result =  pIEcoLab1->pVTbl->QueryInterface(pIEcoLab1, &IID_IEcoLab1, (void**)&pIUnknown_2);
        if ( result == 0 && pIUnknown_2) {
            printf("Запрос интерфейса IEcoUnknown через интерфейс IEcoLab1 успешен\n");
            pIUnknown_2->pVTbl->Release(pIUnknown_2);
            successful++;
        } else {
            printf("ошибка при запросе интерфейса IEcoUnknown через интерфейс IEcoLab1\n");
            unsuccessful++;
        }

        pIEcoLab1->pVTbl->Release(pIEcoLab1);
        successful++;
    } else {
        printf("ошибка при запросе интерфейса IEcoLab1 через интерфейс IEcoLab1\n");
        unsuccessful++;
    }


        /* Получение тестируемого интерфейса */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoLab2, 0, &IID_IEcoLab2, (void**) &pIEcoLab2);
    if (result != 0 || pIEcoLab2 == 0) {
        printf("ошибка при запросе компонента EcoLab2\n");
        /* Освобождение интерфейсов в случае ошибки */
        goto Release;
    }

    printf("\n\n\n");
    printf("---------------------------------------------------------------------\n");
    printf("Тестирование механизма включения/агрегирования для компонента EcoLab2\n");

    printf("\n");
    if (pIEcoLab2->pVTbl->QueryInterface(pIEcoLab2, &IID_IEcoUnknown, (void**)&pIUnknown) == 0 && pIUnknown) {
        printf("Запрос интерфейса IEcoUnknown через интерфейс IEcoLab2 успешен\n\n");

        if (pIUnknown->pVTbl->QueryInterface(pIUnknown, &IID_IEcoLab2, (void**)&pIEcoLab2_2) == 0 && pIEcoLab2_2) {
            printf("Запрос интерфейса IEcoLab2 через интерфейс IEcoUnknown успешен\n");
            pIEcoLab2_2->pVTbl->Release(pIEcoLab2_2);
            successful++;
        } else {
            printf("ошибка при запросе интерфейса IEcoLab2 через интерфейс IEcoUnknown\n");
            unsuccessful++;
        }

        if (pIUnknown->pVTbl->QueryInterface(pIUnknown, &IID_IEcoCalculatorX, (void**)&pIX_2) == 0 && pIX_2) {
            printf("Запрос интерфейса IEcoCalculatorX через интерфейс IEcoUnknown успешен\n");
            if (pIX_2->pVTbl->Addition(pIX_2, 1, 2) == 1+2){
                printf("результат сложения через интерфейс совпадает с результатом обычного сложения: 1 + 2 = %d\n",pIX_2->pVTbl->Addition(pIX_2, 1, 2));
            }
            if (pIX_2->pVTbl->Subtraction(pIX_2, 7, 3) == 7-3){
                printf("результат вычитания через интерфейс совпадает с результатом обычного вычитания: 7 - 3 = %d\n",pIX_2->pVTbl->Subtraction(pIX_2, 7, 3));
            }
            pIX_2->pVTbl->Release(pIX_2);
            successful++;
        } else {
            printf("ошибка при запросе интерфейса IEcoCalculatorX через интерфейс IEcoUnknown\n");
            unsuccessful++;
        }

        if (pIUnknown->pVTbl->QueryInterface(pIUnknown, &IID_IEcoCalculatorY, (void**)&pIY_2) == 0 && pIY_2) {
            printf("Запрос интерфейса IEcoCalculatorY через интерфейс IEcoUnknown успешен\n");
            if (pIY_2->pVTbl->Multiplication(pIY_2, 4, 7) == 28){
                printf("результат умножения через интерфейс совпадает с результатом обычного умножения: 4 * 7 = %d\n",pIY_2->pVTbl->Multiplication(pIY_2, 4, 7));
            }
            if (pIY_2->pVTbl->Division(pIY_2, 28, 4) == 7){
                printf("результат деления через интерфейс совпадает с результатом обычного деления: 28 / 4 = %d\n",pIY_2->pVTbl->Division(pIY_2, 28, 4));
            }
            pIY_2->pVTbl->Release(pIY_2);
            successful++;
        } else {
            printf("ошибка при запросе интерфейса IEcoCalculatorY через интерфейс IEcoUnknown\n");
            unsuccessful++;
        }

        result =  pIUnknown->pVTbl->QueryInterface(pIUnknown, &IID_IEcoLab1, (void**)&pIEcoLab1_2);
        if ( result == 0 && pIEcoLab1_2) {
            printf("Запрос интерфейса IEcoLab1 через интерфейс IEcoUnknown успешен\n");
            pIEcoLab1_2->pVTbl->Release(pIEcoLab1_2);
            successful++;
        } else {
            printf("ошибка при запросе интерфейса IEcoLab1 через интерфейс IEcoUnknown\n");
            unsuccessful++;
        }

        result =  pIUnknown->pVTbl->QueryInterface(pIUnknown, &IID_IEcoUnknown, (void**)&pIUnknown_2);
        if ( result == 0 && pIUnknown_2) {
            printf("Запрос интерфейса IEcoUnknown через интерфейс IEcoUnknown успешен\n");
            pIUnknown_2->pVTbl->Release(pIUnknown_2);
            successful++;
        } else {
            printf("ошибка при запросе интерфейса IEcoUnknown через интерфейс IEcoUnknown\n");
            unsuccessful++;
        }

        pIUnknown->pVTbl->Release(pIUnknown);
        successful++;
    } else {
        printf("ошибка при запросе интерфейса IEcoUnknown через интерфейс IEcoLab2\n");
        unsuccessful++;
    }


    printf("\n");
    if (pIEcoLab2->pVTbl->QueryInterface(pIEcoLab2, &IID_IEcoCalculatorX, (void**)&pIX) == 0 && pIX) {
        printf("Запрос интерфейса IEcoCalculatorX через интерфейс IEcoLab2 успешен\n\n");

        if (pIX->pVTbl->Addition(pIX, 1, 2) == 1+2){
            printf("результат сложения через интерфейс совпадает с результатом обычного сложения: 1 + 2 = %d\n",pIX->pVTbl->Addition(pIX, 1, 2));
        }
        if (pIX->pVTbl->Subtraction(pIX, 7, 3) == 7-3){
            printf("результат вычитания через интерфейс совпадает с результатом обычного вычитания: 7 - 3 = %d\n",pIX->pVTbl->Subtraction(pIX, 7, 3));
        }

        if (pIX->pVTbl->QueryInterface(pIX, &IID_IEcoUnknown, (void**)&pIUnknown_2) == 0 && pIUnknown_2) {
            printf("Запрос интерфейса IEcoUnknown через интерфейс IEcoCalculatorX успешен\n");
            pIUnknown_2->pVTbl->Release(pIUnknown_2);
            successful++;
        } else {
            printf("ошибка при запросе интерфейса IEcoUnknown через интерфейс IEcoCalculatorX\n");
            unsuccessful++;
        }

        if (pIX->pVTbl->QueryInterface(pIX, &IID_IEcoCalculatorY, (void**)&pIY_2) == 0 && pIY_2) {
            printf("Запрос интерфейса IEcoCalculatorY через интерфейс IEcoCalculatorX успешен\n");
            if (pIY_2->pVTbl->Multiplication(pIY_2, 4, 7) == 28){
                printf("результат умножения через интерфейс совпадает с результатом обычного умножения: 4 * 7 = %d\n",pIY_2->pVTbl->Multiplication(pIY_2, 4, 7));
            }
            if (pIY_2->pVTbl->Division(pIY_2, 28, 4) == 7){
                printf("результат деления через интерфейс совпадает с результатом обычного деления: 28 / 4 = %d\n",pIY_2->pVTbl->Division(pIY_2, 28, 4));
            }
            pIY_2->pVTbl->Release(pIY_2);
            successful++;
        } else {
            printf("ошибка при запросе интерфейса IEcoCalculatorY через интерфейс IEcoCalculatorX\n");
            unsuccessful++;
        }

        result =  pIX->pVTbl->QueryInterface(pIX, &IID_IEcoLab2, (void**)&pIEcoLab2_2);
        if ( result == 0 && pIEcoLab1_2) {
            printf("Запрос интерфейса IEcoLab2 через интерфейс IEcoCalculatorX успешен\n");
            pIEcoLab2_2->pVTbl->Release(pIEcoLab2_2);
            successful++;
        } else {
            printf("ошибка при запросе интерфейса IEcoLab2 через интерфейс IEcoCalculatorX\n");
            unsuccessful++;
        }

        result = pIX->pVTbl->QueryInterface(pIX, &IID_IEcoLab1, (void**)&pIEcoLab1_2);
        if ( result == 0 && pIEcoLab1_2) {
            printf("Запрос интерфейса IEcoLab1 через интерфейс IEcoCalculatorX успешен\n");
            pIEcoLab1_2->pVTbl->Release(pIEcoLab1_2);
            successful++;
        } else {
            printf("ошибка при запросе интерфейса IEcoLab1 через интерфейс IEcoCalculatorX\n");
            unsuccessful++;
        }

        result =  pIX->pVTbl->QueryInterface(pIX, &IID_IEcoCalculatorX, (void**)&pIX_2);
        if ( result == 0 && pIX_2) {
            printf("Запрос интерфейса IEcoCalculatorX через интерфейс IEcoCalculatorX успешен\n");
            pIX_2->pVTbl->Release(pIX_2);
            successful++;
        } else {
            printf("ошибка при запросе интерфейса IEcoCalculatorX через интерфейс IEcoCalculatorX\n");
            unsuccessful++;
        }

        pIX->pVTbl->Release(pIX);
        successful++;
    } else {
        printf("ошибка при запросе интерфейса IEcoCalculatorX через интерфейс IEcoLab2\n");
        unsuccessful++;
    }



    printf("\n");
    if (pIEcoLab2->pVTbl->QueryInterface(pIEcoLab2, &IID_IEcoCalculatorY, (void**)&pIY) == 0 && pIY) {
        printf("Запрос интерфейса IEcoCalculatorY через интерфейс IEcoLab2 успешен\n\n");

        

        if (pIY->pVTbl->Multiplication(pIY, 4, 7) == 28){
            printf("результат умножения через интерфейс совпадает с результатом обычного умножения: 4 * 7 = %d\n",pIY->pVTbl->Multiplication(pIY_2, 4, 7));
        }
        if (pIY->pVTbl->Division(pIY, 28, 4) == 7){
            printf("результат деления через интерфейс совпадает с результатом обычного деления: 28 / 4 = %d\n",pIY->pVTbl->Division(pIY_2, 28, 4));
        }

        if (pIY->pVTbl->QueryInterface(pIY, &IID_IEcoUnknown, (void**)&pIUnknown_2) == 0 && pIUnknown_2) {
            printf("Запрос интерфейса IEcoUnknown через интерфейс IEcoCalculatorY успешен\n");
            pIUnknown_2->pVTbl->Release(pIUnknown_2);
            successful++;
        } else {
            printf("ошибка при запросе интерфейса IEcoUnknown через интерфейс IEcoCalculatorY\n");
            unsuccessful++;
        }

        if (pIY->pVTbl->QueryInterface(pIY, &IID_IEcoCalculatorX, (void**)&pIX_2) == 0 && pIX_2) {
            printf("Запрос интерфейса IEcoCalculatorX через интерфейс IEcoCalculatorY успешен\n");
            if (pIX_2->pVTbl->Addition(pIX_2, 1, 2) == 1+2){
            printf("результат сложения через интерфейс совпадает с результатом обычного сложения: 1 + 2 = %d\n",pIX_2->pVTbl->Addition(pIX, 1, 2));
            }
            if (pIX_2->pVTbl->Subtraction(pIX_2, 7, 3) == 7-3){
                printf("результат вычитания через интерфейс совпадает с результатом обычного вычитания: 7 - 3 = %d\n",pIX_2->pVTbl->Subtraction(pIX, 7, 3));
            }
            pIX_2->pVTbl->Release(pIX_2);
            successful++;
        } else {
            printf("ошибка при запросе интерфейса IEcoCalculatorX через интерфейс IEcoCalculatorY\n");
            unsuccessful++;
        }

        result =  pIY->pVTbl->QueryInterface(pIY, &IID_IEcoLab2, (void**)&pIEcoLab2_2);
        if ( result == 0 && pIEcoLab1_2) {
            printf("Запрос интерфейса IEcoLab2 через интерфейс IEcoCalculatorY успешен\n");
            pIEcoLab2_2->pVTbl->Release(pIEcoLab2_2);
            successful++;
        } else {
            printf("ошибка при запросе интерфейса IEcoLab2 через интерфейс IEcoCalculatorY\n");
            unsuccessful++;
        }

        result = pIY->pVTbl->QueryInterface(pIY, &IID_IEcoLab1, (void**)&pIEcoLab1_2);
        if ( result == 0 && pIEcoLab1_2) {
            printf("Запрос интерфейса IEcoLab1 через интерфейс IEcoCalculatorY успешен\n");
            pIEcoLab1_2->pVTbl->Release(pIEcoLab1_2);
            successful++;
        } else {
            printf("ошибка при запросе интерфейса IEcoLab1 через интерфейс IEcoCalculatorY\n");
            unsuccessful++;
        }

        result =  pIY->pVTbl->QueryInterface(pIY, &IID_IEcoCalculatorY, (void**)&pIY_2);
        if ( result == 0 && pIY_2) {
            printf("Запрос интерфейса IEcoCalculatorY через интерфейс IEcoCalculatorY успешен\n");
            pIY_2->pVTbl->Release(pIY_2);
            successful++;
        } else {
            printf("ошибка при запросе интерфейса IEcoCalculatorY через интерфейс IEcoCalculatorY\n");
            unsuccessful++;
        }


        pIY->pVTbl->Release(pIY);
        successful++;
    } else {
        printf("ошибка при запросе интерфейса IEcoCalculatorY через интерфейс IEcoLab2\n");
        unsuccessful++;
    }


    printf("\n");
    if (pIEcoLab2->pVTbl->QueryInterface(pIEcoLab2, &IID_IEcoLab1, (void**)&pIEcoLab1) == 0 && pIEcoLab1) {
        printf("Запрос интерфейса IEcoLab1 через интерфейс IEcoLab2 успешен\n\n");

        if (pIEcoLab1->pVTbl->QueryInterface(pIEcoLab1, &IID_IEcoLab2, (void**)&pIEcoLab2_2) == 0 && pIEcoLab2_2) {
            printf("Запрос интерфейса IEcoLab2 через интерфейс IEcoLab1 успешен\n");
            pIEcoLab2_2->pVTbl->Release(pIEcoLab2_2);
            successful++;
        } else {
            printf("ошибка при запросе интерфейса IEcoLab2 через интерфейс IEcoLab1\n");
            unsuccessful++;
        }

        if (pIEcoLab1->pVTbl->QueryInterface(pIEcoLab1, &IID_IEcoCalculatorX, (void**)&pIX_2) == 0 && pIX_2) {
            printf("Запрос интерфейса IEcoCalculatorX через интерфейс IEcoLab1 успешен\n");
            if (pIX_2->pVTbl->Addition(pIX_2, 1, 2) == 1+2){
                printf("результат сложения через интерфейс совпадает с результатом обычного сложения: 1 + 2 = %d\n",pIX_2->pVTbl->Addition(pIX_2, 1, 2));
            }
            if (pIX_2->pVTbl->Subtraction(pIX_2, 7, 3) == 7-3){
                printf("результат вычитания через интерфейс совпадает с результатом обычного вычитания: 7 - 3 = %d\n",pIX_2->pVTbl->Subtraction(pIX_2, 7, 3));
            }
            pIX_2->pVTbl->Release(pIX_2);
            successful++;
        } else {
            printf("ошибка при запросе интерфейса IEcoCalculatorX через интерфейс IEcoLab1\n");
            unsuccessful++;
        }

        if (pIEcoLab1->pVTbl->QueryInterface(pIEcoLab1, &IID_IEcoCalculatorY, (void**)&pIY_2) == 0 && pIY_2) {
            printf("Запрос интерфейса IEcoCalculatorY через интерфейс IEcoLab1 успешен\n");
            if (pIY_2->pVTbl->Multiplication(pIY_2, 4, 7) == 28){
                printf("результат умножения через интерфейс совпадает с результатом обычного умножения: 4 * 7 = %d\n",pIY_2->pVTbl->Multiplication(pIY_2, 4, 7));
            }
            if (pIY_2->pVTbl->Division(pIY_2, 28, 4) == 7){
                printf("результат деления через интерфейс совпадает с результатом обычного деления: 28 / 4 = %d\n",pIY_2->pVTbl->Division(pIY_2, 28, 4));
            }
            pIY_2->pVTbl->Release(pIY_2);
            successful++;
        } else {
            printf("ошибка при запросе интерфейса IEcoCalculatorY через интерфейс IEcoLab1\n");
            unsuccessful++;
        }

        result =  pIEcoLab1->pVTbl->QueryInterface(pIEcoLab1, &IID_IEcoLab1, (void**)&pIUnknown_2);
        if ( result == 0 && pIUnknown_2) {
            printf("Запрос интерфейса IEcoUnknown через интерфейс IEcoLab1 успешен\n");
            pIUnknown_2->pVTbl->Release(pIUnknown_2);
            successful++;
        } else {
            printf("ошибка при запросе интерфейса IEcoUnknown через интерфейс IEcoLab1\n");
            unsuccessful++;
        }

        result =  pIEcoLab1->pVTbl->QueryInterface(pIEcoLab1, &IID_IEcoLab1, (void**)&pIEcoLab1_2);
        if ( result == 0 && pIEcoLab1_2) {
            printf("Запрос интерфейса IEcoLab1 через интерфейс IEcoLab1 успешен\n");
            pIEcoLab1_2->pVTbl->Release(pIEcoLab1_2);
            successful++;
        } else {
            printf("ошибка при запросе интерфейса IEcoLab1 через интерфейс IEcoLab1\n");
            unsuccessful++;
        }

        pIEcoLab1->pVTbl->Release(pIEcoLab1);
        successful++;
    } else {
        printf("ошибка при запросе интерфейса IEcoLab1 через интерфейс IEcoLab2\n");
        unsuccessful++;
    }

    printf("количество успешных запросов: %d\n", successful);
    printf("количество неуспешных запросов: %d\n", unsuccessful);

Release:

    /* Освобождение интерфейса для работы с интерфейсной шиной */
    if (pIBus != 0) pIBus->pVTbl->Release(pIBus);

    /* Освобождение интерфейса работы с памятью */
    if (pIMem != 0) pIMem->pVTbl->Release(pIMem);

    /* Освобождение тестируемого интерфейса IEcoLab1*/
    if (pIEcoLab1 != 0) pIEcoLab2->pVTbl->Release(pIEcoLab1);

    /* Освобождение тестируемого интерфейса IEcoLab2*/
    if (pIEcoLab2 != 0) pIEcoLab2->pVTbl->Release(pIEcoLab2);

    /* Освобождение системного интерфейса */
    if (pISys != 0) pISys->pVTbl->Release(pISys);

    return result;
}

