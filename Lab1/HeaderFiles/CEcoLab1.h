
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
 *   Данный заголовок описывает реализацию компонента CEcoLab1
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_ECOLAB1_H__
#define __C_ECOLAB1_H__

#include "IEcoLab1.h"
#include "IEcoSystem1.h"
#include "IEcoCalculatorX.h"
#include "IEcoCalculatorY.h"
#include "IdEcoMemoryManager1.h"

typedef struct CEcoLab1* CEcoLab1Ptr_t;

typedef struct CEcoLab1 {

    /* Таблица функций интерфейса IEcoLab1 */
    IEcoLab1VTbl* m_pVTblIEcoLab1;

    /* Таблица функций интерфейса IEcoCalculatorY */
    IEcoCalculatorYVTbl* m_pVTblY;

    /* Таблица функций интерфейса IEcoCalculatorX */
    IEcoCalculatorXVTbl* m_pVTblX;

    /* Неделегирующий интерфейс IEcoNondelegatingUnknown */
    IEcoUnknownVTbl* m_pVTblINondelegatingUnk;

    IEcoVectorVTbl* m_pVTblIEcoVector;

    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Системный интерфейс */
    IEcoSystem1* m_pISys;

    IEcoCalculatorY* m_pIY;

    IEcoCalculatorX* m_pIX;

    IEcoUnknown* m_pInnerUnknown;

    IEcoUnknown* m_pIUnkOuter;

} CEcoLab1;

/* Инициализация экземпляра */
int16_t ECOCALLMETHOD initCEcoLab1(/* in */ IEcoLab1Ptr_t me, /* in */ IEcoUnknownPtr_t pIUnkSystem);
/* Создание экземпляра */
int16_t ECOCALLMETHOD createCEcoLab1(/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* out */ IEcoLab1Ptr_t* ppIEcoLab1);
/* Удаление */
void ECOCALLMETHOD deleteCEcoLab1(/* in */ IEcoLab1Ptr_t pIEcoLab1);

#endif /* __C_ECOLAB1_H__ */

