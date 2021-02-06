


#ifndef __LED_H
#define __LED_H

#include<stdint.h>
#include "stm32f4xx.h"

#define  LED_PORT				 GPIOA
#define  LED1_PIN				(1<<7U)
#define  LED2_PIN				(1<<8U)
#define  LED3_PIN				(1<<4U)
#define  LED4_PIN				(1<<5U)

#define LED1_MODE_BIT		(1<<7*2)
#define LED2_MODE_BIT		(1<<8*2)
#define LED3_MODE_BIT		(1<<4*2)
#define LED4_MODE_BIT		(1<<5*2)

#define LED_CLOCK				(1<<0U)
 
typedef enum{
	
	RED	=0,
	YELLOW,
	BLUE,
	GREEN
}LedColor_Type;

typedef enum{
	
	OFF	=0,
	ON,
}LedState_Type;


typedef struct{
	struct LedVtable const *vptr; /* virtual pointer */
	LedColor_Type color;
	LedState_Type	state;
}Led_Type;


/* led virtual table */

struct LedVtable{
	void (*run_diagnostics)(Led_Type *const me);
	uint32_t (*compute_efficiency)(Led_Type const * const me);
	
};

void Led_ctor(Led_Type * const me,LedColor_Type _color,LedState_Type _state);
void Led_setStatus(Led_Type * const me,LedState_Type _state);
LedState_Type Led_getStatus(Led_Type * const me);


/* method 1**/
static inline void Led_run_diagnostics_Vcall(Led_Type *const me)
{
	(*me->vptr->run_diagnostics)(me);
}

static inline uint32_t Led_ComputeEffi_Vcall(Led_Type const * const me)
{
	return (*me->vptr->compute_efficiency)(me);
}

/***method  2 ****/

#define LED_RUN_DIAG_VCALL(me)		(*(me)->vptr->run_diagnostics)(me);
#define LED_GET_EFFI_VCALL(me)		(*(me)->vptr->compute_efficiency)(me);
#endif








