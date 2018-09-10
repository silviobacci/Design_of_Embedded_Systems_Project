/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: StopWatch2016.h
 *
 * Code generated for Simulink model 'StopWatch2016'.
 *
 * Model version                  : 1.80
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Tue Dec 27 09:51:16 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_StopWatch2016_h_
#define RTW_HEADER_StopWatch2016_h_
#include <string.h>
#ifndef StopWatch2016_COMMON_INCLUDES_
# define StopWatch2016_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* StopWatch2016_COMMON_INCLUDES_ */

#include "StopWatch2016_types.h"
#include "rt_defines.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetPrevZCSigState
# define rtmGetPrevZCSigState(rtm)     ((rtm)->prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
# define rtmSetPrevZCSigState(rtm, val) ((rtm)->prevZCSigState = (val))
#endif

#ifndef rtmGetRootDWork
# define rtmGetRootDWork(rtm)          ((rtm)->dwork)
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ((rtm)->dwork = (val))
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  int32_T sfEvent;                     /* '<S1>/SWatch' */
  uint8_T is_Control;                  /* '<S1>/SWatch' */
  uint8_T is_timesetmode;              /* '<S1>/SWatch' */
  uint8_T is_swatchmode;               /* '<S1>/SWatch' */
  uint8_T is_alarmmode;                /* '<S1>/SWatch' */
  uint8_T is_AlarmMng;                 /* '<S1>/SWatch' */
  uint8_T hours;                       /* '<S1>/SWatch' */
  uint8_T minutes;                     /* '<S1>/SWatch' */
  uint8_T seconds;                     /* '<S1>/SWatch' */
  uint8_T tenths;                      /* '<S1>/SWatch' */
  uint8_T SWhours;                     /* '<S1>/SWatch' */
  uint8_T SWminutes;                   /* '<S1>/SWatch' */
  uint8_T SWseconds;                   /* '<S1>/SWatch' */
  uint8_T SWtenths;                    /* '<S1>/SWatch' */
  uint8_T Ahours;                      /* '<S1>/SWatch' */
  uint8_T Aminutes;                    /* '<S1>/SWatch' */
  boolean_T lapmode;                   /* '<S1>/SWatch' */
} DW_StopWatch2016_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState SWatch_Trig_ZCE[8];       /* '<S1>/SWatch' */
} PrevZCX_StopWatch2016_T;

/* Real-time Model Data Structure */
struct tag_RTM_StopWatch2016_T {
  const char_T *errorStatus;
  PrevZCX_StopWatch2016_T *prevZCSigState;
  DW_StopWatch2016_T *dwork;
};

/* Model entry point functions */
extern void StopWatch2016_initialize(RT_MODEL_StopWatch2016_T *const
  StopWatch2016_M, boolean_T *StopWatch2016_U_tick, boolean_T
  *StopWatch2016_U_plusbutton, boolean_T *StopWatch2016_U_minusbutton, boolean_T
  *StopWatch2016_U_timemode, boolean_T *StopWatch2016_U_timesetmode, boolean_T
  *StopWatch2016_U_alarmmode, boolean_T *StopWatch2016_U_swatchmode, boolean_T
  *StopWatch2016_U_alarmonoff, uint8_T *StopWatch2016_Y_hours, uint8_T
  *StopWatch2016_Y_minutes, uint8_T *StopWatch2016_Y_seconds, uint8_T
  *StopWatch2016_Y_tenths, uint8_T *StopWatch2016_Y_mode, boolean_T
  *StopWatch2016_Y_hblink, boolean_T *StopWatch2016_Y_mblink, boolean_T
  *StopWatch2016_Y_alarmOn, boolean_T *StopWatch2016_Y_ringing);
extern void StopWatch2016_step(RT_MODEL_StopWatch2016_T *const StopWatch2016_M,
  boolean_T StopWatch2016_U_tick, boolean_T StopWatch2016_U_plusbutton,
  boolean_T StopWatch2016_U_minusbutton, boolean_T StopWatch2016_U_timemode,
  boolean_T StopWatch2016_U_timesetmode, boolean_T StopWatch2016_U_alarmmode,
  boolean_T StopWatch2016_U_swatchmode, boolean_T StopWatch2016_U_alarmonoff,
  uint8_T *StopWatch2016_Y_hours, uint8_T *StopWatch2016_Y_minutes, uint8_T
  *StopWatch2016_Y_seconds, uint8_T *StopWatch2016_Y_tenths, uint8_T
  *StopWatch2016_Y_mode, boolean_T *StopWatch2016_Y_hblink, boolean_T
  *StopWatch2016_Y_mblink, boolean_T *StopWatch2016_Y_alarmOn, boolean_T
  *StopWatch2016_Y_ringing);
extern void StopWatch2016_terminate(RT_MODEL_StopWatch2016_T *const
  StopWatch2016_M);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('StopWatchProject/StopWatch2016')    - opens subsystem StopWatchProject/StopWatch2016
 * hilite_system('StopWatchProject/StopWatch2016/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'StopWatchProject'
 * '<S1>'   : 'StopWatchProject/StopWatch2016'
 * '<S2>'   : 'StopWatchProject/StopWatch2016/SWatch'
 */
#endif                                 /* RTW_HEADER_StopWatch2016_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
