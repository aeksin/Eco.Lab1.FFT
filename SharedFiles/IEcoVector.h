#ifndef __I_ECO_VECTOR_H__
#define __I_ECO_VECTOR_H__

#include "IEcoBase1.h"
#include "EcoLabDefines.h"

/* IEcoLab1 IID = {277FC00C-3562-4096-AFCF-C125B94EEC90} */
#ifndef __IID_IEcoVector
static const UGUID IID_IEcoVector = {0x01, 0x10, {0x2D, 0x7C, 0xF9, 0x14, 0x56, 0x89, 0x4B, 0xE2, 0x83, 0x1A, 0xBE, 0x05, 0x72, 0x9C, 0x48, 0xF6}};
#endif /* __IID_IEcoVector */

typedef struct IEcoVector* IEcoVectorPtr_t;

typedef struct IEcoVectorVTbl {

	/* IEcoUnknown */
	int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoVectorPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
	uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoVectorPtr_t me);
	uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoVectorPtr_t me);

	/* IEcoVector */
	IEcoVectorPtr_t (ECOCALLMETHOD *NewVector)(/* in */ IEcoVectorPtr_t me, /* in */ EcoDataType_e type, /* in */ uint32_t size);
	int16_t (ECOCALLMETHOD *Set)(/* in */ IEcoVectorPtr_t me, /* in */ uint32_t position, /* in */ voidptr_t value, EcoDataType_e type);
	int16_t (ECOCALLMETHOD *Get)(/* in */ IEcoVectorPtr_t me, /* in */ uint32_t position, /* in */ voidptr_t outValue, EcoDataType_e type);
	uint32_t (ECOCALLMETHOD *GetSize)(/* in */ IEcoVectorPtr_t me);
	EcoDataType_e (ECOCALLMETHOD *GetType)(/* in */ IEcoVectorPtr_t me);
	

} IEcoVectorVTbl, *IEcoVectorVTblPtr;

interface IEcoVector {
    struct IEcoVectorVTbl *pVTbl;
} IEcoVector;

#endif /* __I_ECO_VECTOR_H__ */