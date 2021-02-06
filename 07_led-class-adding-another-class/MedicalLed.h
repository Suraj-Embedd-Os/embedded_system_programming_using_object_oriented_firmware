

#ifndef __MEDICALLED_H
#define	__MEDICALLED_H

#include "led.h"

typedef enum{
	INFARARED					=910,
	NEAR_INFARARED		=810
}LedWaveLenght_Type;

typedef struct{
	Led_Type						super;
	LedWaveLenght_Type	waveLenght;
}MedicalLed_Type;

void MedicalLed_ctor( MedicalLed_Type *const me,
											LedWaveLenght_Type _waveLenght,
											LedColor_Type _color,
											LedState_Type	_state);

LedWaveLenght_Type MedicalLed_GetWaveLength(MedicalLed_Type *const me);
void MedicalLed_SetWaveLength(MedicalLed_Type *const me,LedWaveLenght_Type _waveLenght);

#endif


