#include "rtwtypes.h"
#include "StopWatch2016_types.h"

//------------------------------------------------------------------------------
// GLOBAL DATA STRUCTURES
//------------------------------------------------------------------------------

// Block states
typedef struct {
  uint8_T is_Control;
  uint8_T is_timesetmode;
  uint8_T is_swatchmode;
  uint8_T is_alarmmode;
  uint8_T is_AlarmMng;
} states;

// Variables of the model
typedef struct {
  uint8_T hours;
  uint8_T minutes;
  uint8_T seconds;
  uint8_T tenths;
  uint8_T SWhours;
  uint8_T SWminutes;
  uint8_T SWseconds;
  uint8_T SWtenths;
  uint8_T Ahours;
  uint8_T Aminutes;
  boolean_T lapmode;
} local_variable;

// Structure of the model
struct tag_RTM_StopWatch2016_T {
  states *work_mode;
  local_variable *var;
};

//------------------------------------------------------------------------------
// FUNCTIONS
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// STOP WATCH 2016 STEP: 	Step function called to update the output and the
//							state of the machine
//------------------------------------------------------------------------------

void StopWatch2016_step(		RT_MODEL_StopWatch2016_T * StopWatch2016_M,
		boolean_T plusbutton,	boolean_T minusbutton, 	boolean_T timemode,
		boolean_T timesetmode, 	boolean_T alarmmode,	boolean_T swatchmode,
		boolean_T alarmonoff,	uint8_T *hours, 		uint8_T *minutes,
		uint8_T *seconds, 		uint8_T *tenths, 		uint8_T *mode,
		boolean_T *hblink,		boolean_T *mblink, 		boolean_T *alarmOn,
		boolean_T *ringing);

//------------------------------------------------------------------------------
// STOP WATCH 2016 INITIALIZE: 	Initialize function called to initialize  the
//								state machine
//------------------------------------------------------------------------------

void StopWatch2016_initialize(	RT_MODEL_StopWatch2016_T * StopWatch2016_M,
		boolean_T *plusbutton,	boolean_T *minusbutton, boolean_T *timemode,
		boolean_T *timesetmode, boolean_T *alarmmode,	boolean_T *swatchmode,
		boolean_T *alarmonoff,	uint8_T *hours, 		uint8_T *minutes,
		uint8_T *seconds, 		uint8_T *tenths, 		uint8_T *mode,
		boolean_T *hblink,		boolean_T *mblink, 		boolean_T *alarmOn,
		boolean_T *ringing);
