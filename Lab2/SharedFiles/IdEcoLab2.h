/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IdEcoLab2
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IdEcoLab2
 * </описание>
 *
 * <ссылка>
 *
 * </ссылка>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __ID_ECOLAB2_H__
#define __ID_ECOLAB2_H__

#include "IEcoBase1.h"
#include "IEcoLab2.h"

/* EcoLab2 CID = {A3C8F12B-94D7-4E1A-87C2-6F1B44D9E7C1} */
#ifndef __CID_EcoLab2
static const UGUID CID_EcoLab2 = {0x01, 0x10, {0xA3, 0xC8, 0xF1, 0x2B, 0x94, 0xD7, 0x4E, 0x1A, 0x87, 0xC2, 0x6F, 0x1B, 0x44, 0xD9, 0xE7, 0xC1}};
#endif /* __CID_EcoLab2 */

/* Фабрика компонента для динамической и статической компановки */
#ifdef ECO_DLL
ECO_EXPORT IEcoComponentFactory* ECOCALLMETHOD GetIEcoComponentFactoryPtr();
#elif ECO_LIB

extern IEcoComponentFactory* GetIEcoComponentFactoryPtr_D42A9B8EF376491CB32985C1F3A6E0B4;
#endif

#endif /* __ID_ECOLAB2_H__ */
