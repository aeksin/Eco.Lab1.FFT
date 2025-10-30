/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoLab2
 * </сводка>
 *
 * <описание>
 *   Данный исходный код описывает реализацию интерфейсов CEcoLab2
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
#include "IEcoCalculatorX.h"
#include "IEcoCalculatorY.h"
#include "IEcoLab1.h"
#include "IdEcoLab1.h"
#include "IdEcoCalculatorB.h"
#include "IdEcoCalculatorE.h"
#include "CEcoLab2.h"

/*
 *
 * <сводка>
 *   Функция QueryInterface
 * </сводка>
 *
 * <описание>
 *   Функция QueryInterface для интерфейса IEcoLab2
 * </описание>
 *
 */
static int16_t ECOCALLMETHOD CEcoLab2_QueryInterface(/* in */ IEcoLab2Ptr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv) {
    CEcoLab2* pCMe = (CEcoLab2*)me;

    /* Проверка указателей */
    if ( me == 0 || ppv == 0 ) {
        return ERR_ECO_POINTER;
    }

    /* Проверка и получение запрошенного интерфейса */
    if ( IsEqualUGUID(riid, &IID_IEcoLab2) ) {
        *ppv = &pCMe->m_pVTblIEcoLab2;
        pCMe->m_pVTblIEcoLab2->AddRef((IEcoLab2*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoCalculatorX) ) {
        *ppv = &pCMe->m_pVTblX;
        pCMe->m_pVTblIEcoLab2->AddRef((IEcoLab2*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoCalculatorY) ) {
        *ppv = &pCMe->m_pVTblY;
        pCMe->m_pVTblIEcoLab2->AddRef((IEcoLab2*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoLab1) && pCMe->m_pInnerUnknown != 0 ) {
        return pCMe->m_pInnerUnknown->pVTbl->QueryInterface(pCMe->m_pInnerUnknown, riid, ppv);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoUnknown) ) {
        *ppv = &pCMe->m_pVTblIEcoLab2;
        pCMe->m_pVTblIEcoLab2->AddRef((IEcoLab2*)pCMe);
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
 *   Функция AddRef
 * </сводка>
 *
 * <описание>
 *   Функция AddRef для интерфейса IEcoLab2
 * </описание>
 *
 */
static uint32_t ECOCALLMETHOD CEcoLab2_AddRef(/* in */ IEcoLab2Ptr_t me) {
    CEcoLab2* pCMe = (CEcoLab2*)me;

    /* Проверка указателя */
    if ( me == 0 ) {
        return -1; /* ERR_ECO_POINTER */
    }

    return ++pCMe->m_cRef;
}

/*
 *
 * <сводка>
 *   Функция Release
 * </сводка>
 *
 * <описание>
 *   Функция Release для интерфейса IEcoLab2
 * </описание>
 *
 */
static uint32_t ECOCALLMETHOD CEcoLab2_Release(/* in */ IEcoLab2Ptr_t me) {
    CEcoLab2* pCMe = (CEcoLab2*)me;

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
            deleteCEcoLab2((IEcoLab2*)pCMe);
        }		
        return 0;
    }
    return pCMe->m_cRef;
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
static int16_t ECOCALLMETHOD CEcoLab2_IEcoCalculatorY_QueryInterface(/* in */ IEcoCalculatorYPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv) {
    CEcoLab2* pCMe = (CEcoLab2*)((uint64_t)me - sizeof(IEcoUnknownPtr_t));
    
    /* Проверка указателей */
    if ( me == 0 || ppv == 0 ) {
        return ERR_ECO_POINTER;
    }

    /* Проверка и получение запрошенного интерфейса */
    
    if ( IsEqualUGUID(riid, &IID_IEcoCalculatorY) ) {
        *ppv = &pCMe->m_pVTblY;
        pCMe->m_pVTblIEcoLab2->AddRef((IEcoLab2*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoCalculatorX) ) {
        *ppv = &pCMe->m_pVTblX;
        pCMe->m_pVTblIEcoLab2->AddRef((IEcoLab2*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoLab1) && pCMe->m_pInnerUnknown != 0 ) {
        return pCMe->m_pInnerUnknown->pVTbl->QueryInterface(pCMe->m_pInnerUnknown, riid, ppv);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoLab2) ) {
        *ppv = &pCMe->m_pVTblIEcoLab2;
        pCMe->m_pVTblIEcoLab2->AddRef((IEcoLab2*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoUnknown) ) {
        *ppv = &pCMe->m_pVTblY;
        pCMe->m_pVTblIEcoLab2->AddRef((IEcoLab2*)pCMe);
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
 *   Функция AddRef
 * </сводка>
 *
 * <описание>
 *   Функция AddRef для интерфейса IEcoCalculatorY
 * </описание>
 *
 */
static uint32_t ECOCALLMETHOD CEcoLab2_IEcoCalculatorY_AddRef(/* in */ IEcoCalculatorYPtr_t me) {
    CEcoLab2* pCMe = (CEcoLab2*)((uint64_t)me - sizeof(IEcoUnknownPtr_t));

    /* Проверка указателя */
    if ( me == 0 ) {
        return -1; /* ERR_ECO_POINTER */
    }

    return ++pCMe->m_cRef;
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
static uint32_t ECOCALLMETHOD CEcoLab2_IEcoCalculatorY_Release(/* in */ IEcoCalculatorYPtr_t me) {
    CEcoLab2* pCMe = (CEcoLab2*)((uint64_t)me - sizeof(IEcoUnknownPtr_t));
    
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
            deleteCEcoLab2((IEcoLab2*)pCMe);
        }		
        return 0;
    }
    return pCMe->m_cRef;
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
int32_t ECOCALLMETHOD CEcoLab2_IEcoCalculatorY_Multiplication(/* in */ IEcoCalculatorYPtr_t me, /* in */ int16_t a, /* in */ int16_t b) {
	CEcoLab2* pCMe = (CEcoLab2*)((uint64_t)me - sizeof(IEcoUnknownPtr_t));
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
int16_t ECOCALLMETHOD CEcoLab2_IEcoCalculatorY_Division(/* in */ IEcoCalculatorYPtr_t me, /* in */ int16_t a, /* in */ int16_t b) {
    CEcoLab2* pCMe = (CEcoLab2*)((uint64_t)me - sizeof(IEcoUnknownPtr_t));
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
int16_t ECOCALLMETHOD CEcoLab2_IEcoCalculatorX_QueryInterface(/* in */ IEcoCalculatorXPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv) {
    CEcoLab2* pCMe = (CEcoLab2*)((uint64_t)me - 2 * sizeof(IEcoUnknownPtr_t));
    
    /* Проверка указателей */
    if ( me == 0 || ppv == 0 ) {
        return ERR_ECO_POINTER;
    }

    /* Проверка и получение запрошенного интерфейса */
    if ( IsEqualUGUID(riid, &IID_IEcoCalculatorX) ) {
        *ppv = &pCMe->m_pVTblX;
        pCMe->m_pVTblIEcoLab2->AddRef((IEcoLab2*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoCalculatorY) ) {
        *ppv = &pCMe->m_pVTblY;
        pCMe->m_pVTblIEcoLab2->AddRef((IEcoLab2*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoLab1) && pCMe->m_pInnerUnknown != 0) {
        return pCMe->m_pInnerUnknown->pVTbl->QueryInterface(pCMe->m_pInnerUnknown, riid, ppv);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoLab2) ) {
        *ppv = &pCMe->m_pVTblIEcoLab2;
        pCMe->m_pVTblIEcoLab2->AddRef((IEcoLab2*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoUnknown) ) {
        *ppv = &pCMe->m_pVTblX;
        pCMe->m_pVTblIEcoLab2->AddRef((IEcoLab2*)pCMe);
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
 *   Функция AddRef
 * </сводка>
 *
 * <описание>
 *   Функция AddRef для интерфейса IEcoCalculatorX
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CEcoLab2_IEcoCalculatorX_AddRef(/* in */ IEcoCalculatorXPtr_t me) {
    CEcoLab2* pCMe = (CEcoLab2*)((uint64_t)me - 2 * sizeof(IEcoUnknownPtr_t));

    /* Проверка указателя */
    if ( me == 0 ) {
        return -1; /* ERR_ECO_POINTER */
    }

    return ++pCMe->m_cRef;
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
uint32_t ECOCALLMETHOD CEcoLab2_IEcoCalculatorX_Release(/* in */ IEcoCalculatorXPtr_t me) {
    CEcoLab2* pCMe = (CEcoLab2*)((uint64_t)me - 2 * sizeof(IEcoUnknownPtr_t));
    
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
            deleteCEcoLab2((IEcoLab2*)pCMe);
        }		
        return 0;
    }
    return pCMe->m_cRef;
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
int32_t ECOCALLMETHOD CEcoLab2_IEcoCalculatorX_Addition(/* in */ IEcoCalculatorXPtr_t me, /* in */ int16_t a, /* in */ int16_t b) {
    CEcoLab2* pCMe = (CEcoLab2*)((uint64_t)me - 2 * sizeof(IEcoUnknownPtr_t));
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
int16_t ECOCALLMETHOD CEcoLab2_IEcoCalculatorX_Subtraction(/* in */ IEcoCalculatorXPtr_t me, /* in */ int16_t a, /* in */ int16_t b) {
    CEcoLab2* pCMe = (CEcoLab2*)((uint64_t)me - 2 * sizeof(IEcoUnknownPtr_t));
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
 *   Функция Init
 * </сводка>
 *
 * <описание>
 *   Функция инициализации экземпляра
 * </описание>
 *
 */
int16_t ECOCALLMETHOD initCEcoLab2(/* in */ IEcoLab2Ptr_t me, /* in */ IEcoUnknownPtr_t pIUnkSystem) {
    /* CEcoLab2* pCMe = (CEcoLab2*)me; */

    /* Проверка указателей */
    if ( me == 0 ) {
        return ERR_ECO_POINTER;
    }

    return ERR_ECO_SUCCESES;
}

IEcoLab2VTbl g_x7E91C2A405F34D88BA629F8D12C7F5D9Lab2VTbl = {
    CEcoLab2_QueryInterface,
    CEcoLab2_AddRef,
    CEcoLab2_Release
};

IEcoCalculatorXVTbl g_x9322111622484742AE0682819447843DLab2VTbl = {
    CEcoLab2_IEcoCalculatorX_QueryInterface,
    CEcoLab2_IEcoCalculatorX_AddRef,
    CEcoLab2_IEcoCalculatorX_Release,
    CEcoLab2_IEcoCalculatorX_Addition,
    CEcoLab2_IEcoCalculatorX_Subtraction
};

IEcoCalculatorYVTbl g_xBD6414C29096423EA90C04D77AFD1CADLab2VTbl = {
    CEcoLab2_IEcoCalculatorY_QueryInterface,
    CEcoLab2_IEcoCalculatorY_AddRef,
    CEcoLab2_IEcoCalculatorY_Release,
    CEcoLab2_IEcoCalculatorY_Multiplication,
    CEcoLab2_IEcoCalculatorY_Division
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
int16_t ECOCALLMETHOD createCEcoLab2(/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* out */ IEcoLab2Ptr_t* ppIEcoLab2) {
    int16_t result = ERR_ECO_POINTER;
    IEcoSystem1* pISys = 0;
    IEcoInterfaceBus1* pIBus = 0;
    IEcoInterfaceBus1MemExt* pIMemExt = 0;
    IEcoMemoryAllocator1* pIMem = 0;
    CEcoLab2* pCMe = 0;
    UGUID* rcid = (UGUID*)&CID_EcoMemoryManager1;
	
    /* Проверка указателей */
    if ( ppIEcoLab2 == 0 || pIUnkSystem == 0 ) {
        return result; /* ERR_ECO_POINTER */
    }

    /* Получение системного интерфейса приложения */
    result = pIUnkSystem->pVTbl->QueryInterface(pIUnkSystem, &GID_IEcoSystem, (void **)&pISys);
    /* Проверка */
    if ( result != 0 || pISys == 0 ) {
        return ERR_ECO_NOSYSTEM;
    }

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pISys->pVTbl->QueryInterface(pISys, &IID_IEcoInterfaceBus1, (void **)&pIBus);
    /* Проверка */
    if ( result != 0 || pIBus == 0 ) {
        pISys->pVTbl->Release(pISys);
        return ERR_ECO_NOBUS;
    }
	
	/* Получение идентификатора компонента для работы с памятью */
    result = pIBus->pVTbl->QueryInterface(pIBus, &IID_IEcoInterfaceBus1MemExt, (void**)&pIMemExt);
    if ( result == 0 && pIMemExt != 0 ) {
        rcid = (UGUID*)pIMemExt->pVTbl->get_Manager(pIMemExt);
        pIMemExt->pVTbl->Release(pIMemExt);
    }

    /* Получение интерфейса распределителя памяти */
    pIBus->pVTbl->QueryComponent(pIBus, rcid, 0, &IID_IEcoMemoryAllocator1, (void**) &pIMem);
    /* Проверка */
    if ( result != 0 || pIMem == 0 ) {
        /* Освобождение в случае ошибки */
        pIBus->pVTbl->Release(pIBus);
        pISys->pVTbl->Release(pISys);
        return ERR_ECO_GET_MEMORY_ALLOCATOR;
    }

    /* Выделение памяти для данных экземпляра */
    pCMe = (CEcoLab2*)pIMem->pVTbl->Alloc(pIMem, sizeof(CEcoLab2));
    if ( pCMe == 0 ) {
        /* Освобождение в случае ошибки */
        pIBus->pVTbl->Release(pIBus);
        pISys->pVTbl->Release(pISys);
        return ERR_ECO_OUTOFMEMORY;
    }
	
    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = pISys;

    /* Сохранение указателя на интерфейс для работы с памятью */
    pCMe->m_pIMem = pIMem;

    /* Установка счетчика ссылок на компонент */
    pCMe->m_cRef = 1;

    /* Создание таблицы функций интерфейса IEcoLab2 */
    pCMe->m_pVTblIEcoLab2 = &g_x7E91C2A405F34D88BA629F8D12C7F5D9Lab2VTbl;

    /* Создание таблицы функций интерфейса IEcoCalculatorX */
    pCMe->m_pVTblX = &g_x9322111622484742AE0682819447843DLab2VTbl;

    /* Создание таблицы функций интерфейса IEcoCalculatorY */
    pCMe->m_pVTblY = &g_xBD6414C29096423EA90C04D77AFD1CADLab2VTbl;


    pCMe->m_pIX = 0;
    pCMe->m_pIY = 0;
    pCMe->m_pInnerUnknown = 0;

    /* Возврат указателя на интерфейс */
    *ppIEcoLab2 = (IEcoLab2*)pCMe;

    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoCalculatorE, 0, &IID_IEcoCalculatorY, (void **) &pCMe->m_pIY);
    if ( result == 0 && pCMe->m_pIY != 0 ) {
		result = pCMe->m_pIY->pVTbl->QueryInterface(pCMe->m_pIY, &IID_IEcoCalculatorX, (void **)&pCMe->m_pIX);
    }

    // Получение интерфейса IEcoLab1 через агрегирование
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoLab1, (IEcoUnknown*)pCMe, &IID_IEcoUnknown, (void **) &pCMe->m_pInnerUnknown);
    if ( result == 0 && pCMe->m_pInnerUnknown != 0 ) {
        if ( pCMe->m_pIX == 0 ) {
            result = pCMe->m_pInnerUnknown->pVTbl->QueryInterface(pCMe->m_pInnerUnknown, &IID_IEcoCalculatorX, (void **) &pCMe->m_pIX);
        }
        if ( pCMe->m_pIY == 0 ) {
            result = pCMe->m_pInnerUnknown->pVTbl->QueryInterface(pCMe->m_pInnerUnknown, &IID_IEcoCalculatorY, (void **) &pCMe->m_pIY);
        }
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
void ECOCALLMETHOD deleteCEcoLab2(/* in */ IEcoLab2Ptr_t pIEcoLab2) {
    CEcoLab2* pCMe = (CEcoLab2*)pIEcoLab2;
    IEcoMemoryAllocator1* pIMem = 0;

    if ( pIEcoLab2 != 0 ) {
        pIMem = pCMe->m_pIMem;
        /* Освобождение */
        if ( pCMe->m_pIY!= 0 ) {
            pCMe->m_pIY->pVTbl->Release(pCMe->m_pIY);
        }
        if ( pCMe->m_pIX != 0 ) {
            pCMe->m_pIX->pVTbl->Release(pCMe->m_pIX);
        }
        if ( pCMe->m_pISys != 0 ) {
            pCMe->m_pISys->pVTbl->Release(pCMe->m_pISys);
        }
        pIMem->pVTbl->Free(pIMem, pCMe);
        pIMem->pVTbl->Release(pIMem);
    }
}
