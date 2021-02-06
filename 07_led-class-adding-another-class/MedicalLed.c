
#include "MedicalLed.h"


void MedicalLed_ctor( MedicalLed_Type *const me,
											LedWaveLenght_Type _waveLenght,
											LedColor_Type _color,
											LedState_Type	_state)
{
	Led_ctor(&me->super,_color,_state);
	me->waveLenght	=_waveLenght;
	
}

LedWaveLenght_Type MedicalLed_GetWaveLength(MedicalLed_Type *const me){
	return me->waveLenght;
}

void MedicalLed_SetWaveLength(MedicalLed_Type *const me,LedWaveLenght_Type _waveLenght){
	me->waveLenght	= _waveLenght;
}


