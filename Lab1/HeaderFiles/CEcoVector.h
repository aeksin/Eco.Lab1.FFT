/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoVector
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию компонента CEcoVector
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_EcoVector_H__
#define __C_EcoVector_H__

#include "IEcoVector.h"
#include "IEcoLab1.h"
#include "EcoLabDefines.h"
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"

typedef struct CEcoVector {

    /* Таблица функций интерфейса IEcoVector */
    IEcoVectorVTbl* m_pVTblIEcoVector;
    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Системный интерфейс */
    IEcoSystem1* m_pISys;

    /* Данные экземпляра */
    uint64_t m_Size;
    EcoDataType_e m_Type;
    uint64_t m_ElementSize;
    void* m_pData;

} CEcoVector, *CEcoVectorPtr;

/* Инициализация экземпляра */
int16_t ECOCALLMETHOD initCEcoVector(/*in*/ struct IEcoVector* me, /* in */ IEcoUnknown *pIUnkSystem);
/* Создание экземпляра */
int16_t ECOCALLMETHOD createCEcoVector(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* out */ IEcoVector** ppIEcoVector);
/* Удаление */
void ECOCALLMETHOD deleteCEcoVector(/* in */ IEcoVector* pIEcoVector);

#endif /* __C_EcoVector_H__ */
