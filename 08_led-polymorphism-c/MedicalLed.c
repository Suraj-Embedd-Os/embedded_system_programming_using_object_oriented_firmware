
#include "MedicalLed.h"
#include "usart.h"

void MedicalLed_ctor( MedicalLed_Type *const me,
											LedWaveLenght_Type _waveLenght,
											LedColor_Type _color,
											LedState_Type	_state)
{
	
	static const struct LedVtable vtable ={
		(void(*)(Led_Type const * const me))&MedicalLed_runDiagnostics,
		(uint32_t(*)(Led_Type const * const me))&MedicalLed_computeEfficiency,
			
	};
	
	Led_ctor(&me->super,_color,_state);
	me->super.vptr =&vtable;
	me->waveLenght	=_waveLenght;
	
	
	
}

LedWaveLenght_Type MedicalLed_GetWaveLength(MedicalLed_Type *const me){
	return me->waveLenght;
}

void MedicalLed_SetWaveLength(MedicalLed_Type *const me,LedWaveLenght_Type _waveLenght){
	me->waveLenght	= _waveLenght;
}


uint32_t MedicalLed_computeEfficiency(MedicalLed_Type const *const me)
{
	//Dummy efficiency computations
	
	const int8_t input=120;
	const int8_t output=80;
	const int8_t k1=4;
	const int8_t k2=10;
	
	int8_t k;
	k= me->waveLenght ==INFARARED ? k1:k2;
	int8_t eff =((input/output)*100)-k;
	
	printf("medical Led Module Efficiency is  : %d...\r\n",eff);
	return eff;
}

void MedicalLed_runDiagnostics(MedicalLed_Type const *const me)
{
	/* dummy diagnosis */
	for(int i=0;i<20;i++)
	{
		printf("mediacal Led diagnositics stage :%d...\n\r",i);
		
		// do something
	}
}
