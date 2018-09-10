/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: StopWatch2016.c
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

#include "StopWatch2016.h"
#include "StopWatch2016_private.h"

/* Named constants for Chart: '<S1>/SWatch' */
#define StopWatch2016_IN_alarmmode     ((uint8_T)1U)
#define StopWatch2016_IN_ringing       ((uint8_T)1U)
#define StopWatch2016_IN_running       ((uint8_T)1U)
#define StopWatch2016_IN_sethours      ((uint8_T)1U)
#define StopWatch2016_IN_setminutes    ((uint8_T)2U)
#define StopWatch2016_IN_silent        ((uint8_T)2U)
#define StopWatch2016_IN_stopped       ((uint8_T)2U)
#define StopWatch2016_IN_swatchmode    ((uint8_T)2U)
#define StopWatch2016_IN_timemode      ((uint8_T)3U)
#define StopWatch2016_IN_timesetmode   ((uint8_T)4U)
#define StopWatch2016_event_Balarm     (5)
#define StopWatch2016_event_BalarmOnOff (7)
#define StopWatch2016_event_Bminus     (2)
#define StopWatch2016_event_Bplus      (1)
#define StopWatch2016_event_Bstop      (6)
#define StopWatch2016_event_Btime      (3)
#define StopWatch2016_event_Btimeset   (4)
#define StopWatch2016_event_ttick      (0)
#define StopWatch201_IN_NO_ACTIVE_CHILD ((uint8_T)0U)

/* Forward declaration for local functions */
static void StopWatch2016_timesetmode(uint8_T *StopWatch2016_Y_hours, uint8_T
  *StopWatch2016_Y_minutes, uint8_T *StopWatch2016_Y_seconds, uint8_T
  *StopWatch2016_Y_tenths, uint8_T *StopWatch2016_Y_mode, boolean_T
  *StopWatch2016_Y_hblink, boolean_T *StopWatch2016_Y_mblink, DW_StopWatch2016_T
  *StopWatch2016_DW);
static void StopWatch2016_alarmmode(uint8_T *StopWatch2016_Y_hours, uint8_T
  *StopWatch2016_Y_minutes, uint8_T *StopWatch2016_Y_seconds, uint8_T
  *StopWatch2016_Y_tenths, uint8_T *StopWatch2016_Y_mode, boolean_T
  *StopWatch2016_Y_hblink, boolean_T *StopWatch2016_Y_mblink, boolean_T
  *StopWatch2016_Y_alarmOn, boolean_T *StopWatch2016_Y_ringing,
  DW_StopWatch2016_T *StopWatch2016_DW);
static void StopWatch_exit_internal_Control(boolean_T *StopWatch2016_Y_hblink,
  boolean_T *StopWatch2016_Y_mblink, DW_StopWatch2016_T *StopWatch2016_DW);
static void StopWatch2016_Control(uint8_T *StopWatch2016_Y_hours, uint8_T
  *StopWatch2016_Y_minutes, uint8_T *StopWatch2016_Y_seconds, uint8_T
  *StopWatch2016_Y_tenths, uint8_T *StopWatch2016_Y_mode, boolean_T
  *StopWatch2016_Y_hblink, boolean_T *StopWatch2016_Y_mblink, boolean_T
  *StopWatch2016_Y_alarmOn, boolean_T *StopWatch2016_Y_ringing,
  DW_StopWatch2016_T *StopWatch2016_DW);
static void Stop_chartstep_c3_StopWatch2016(uint8_T *StopWatch2016_Y_hours,
  uint8_T *StopWatch2016_Y_minutes, uint8_T *StopWatch2016_Y_seconds, uint8_T
  *StopWatch2016_Y_tenths, uint8_T *StopWatch2016_Y_mode, boolean_T
  *StopWatch2016_Y_hblink, boolean_T *StopWatch2016_Y_mblink, boolean_T
  *StopWatch2016_Y_alarmOn, boolean_T *StopWatch2016_Y_ringing,
  DW_StopWatch2016_T *StopWatch2016_DW);

/* Function for Chart: '<S1>/SWatch' */
static void StopWatch2016_timesetmode(uint8_T *StopWatch2016_Y_hours, uint8_T
  *StopWatch2016_Y_minutes, uint8_T *StopWatch2016_Y_seconds, uint8_T
  *StopWatch2016_Y_tenths, uint8_T *StopWatch2016_Y_mode, boolean_T
  *StopWatch2016_Y_hblink, boolean_T *StopWatch2016_Y_mblink, DW_StopWatch2016_T
  *StopWatch2016_DW)
{
  int32_T tmp;
  uint32_T qY;

  /* During 'timesetmode': '<S2>:24' */
  /* '<S2>:47:1' sf_internal_predicateOutput = ... */
  /* '<S2>:47:1' Balarm; */
  switch (StopWatch2016_DW->sfEvent) {
   case StopWatch2016_event_Balarm:
    /* Transition: '<S2>:47' */
    /* Exit Internal 'timesetmode': '<S2>:24' */
    switch (StopWatch2016_DW->is_timesetmode) {
     case StopWatch2016_IN_sethours:
      /* Exit 'sethours': '<S2>:60' */
      /* '<S2>:60:2' hblink= false; */
      *StopWatch2016_Y_hblink = false;
      StopWatch2016_DW->is_timesetmode = StopWatch201_IN_NO_ACTIVE_CHILD;
      break;

     case StopWatch2016_IN_setminutes:
      /* Exit 'setminutes': '<S2>:67' */
      /* '<S2>:67:2' mblink= false; */
      *StopWatch2016_Y_mblink = false;
      StopWatch2016_DW->is_timesetmode = StopWatch201_IN_NO_ACTIVE_CHILD;
      break;
    }

    StopWatch2016_DW->is_Control = StopWatch2016_IN_alarmmode;

    /* Entry 'alarmmode': '<S2>:39' */
    /* '<S2>:39:1' mode=uint8(2) */
    *StopWatch2016_Y_mode = 2U;

    /* Entry Internal 'alarmmode': '<S2>:39' */
    /* Transition: '<S2>:141' */
    StopWatch2016_DW->is_alarmmode = StopWatch2016_IN_sethours;

    /* Entry 'sethours': '<S2>:132' */
    /* '<S2>:132:1' Dhours=Ahours; */
    *StopWatch2016_Y_hours = StopWatch2016_DW->Ahours;

    /* '<S2>:132:1' Dminutes=Aminutes; */
    *StopWatch2016_Y_minutes = StopWatch2016_DW->Aminutes;

    /* '<S2>:132:1' hblink= true; */
    *StopWatch2016_Y_hblink = true;
    break;

   case StopWatch2016_event_Bstop:
    /* '<S2>:75:1' sf_internal_predicateOutput = ... */
    /* '<S2>:75:1' Bstop; */
    /* Transition: '<S2>:75' */
    /* Exit Internal 'timesetmode': '<S2>:24' */
    switch (StopWatch2016_DW->is_timesetmode) {
     case StopWatch2016_IN_sethours:
      /* Exit 'sethours': '<S2>:60' */
      /* '<S2>:60:2' hblink= false; */
      *StopWatch2016_Y_hblink = false;
      StopWatch2016_DW->is_timesetmode = StopWatch201_IN_NO_ACTIVE_CHILD;
      break;

     case StopWatch2016_IN_setminutes:
      /* Exit 'setminutes': '<S2>:67' */
      /* '<S2>:67:2' mblink= false; */
      *StopWatch2016_Y_mblink = false;
      StopWatch2016_DW->is_timesetmode = StopWatch201_IN_NO_ACTIVE_CHILD;
      break;
    }

    StopWatch2016_DW->is_Control = StopWatch2016_IN_swatchmode;

    /* Entry 'swatchmode': '<S2>:40' */
    /* '<S2>:40:1' mode=uint8(3) */
    *StopWatch2016_Y_mode = 3U;

    /* Entry Internal 'swatchmode': '<S2>:40' */
    /* Transition: '<S2>:115' */
    /* Transition: '<S2>:82' */
    /* '<S2>:82:1' SWhours= uint8(0); */
    StopWatch2016_DW->SWhours = 0U;

    /* '<S2>:82:1' SWminutes= uint8(0); */
    StopWatch2016_DW->SWminutes = 0U;

    /* '<S2>:82:1' SWseconds= uint8(0); */
    StopWatch2016_DW->SWseconds = 0U;

    /* '<S2>:82:2' SWtenths= uint8(0); */
    StopWatch2016_DW->SWtenths = 0U;
    StopWatch2016_DW->is_swatchmode = StopWatch2016_IN_stopped;

    /* Entry 'stopped': '<S2>:81' */
    /* '<S2>:81:1' Dhours=SWhours; */
    *StopWatch2016_Y_hours = StopWatch2016_DW->SWhours;

    /* '<S2>:81:1' Dminutes=SWminutes; */
    *StopWatch2016_Y_minutes = StopWatch2016_DW->SWminutes;

    /* '<S2>:81:1' Dseconds=SWseconds; */
    *StopWatch2016_Y_seconds = StopWatch2016_DW->SWseconds;

    /* '<S2>:81:2' Dtenths=SWtenths; */
    *StopWatch2016_Y_tenths = StopWatch2016_DW->SWtenths;
    break;

   default:
    if (StopWatch2016_DW->is_timesetmode == StopWatch2016_IN_sethours) {
      /* During 'sethours': '<S2>:60' */
      /* '<S2>:62:1' sf_internal_predicateOutput = ... */
      /* '<S2>:62:1' Bplus; */
      if (StopWatch2016_DW->sfEvent == StopWatch2016_event_Bplus) {
        /* Transition: '<S2>:62' */
        /* Exit 'sethours': '<S2>:60' */
        /* '<S2>:60:2' hblink= false; */
        /* '<S2>:62:1' hours=mod(hours+1,24) */
        tmp = (int32_T)(StopWatch2016_DW->hours + 1U);
        if ((uint32_T)tmp > 255U) {
          tmp = 255;
        }

        StopWatch2016_DW->hours = (uint8_T)((uint32_T)(uint8_T)tmp - (uint8_T)
          ((uint8_T)tmp / 24U * 24U));
        StopWatch2016_DW->is_timesetmode = StopWatch2016_IN_sethours;

        /* Entry 'sethours': '<S2>:60' */
        /* '<S2>:60:1' Dhours=hours; */
        *StopWatch2016_Y_hours = StopWatch2016_DW->hours;

        /* '<S2>:60:1' Dminutes=minutes; */
        *StopWatch2016_Y_minutes = StopWatch2016_DW->minutes;

        /* '<S2>:60:1' hblink= true; */
        *StopWatch2016_Y_hblink = true;
      } else {
        /* '<S2>:65:1' sf_internal_predicateOutput = ... */
        /* '<S2>:65:1' (Bminus) && (hours==0); */
        if ((StopWatch2016_DW->sfEvent == StopWatch2016_event_Bminus) &&
            (StopWatch2016_DW->hours == 0)) {
          /* Transition: '<S2>:65' */
          /* Exit 'sethours': '<S2>:60' */
          /* '<S2>:60:2' hblink= false; */
          /* '<S2>:65:1' hours= uint8(23) */
          StopWatch2016_DW->hours = 23U;
          StopWatch2016_DW->is_timesetmode = StopWatch2016_IN_sethours;

          /* Entry 'sethours': '<S2>:60' */
          /* '<S2>:60:1' Dhours=hours; */
          *StopWatch2016_Y_hours = StopWatch2016_DW->hours;

          /* '<S2>:60:1' Dminutes=minutes; */
          *StopWatch2016_Y_minutes = StopWatch2016_DW->minutes;

          /* '<S2>:60:1' hblink= true; */
          *StopWatch2016_Y_hblink = true;
        } else {
          /* '<S2>:66:1' sf_internal_predicateOutput = ... */
          /* '<S2>:66:1' Bminus; */
          switch (StopWatch2016_DW->sfEvent) {
           case StopWatch2016_event_Bminus:
            /* Transition: '<S2>:66' */
            /* Exit 'sethours': '<S2>:60' */
            /* '<S2>:60:2' hblink= false; */
            /* '<S2>:66:1' hours = hours - 1 */
            qY = StopWatch2016_DW->hours - /*MW:OvSatOk*/ 1U;
            if (qY > StopWatch2016_DW->hours) {
              qY = 0U;
            }

            StopWatch2016_DW->hours = (uint8_T)qY;
            StopWatch2016_DW->is_timesetmode = StopWatch2016_IN_sethours;

            /* Entry 'sethours': '<S2>:60' */
            /* '<S2>:60:1' Dhours=hours; */
            *StopWatch2016_Y_hours = StopWatch2016_DW->hours;

            /* '<S2>:60:1' Dminutes=minutes; */
            *StopWatch2016_Y_minutes = StopWatch2016_DW->minutes;

            /* '<S2>:60:1' hblink= true; */
            *StopWatch2016_Y_hblink = true;
            break;

           case StopWatch2016_event_Btimeset:
            /* '<S2>:72:1' sf_internal_predicateOutput = ... */
            /* '<S2>:72:1' Btimeset; */
            /* Transition: '<S2>:72' */
            /* Exit 'sethours': '<S2>:60' */
            /* '<S2>:60:2' hblink= false; */
            *StopWatch2016_Y_hblink = false;
            StopWatch2016_DW->is_timesetmode = StopWatch2016_IN_setminutes;

            /* Entry 'setminutes': '<S2>:67' */
            /* '<S2>:67:1' Dminutes=minutes; */
            *StopWatch2016_Y_minutes = StopWatch2016_DW->minutes;

            /* '<S2>:67:1' mblink= true; */
            *StopWatch2016_Y_mblink = true;
            break;
          }
        }
      }
    } else {
      /* During 'setminutes': '<S2>:67' */
      /* '<S2>:68:1' sf_internal_predicateOutput = ... */
      /* '<S2>:68:1' Bplus; */
      if (StopWatch2016_DW->sfEvent == StopWatch2016_event_Bplus) {
        /* Transition: '<S2>:68' */
        /* Exit 'setminutes': '<S2>:67' */
        /* '<S2>:67:2' mblink= false; */
        /* '<S2>:68:1' minutes=mod(minutes+1,60) */
        tmp = (int32_T)(StopWatch2016_DW->minutes + 1U);
        if ((uint32_T)tmp > 255U) {
          tmp = 255;
        }

        StopWatch2016_DW->minutes = (uint8_T)((uint32_T)(uint8_T)tmp - (uint8_T)
          ((uint8_T)tmp / 60U * 60U));
        StopWatch2016_DW->is_timesetmode = StopWatch2016_IN_setminutes;

        /* Entry 'setminutes': '<S2>:67' */
        /* '<S2>:67:1' Dminutes=minutes; */
        *StopWatch2016_Y_minutes = StopWatch2016_DW->minutes;

        /* '<S2>:67:1' mblink= true; */
        *StopWatch2016_Y_mblink = true;
      } else {
        /* '<S2>:70:1' sf_internal_predicateOutput = ... */
        /* '<S2>:70:1' (Bminus) && (minutes==0); */
        if ((StopWatch2016_DW->sfEvent == StopWatch2016_event_Bminus) &&
            (StopWatch2016_DW->minutes == 0)) {
          /* Transition: '<S2>:70' */
          /* Exit 'setminutes': '<S2>:67' */
          /* '<S2>:67:2' mblink= false; */
          /* '<S2>:70:1' minutes= uint8(59) */
          StopWatch2016_DW->minutes = 59U;
          StopWatch2016_DW->is_timesetmode = StopWatch2016_IN_setminutes;

          /* Entry 'setminutes': '<S2>:67' */
          /* '<S2>:67:1' Dminutes=minutes; */
          *StopWatch2016_Y_minutes = StopWatch2016_DW->minutes;

          /* '<S2>:67:1' mblink= true; */
          *StopWatch2016_Y_mblink = true;
        } else {
          /* '<S2>:71:1' sf_internal_predicateOutput = ... */
          /* '<S2>:71:1' Bminus; */
          switch (StopWatch2016_DW->sfEvent) {
           case StopWatch2016_event_Bminus:
            /* Transition: '<S2>:71' */
            /* Exit 'setminutes': '<S2>:67' */
            /* '<S2>:67:2' mblink= false; */
            /* '<S2>:71:1' minutes = minutes - 1 */
            qY = StopWatch2016_DW->minutes - /*MW:OvSatOk*/ 1U;
            if (qY > StopWatch2016_DW->minutes) {
              qY = 0U;
            }

            StopWatch2016_DW->minutes = (uint8_T)qY;
            StopWatch2016_DW->is_timesetmode = StopWatch2016_IN_setminutes;

            /* Entry 'setminutes': '<S2>:67' */
            /* '<S2>:67:1' Dminutes=minutes; */
            *StopWatch2016_Y_minutes = StopWatch2016_DW->minutes;

            /* '<S2>:67:1' mblink= true; */
            *StopWatch2016_Y_mblink = true;
            break;

           case StopWatch2016_event_Btimeset:
            /* '<S2>:127:1' sf_internal_predicateOutput = ... */
            /* '<S2>:127:1' Btimeset; */
            /* Transition: '<S2>:127' */
            /* Exit 'setminutes': '<S2>:67' */
            /* '<S2>:67:2' mblink= false; */
            *StopWatch2016_Y_mblink = false;
            StopWatch2016_DW->is_timesetmode = StopWatch2016_IN_sethours;

            /* Entry 'sethours': '<S2>:60' */
            /* '<S2>:60:1' Dhours=hours; */
            *StopWatch2016_Y_hours = StopWatch2016_DW->hours;

            /* '<S2>:60:1' Dminutes=minutes; */
            *StopWatch2016_Y_minutes = StopWatch2016_DW->minutes;

            /* '<S2>:60:1' hblink= true; */
            *StopWatch2016_Y_hblink = true;
            break;
          }
        }
      }
    }
    break;
  }
}

/* Function for Chart: '<S1>/SWatch' */
static void StopWatch2016_alarmmode(uint8_T *StopWatch2016_Y_hours, uint8_T
  *StopWatch2016_Y_minutes, uint8_T *StopWatch2016_Y_seconds, uint8_T
  *StopWatch2016_Y_tenths, uint8_T *StopWatch2016_Y_mode, boolean_T
  *StopWatch2016_Y_hblink, boolean_T *StopWatch2016_Y_mblink, boolean_T
  *StopWatch2016_Y_alarmOn, boolean_T *StopWatch2016_Y_ringing,
  DW_StopWatch2016_T *StopWatch2016_DW)
{
  int32_T tmp;
  uint32_T qY;

  /* During 'alarmmode': '<S2>:39' */
  /* '<S2>:44:1' sf_internal_predicateOutput = ... */
  /* '<S2>:44:1' Btimeset; */
  switch (StopWatch2016_DW->sfEvent) {
   case StopWatch2016_event_Btimeset:
    /* Transition: '<S2>:44' */
    /* Exit Internal 'alarmmode': '<S2>:39' */
    switch (StopWatch2016_DW->is_alarmmode) {
     case StopWatch2016_IN_sethours:
      /* Exit 'sethours': '<S2>:132' */
      /* '<S2>:132:2' hblink= false; */
      *StopWatch2016_Y_hblink = false;
      StopWatch2016_DW->is_alarmmode = StopWatch201_IN_NO_ACTIVE_CHILD;
      break;

     case StopWatch2016_IN_setminutes:
      /* Exit 'setminutes': '<S2>:137' */
      /* '<S2>:137:2' mblink= false; */
      *StopWatch2016_Y_mblink = false;
      StopWatch2016_DW->is_alarmmode = StopWatch201_IN_NO_ACTIVE_CHILD;
      break;
    }

    StopWatch2016_DW->is_Control = StopWatch2016_IN_timesetmode;

    /* Entry 'timesetmode': '<S2>:24' */
    /* '<S2>:24:1' mode=uint8(1) */
    *StopWatch2016_Y_mode = 1U;

    /* Entry Internal 'timesetmode': '<S2>:24' */
    /* Transition: '<S2>:61' */
    StopWatch2016_DW->is_timesetmode = StopWatch2016_IN_sethours;

    /* Entry 'sethours': '<S2>:60' */
    /* '<S2>:60:1' Dhours=hours; */
    *StopWatch2016_Y_hours = StopWatch2016_DW->hours;

    /* '<S2>:60:1' Dminutes=minutes; */
    *StopWatch2016_Y_minutes = StopWatch2016_DW->minutes;

    /* '<S2>:60:1' hblink= true; */
    *StopWatch2016_Y_hblink = true;
    break;

   case StopWatch2016_event_Bstop:
    /* '<S2>:76:1' sf_internal_predicateOutput = ... */
    /* '<S2>:76:1' Bstop; */
    /* Transition: '<S2>:76' */
    /* Exit Internal 'alarmmode': '<S2>:39' */
    switch (StopWatch2016_DW->is_alarmmode) {
     case StopWatch2016_IN_sethours:
      /* Exit 'sethours': '<S2>:132' */
      /* '<S2>:132:2' hblink= false; */
      *StopWatch2016_Y_hblink = false;
      StopWatch2016_DW->is_alarmmode = StopWatch201_IN_NO_ACTIVE_CHILD;
      break;

     case StopWatch2016_IN_setminutes:
      /* Exit 'setminutes': '<S2>:137' */
      /* '<S2>:137:2' mblink= false; */
      *StopWatch2016_Y_mblink = false;
      StopWatch2016_DW->is_alarmmode = StopWatch201_IN_NO_ACTIVE_CHILD;
      break;
    }

    StopWatch2016_DW->is_Control = StopWatch2016_IN_swatchmode;

    /* Entry 'swatchmode': '<S2>:40' */
    /* '<S2>:40:1' mode=uint8(3) */
    *StopWatch2016_Y_mode = 3U;

    /* Entry Internal 'swatchmode': '<S2>:40' */
    /* Transition: '<S2>:115' */
    /* Transition: '<S2>:82' */
    /* '<S2>:82:1' SWhours= uint8(0); */
    StopWatch2016_DW->SWhours = 0U;

    /* '<S2>:82:1' SWminutes= uint8(0); */
    StopWatch2016_DW->SWminutes = 0U;

    /* '<S2>:82:1' SWseconds= uint8(0); */
    StopWatch2016_DW->SWseconds = 0U;

    /* '<S2>:82:2' SWtenths= uint8(0); */
    StopWatch2016_DW->SWtenths = 0U;
    StopWatch2016_DW->is_swatchmode = StopWatch2016_IN_stopped;

    /* Entry 'stopped': '<S2>:81' */
    /* '<S2>:81:1' Dhours=SWhours; */
    *StopWatch2016_Y_hours = StopWatch2016_DW->SWhours;

    /* '<S2>:81:1' Dminutes=SWminutes; */
    *StopWatch2016_Y_minutes = StopWatch2016_DW->SWminutes;

    /* '<S2>:81:1' Dseconds=SWseconds; */
    *StopWatch2016_Y_seconds = StopWatch2016_DW->SWseconds;

    /* '<S2>:81:2' Dtenths=SWtenths; */
    *StopWatch2016_Y_tenths = StopWatch2016_DW->SWtenths;
    break;

   default:
    /* '<S2>:156:1' sf_internal_predicateOutput = ... */
    /* '<S2>:156:1' (BalarmOnOff) && (alarmOn==false); */
    if ((StopWatch2016_DW->sfEvent == StopWatch2016_event_BalarmOnOff) &&
        (!*StopWatch2016_Y_alarmOn)) {
      /* Transition: '<S2>:156' */
      /* '<S2>:156:1' alarmOn=true */
      *StopWatch2016_Y_alarmOn = true;

      /* Exit Internal 'alarmmode': '<S2>:39' */
      switch (StopWatch2016_DW->is_alarmmode) {
       case StopWatch2016_IN_sethours:
        /* Exit 'sethours': '<S2>:132' */
        /* '<S2>:132:2' hblink= false; */
        *StopWatch2016_Y_hblink = false;
        StopWatch2016_DW->is_alarmmode = StopWatch201_IN_NO_ACTIVE_CHILD;
        break;

       case StopWatch2016_IN_setminutes:
        /* Exit 'setminutes': '<S2>:137' */
        /* '<S2>:137:2' mblink= false; */
        *StopWatch2016_Y_mblink = false;
        StopWatch2016_DW->is_alarmmode = StopWatch201_IN_NO_ACTIVE_CHILD;
        break;
      }

      StopWatch2016_DW->is_Control = StopWatch2016_IN_alarmmode;

      /* Entry 'alarmmode': '<S2>:39' */
      /* '<S2>:39:1' mode=uint8(2) */
      *StopWatch2016_Y_mode = 2U;

      /* Entry Internal 'alarmmode': '<S2>:39' */
      /* Transition: '<S2>:141' */
      StopWatch2016_DW->is_alarmmode = StopWatch2016_IN_sethours;

      /* Entry 'sethours': '<S2>:132' */
      /* '<S2>:132:1' Dhours=Ahours; */
      *StopWatch2016_Y_hours = StopWatch2016_DW->Ahours;

      /* '<S2>:132:1' Dminutes=Aminutes; */
      *StopWatch2016_Y_minutes = StopWatch2016_DW->Aminutes;

      /* '<S2>:132:1' hblink= true; */
      *StopWatch2016_Y_hblink = true;
    } else {
      /* '<S2>:157:1' sf_internal_predicateOutput = ... */
      /* '<S2>:157:1' BalarmOnOff; */
      if (StopWatch2016_DW->sfEvent == StopWatch2016_event_BalarmOnOff) {
        /* Transition: '<S2>:157' */
        /* '<S2>:157:1' alarmOn=false; */
        *StopWatch2016_Y_alarmOn = false;

        /* '<S2>:157:1' ringing=false; */
        *StopWatch2016_Y_ringing = false;

        /* Exit Internal 'alarmmode': '<S2>:39' */
        switch (StopWatch2016_DW->is_alarmmode) {
         case StopWatch2016_IN_sethours:
          /* Exit 'sethours': '<S2>:132' */
          /* '<S2>:132:2' hblink= false; */
          *StopWatch2016_Y_hblink = false;
          StopWatch2016_DW->is_alarmmode = StopWatch201_IN_NO_ACTIVE_CHILD;
          break;

         case StopWatch2016_IN_setminutes:
          /* Exit 'setminutes': '<S2>:137' */
          /* '<S2>:137:2' mblink= false; */
          *StopWatch2016_Y_mblink = false;
          StopWatch2016_DW->is_alarmmode = StopWatch201_IN_NO_ACTIVE_CHILD;
          break;
        }

        StopWatch2016_DW->is_Control = StopWatch2016_IN_alarmmode;

        /* Entry 'alarmmode': '<S2>:39' */
        /* '<S2>:39:1' mode=uint8(2) */
        *StopWatch2016_Y_mode = 2U;

        /* Entry Internal 'alarmmode': '<S2>:39' */
        /* Transition: '<S2>:141' */
        StopWatch2016_DW->is_alarmmode = StopWatch2016_IN_sethours;

        /* Entry 'sethours': '<S2>:132' */
        /* '<S2>:132:1' Dhours=Ahours; */
        *StopWatch2016_Y_hours = StopWatch2016_DW->Ahours;

        /* '<S2>:132:1' Dminutes=Aminutes; */
        *StopWatch2016_Y_minutes = StopWatch2016_DW->Aminutes;

        /* '<S2>:132:1' hblink= true; */
        *StopWatch2016_Y_hblink = true;
      } else if (StopWatch2016_DW->is_alarmmode == StopWatch2016_IN_sethours) {
        /* During 'sethours': '<S2>:132' */
        /* '<S2>:131:1' sf_internal_predicateOutput = ... */
        /* '<S2>:131:1' Bplus; */
        if (StopWatch2016_DW->sfEvent == StopWatch2016_event_Bplus) {
          /* Transition: '<S2>:131' */
          /* Exit 'sethours': '<S2>:132' */
          /* '<S2>:132:2' hblink= false; */
          /* '<S2>:131:1' Ahours=mod(Ahours+1,24) */
          tmp = (int32_T)(StopWatch2016_DW->Ahours + 1U);
          if ((uint32_T)tmp > 255U) {
            tmp = 255;
          }

          StopWatch2016_DW->Ahours = (uint8_T)((uint32_T)(uint8_T)tmp - (uint8_T)
            ((uint8_T)tmp / 24U * 24U));
          StopWatch2016_DW->is_alarmmode = StopWatch2016_IN_sethours;

          /* Entry 'sethours': '<S2>:132' */
          /* '<S2>:132:1' Dhours=Ahours; */
          *StopWatch2016_Y_hours = StopWatch2016_DW->Ahours;

          /* '<S2>:132:1' Dminutes=Aminutes; */
          *StopWatch2016_Y_minutes = StopWatch2016_DW->Aminutes;

          /* '<S2>:132:1' hblink= true; */
          *StopWatch2016_Y_hblink = true;
        } else {
          /* '<S2>:138:1' sf_internal_predicateOutput = ... */
          /* '<S2>:138:1' (Bminus) && (Ahours==0); */
          if ((StopWatch2016_DW->sfEvent == StopWatch2016_event_Bminus) &&
              (StopWatch2016_DW->Ahours == 0)) {
            /* Transition: '<S2>:138' */
            /* Exit 'sethours': '<S2>:132' */
            /* '<S2>:132:2' hblink= false; */
            /* '<S2>:138:1' Ahours= uint8(23) */
            StopWatch2016_DW->Ahours = 23U;
            StopWatch2016_DW->is_alarmmode = StopWatch2016_IN_sethours;

            /* Entry 'sethours': '<S2>:132' */
            /* '<S2>:132:1' Dhours=Ahours; */
            *StopWatch2016_Y_hours = StopWatch2016_DW->Ahours;

            /* '<S2>:132:1' Dminutes=Aminutes; */
            *StopWatch2016_Y_minutes = StopWatch2016_DW->Aminutes;

            /* '<S2>:132:1' hblink= true; */
            *StopWatch2016_Y_hblink = true;
          } else {
            /* '<S2>:133:1' sf_internal_predicateOutput = ... */
            /* '<S2>:133:1' Bminus; */
            switch (StopWatch2016_DW->sfEvent) {
             case StopWatch2016_event_Bminus:
              /* Transition: '<S2>:133' */
              /* Exit 'sethours': '<S2>:132' */
              /* '<S2>:132:2' hblink= false; */
              /* '<S2>:133:1' Ahours = Ahours - 1 */
              qY = StopWatch2016_DW->Ahours - /*MW:OvSatOk*/ 1U;
              if (qY > StopWatch2016_DW->Ahours) {
                qY = 0U;
              }

              StopWatch2016_DW->Ahours = (uint8_T)qY;
              StopWatch2016_DW->is_alarmmode = StopWatch2016_IN_sethours;

              /* Entry 'sethours': '<S2>:132' */
              /* '<S2>:132:1' Dhours=Ahours; */
              *StopWatch2016_Y_hours = StopWatch2016_DW->Ahours;

              /* '<S2>:132:1' Dminutes=Aminutes; */
              *StopWatch2016_Y_minutes = StopWatch2016_DW->Aminutes;

              /* '<S2>:132:1' hblink= true; */
              *StopWatch2016_Y_hblink = true;
              break;

             case StopWatch2016_event_Balarm:
              /* '<S2>:139:1' sf_internal_predicateOutput = ... */
              /* '<S2>:139:1' Balarm; */
              /* Transition: '<S2>:139' */
              /* Exit 'sethours': '<S2>:132' */
              /* '<S2>:132:2' hblink= false; */
              *StopWatch2016_Y_hblink = false;
              StopWatch2016_DW->is_alarmmode = StopWatch2016_IN_setminutes;

              /* Entry 'setminutes': '<S2>:137' */
              /* '<S2>:137:1' Dminutes=Aminutes; */
              *StopWatch2016_Y_minutes = StopWatch2016_DW->Aminutes;

              /* '<S2>:137:1' mblink= true; */
              *StopWatch2016_Y_mblink = true;
              break;
            }
          }
        }
      } else {
        /* During 'setminutes': '<S2>:137' */
        /* '<S2>:140:1' sf_internal_predicateOutput = ... */
        /* '<S2>:140:1' Bplus; */
        if (StopWatch2016_DW->sfEvent == StopWatch2016_event_Bplus) {
          /* Transition: '<S2>:140' */
          /* Exit 'setminutes': '<S2>:137' */
          /* '<S2>:137:2' mblink= false; */
          /* '<S2>:140:1' Aminutes=mod(Aminutes+1,60) */
          tmp = (int32_T)(StopWatch2016_DW->Aminutes + 1U);
          if ((uint32_T)tmp > 255U) {
            tmp = 255;
          }

          StopWatch2016_DW->Aminutes = (uint8_T)((uint32_T)(uint8_T)tmp -
            (uint8_T)((uint8_T)tmp / 60U * 60U));
          StopWatch2016_DW->is_alarmmode = StopWatch2016_IN_setminutes;

          /* Entry 'setminutes': '<S2>:137' */
          /* '<S2>:137:1' Dminutes=Aminutes; */
          *StopWatch2016_Y_minutes = StopWatch2016_DW->Aminutes;

          /* '<S2>:137:1' mblink= true; */
          *StopWatch2016_Y_mblink = true;
        } else {
          /* '<S2>:136:1' sf_internal_predicateOutput = ... */
          /* '<S2>:136:1' (Bminus) && (Aminutes==0); */
          if ((StopWatch2016_DW->sfEvent == StopWatch2016_event_Bminus) &&
              (StopWatch2016_DW->Aminutes == 0)) {
            /* Transition: '<S2>:136' */
            /* Exit 'setminutes': '<S2>:137' */
            /* '<S2>:137:2' mblink= false; */
            /* '<S2>:136:1' Aminutes= uint8(59) */
            StopWatch2016_DW->Aminutes = 59U;
            StopWatch2016_DW->is_alarmmode = StopWatch2016_IN_setminutes;

            /* Entry 'setminutes': '<S2>:137' */
            /* '<S2>:137:1' Dminutes=Aminutes; */
            *StopWatch2016_Y_minutes = StopWatch2016_DW->Aminutes;

            /* '<S2>:137:1' mblink= true; */
            *StopWatch2016_Y_mblink = true;
          } else {
            /* '<S2>:134:1' sf_internal_predicateOutput = ... */
            /* '<S2>:134:1' Bminus; */
            switch (StopWatch2016_DW->sfEvent) {
             case StopWatch2016_event_Bminus:
              /* Transition: '<S2>:134' */
              /* Exit 'setminutes': '<S2>:137' */
              /* '<S2>:137:2' mblink= false; */
              /* '<S2>:134:1' Aminutes = Aminutes - 1 */
              qY = StopWatch2016_DW->Aminutes - /*MW:OvSatOk*/ 1U;
              if (qY > StopWatch2016_DW->Aminutes) {
                qY = 0U;
              }

              StopWatch2016_DW->Aminutes = (uint8_T)qY;
              StopWatch2016_DW->is_alarmmode = StopWatch2016_IN_setminutes;

              /* Entry 'setminutes': '<S2>:137' */
              /* '<S2>:137:1' Dminutes=Aminutes; */
              *StopWatch2016_Y_minutes = StopWatch2016_DW->Aminutes;

              /* '<S2>:137:1' mblink= true; */
              *StopWatch2016_Y_mblink = true;
              break;

             case StopWatch2016_event_Balarm:
              /* '<S2>:135:1' sf_internal_predicateOutput = ... */
              /* '<S2>:135:1' Balarm; */
              /* Transition: '<S2>:135' */
              /* Exit 'setminutes': '<S2>:137' */
              /* '<S2>:137:2' mblink= false; */
              *StopWatch2016_Y_mblink = false;
              StopWatch2016_DW->is_alarmmode = StopWatch2016_IN_sethours;

              /* Entry 'sethours': '<S2>:132' */
              /* '<S2>:132:1' Dhours=Ahours; */
              *StopWatch2016_Y_hours = StopWatch2016_DW->Ahours;

              /* '<S2>:132:1' Dminutes=Aminutes; */
              *StopWatch2016_Y_minutes = StopWatch2016_DW->Aminutes;

              /* '<S2>:132:1' hblink= true; */
              *StopWatch2016_Y_hblink = true;
              break;
            }
          }
        }
      }
    }
    break;
  }
}

/* Function for Chart: '<S1>/SWatch' */
static void StopWatch_exit_internal_Control(boolean_T *StopWatch2016_Y_hblink,
  boolean_T *StopWatch2016_Y_mblink, DW_StopWatch2016_T *StopWatch2016_DW)
{
  /* Exit Internal 'Control': '<S2>:13' */
  switch (StopWatch2016_DW->is_Control) {
   case StopWatch2016_IN_alarmmode:
    /* Exit Internal 'alarmmode': '<S2>:39' */
    switch (StopWatch2016_DW->is_alarmmode) {
     case StopWatch2016_IN_sethours:
      /* Exit 'sethours': '<S2>:132' */
      /* '<S2>:132:2' hblink= false; */
      *StopWatch2016_Y_hblink = false;
      StopWatch2016_DW->is_alarmmode = StopWatch201_IN_NO_ACTIVE_CHILD;
      break;

     case StopWatch2016_IN_setminutes:
      /* Exit 'setminutes': '<S2>:137' */
      /* '<S2>:137:2' mblink= false; */
      *StopWatch2016_Y_mblink = false;
      StopWatch2016_DW->is_alarmmode = StopWatch201_IN_NO_ACTIVE_CHILD;
      break;
    }

    StopWatch2016_DW->is_Control = StopWatch201_IN_NO_ACTIVE_CHILD;
    break;

   case StopWatch2016_IN_timesetmode:
    /* Exit Internal 'timesetmode': '<S2>:24' */
    switch (StopWatch2016_DW->is_timesetmode) {
     case StopWatch2016_IN_sethours:
      /* Exit 'sethours': '<S2>:60' */
      /* '<S2>:60:2' hblink= false; */
      *StopWatch2016_Y_hblink = false;
      StopWatch2016_DW->is_timesetmode = StopWatch201_IN_NO_ACTIVE_CHILD;
      break;

     case StopWatch2016_IN_setminutes:
      /* Exit 'setminutes': '<S2>:67' */
      /* '<S2>:67:2' mblink= false; */
      *StopWatch2016_Y_mblink = false;
      StopWatch2016_DW->is_timesetmode = StopWatch201_IN_NO_ACTIVE_CHILD;
      break;
    }

    StopWatch2016_DW->is_Control = StopWatch201_IN_NO_ACTIVE_CHILD;
    break;

   default:
    /* Exit Internal 'swatchmode': '<S2>:40' */
    /* Exit Internal 'running': '<S2>:83' */
    StopWatch2016_DW->is_swatchmode = StopWatch201_IN_NO_ACTIVE_CHILD;
    StopWatch2016_DW->is_Control = StopWatch201_IN_NO_ACTIVE_CHILD;
    break;
  }
}

/* Function for Chart: '<S1>/SWatch' */
static void StopWatch2016_Control(uint8_T *StopWatch2016_Y_hours, uint8_T
  *StopWatch2016_Y_minutes, uint8_T *StopWatch2016_Y_seconds, uint8_T
  *StopWatch2016_Y_tenths, uint8_T *StopWatch2016_Y_mode, boolean_T
  *StopWatch2016_Y_hblink, boolean_T *StopWatch2016_Y_mblink, boolean_T
  *StopWatch2016_Y_alarmOn, boolean_T *StopWatch2016_Y_ringing,
  DW_StopWatch2016_T *StopWatch2016_DW)
{
  int32_T tmp;

  /* During 'Control': '<S2>:13' */
  /* '<S2>:45:1' sf_internal_predicateOutput = ... */
  /* '<S2>:45:1' Btime; */
  if (StopWatch2016_DW->sfEvent == StopWatch2016_event_Btime) {
    /* Transition: '<S2>:45' */
    StopWatch_exit_internal_Control(StopWatch2016_Y_hblink,
      StopWatch2016_Y_mblink, StopWatch2016_DW);
    StopWatch2016_DW->is_Control = StopWatch2016_IN_timemode;

    /* Entry 'timemode': '<S2>:23' */
    /* '<S2>:23:1' mode=uint8(0) */
    *StopWatch2016_Y_mode = 0U;
  } else {
    switch (StopWatch2016_DW->is_Control) {
     case StopWatch2016_IN_alarmmode:
      StopWatch2016_alarmmode(StopWatch2016_Y_hours, StopWatch2016_Y_minutes,
        StopWatch2016_Y_seconds, StopWatch2016_Y_tenths, StopWatch2016_Y_mode,
        StopWatch2016_Y_hblink, StopWatch2016_Y_mblink, StopWatch2016_Y_alarmOn,
        StopWatch2016_Y_ringing, StopWatch2016_DW);
      break;

     case StopWatch2016_IN_swatchmode:
      /* During 'swatchmode': '<S2>:40' */
      /* '<S2>:43:1' sf_internal_predicateOutput = ... */
      /* '<S2>:43:1' Btimeset; */
      switch (StopWatch2016_DW->sfEvent) {
       case StopWatch2016_event_Btimeset:
        /* Transition: '<S2>:43' */
        /* Exit Internal 'swatchmode': '<S2>:40' */
        /* Exit Internal 'running': '<S2>:83' */
        StopWatch2016_DW->is_swatchmode = StopWatch201_IN_NO_ACTIVE_CHILD;
        StopWatch2016_DW->is_Control = StopWatch2016_IN_timesetmode;

        /* Entry 'timesetmode': '<S2>:24' */
        /* '<S2>:24:1' mode=uint8(1) */
        *StopWatch2016_Y_mode = 1U;

        /* Entry Internal 'timesetmode': '<S2>:24' */
        /* Transition: '<S2>:61' */
        StopWatch2016_DW->is_timesetmode = StopWatch2016_IN_sethours;

        /* Entry 'sethours': '<S2>:60' */
        /* '<S2>:60:1' Dhours=hours; */
        *StopWatch2016_Y_hours = StopWatch2016_DW->hours;

        /* '<S2>:60:1' Dminutes=minutes; */
        *StopWatch2016_Y_minutes = StopWatch2016_DW->minutes;

        /* '<S2>:60:1' hblink= true; */
        *StopWatch2016_Y_hblink = true;
        break;

       case StopWatch2016_event_Balarm:
        /* '<S2>:128:1' sf_internal_predicateOutput = ... */
        /* '<S2>:128:1' Balarm; */
        /* Transition: '<S2>:128' */
        /* Exit Internal 'swatchmode': '<S2>:40' */
        /* Exit Internal 'running': '<S2>:83' */
        StopWatch2016_DW->is_swatchmode = StopWatch201_IN_NO_ACTIVE_CHILD;
        StopWatch2016_DW->is_Control = StopWatch2016_IN_alarmmode;

        /* Entry 'alarmmode': '<S2>:39' */
        /* '<S2>:39:1' mode=uint8(2) */
        *StopWatch2016_Y_mode = 2U;

        /* Entry Internal 'alarmmode': '<S2>:39' */
        /* Transition: '<S2>:141' */
        StopWatch2016_DW->is_alarmmode = StopWatch2016_IN_sethours;

        /* Entry 'sethours': '<S2>:132' */
        /* '<S2>:132:1' Dhours=Ahours; */
        *StopWatch2016_Y_hours = StopWatch2016_DW->Ahours;

        /* '<S2>:132:1' Dminutes=Aminutes; */
        *StopWatch2016_Y_minutes = StopWatch2016_DW->Aminutes;

        /* '<S2>:132:1' hblink= true; */
        *StopWatch2016_Y_hblink = true;
        break;

       case StopWatch2016_event_Bstop:
        /* '<S2>:114:1' sf_internal_predicateOutput = ... */
        /* '<S2>:114:1' Bstop; */
        /* Transition: '<S2>:114' */
        /* Transition: '<S2>:82' */
        /* '<S2>:82:1' SWhours= uint8(0); */
        StopWatch2016_DW->SWhours = 0U;

        /* '<S2>:82:1' SWminutes= uint8(0); */
        StopWatch2016_DW->SWminutes = 0U;

        /* '<S2>:82:1' SWseconds= uint8(0); */
        StopWatch2016_DW->SWseconds = 0U;

        /* '<S2>:82:2' SWtenths= uint8(0); */
        StopWatch2016_DW->SWtenths = 0U;

        /* Exit Internal 'swatchmode': '<S2>:40' */
        /* Exit Internal 'running': '<S2>:83' */
        StopWatch2016_DW->is_swatchmode = StopWatch2016_IN_stopped;

        /* Entry 'stopped': '<S2>:81' */
        /* '<S2>:81:1' Dhours=SWhours; */
        *StopWatch2016_Y_hours = StopWatch2016_DW->SWhours;

        /* '<S2>:81:1' Dminutes=SWminutes; */
        *StopWatch2016_Y_minutes = StopWatch2016_DW->SWminutes;

        /* '<S2>:81:1' Dseconds=SWseconds; */
        *StopWatch2016_Y_seconds = StopWatch2016_DW->SWseconds;

        /* '<S2>:81:2' Dtenths=SWtenths; */
        *StopWatch2016_Y_tenths = StopWatch2016_DW->SWtenths;
        break;

       default:
        if (StopWatch2016_DW->is_swatchmode == StopWatch2016_IN_running) {
          /* During 'running': '<S2>:83' */
          /* '<S2>:111:1' sf_internal_predicateOutput = ... */
          /* '<S2>:111:1' (Bminus) && (lapmode==false); */
          if ((StopWatch2016_DW->sfEvent == StopWatch2016_event_Bminus) &&
              (!StopWatch2016_DW->lapmode)) {
            /* Transition: '<S2>:111' */
            /* '<S2>:111:1' lapmode= true */
            StopWatch2016_DW->lapmode = true;

            /* Exit Internal 'running': '<S2>:83' */
            StopWatch2016_DW->is_swatchmode = StopWatch2016_IN_running;

            /* Entry Internal 'running': '<S2>:83' */
            /* Transition: '<S2>:88' */
          } else {
            /* '<S2>:144:1' sf_internal_predicateOutput = ... */
            /* '<S2>:144:1' Bminus; */
            if (StopWatch2016_DW->sfEvent == StopWatch2016_event_Bminus) {
              /* Transition: '<S2>:144' */
              /* '<S2>:144:1' lapmode= false */
              StopWatch2016_DW->lapmode = false;

              /* Exit Internal 'running': '<S2>:83' */
              StopWatch2016_DW->is_swatchmode = StopWatch2016_IN_running;

              /* Entry Internal 'running': '<S2>:83' */
              /* Transition: '<S2>:88' */
            } else {
              /* '<S2>:147:1' sf_internal_predicateOutput = ... */
              /* '<S2>:147:1' (Bplus) && (lapmode==true); */
              if ((StopWatch2016_DW->sfEvent == StopWatch2016_event_Bplus) &&
                  StopWatch2016_DW->lapmode) {
                /* Transition: '<S2>:147' */
                /* '<S2>:147:1' lapmode= false */
                StopWatch2016_DW->lapmode = false;

                /* Exit Internal 'running': '<S2>:83' */
                StopWatch2016_DW->is_swatchmode = StopWatch2016_IN_running;

                /* Entry Internal 'running': '<S2>:83' */
                /* Transition: '<S2>:88' */
              } else {
                /* '<S2>:86:1' sf_internal_predicateOutput = ... */
                /* '<S2>:86:1' Bplus; */
                if (StopWatch2016_DW->sfEvent == StopWatch2016_event_Bplus) {
                  /* Transition: '<S2>:86' */
                  /* '<S2>:86:1' lapmode= true; */
                  StopWatch2016_DW->lapmode = true;

                  /* Exit Internal 'running': '<S2>:83' */
                  StopWatch2016_DW->is_swatchmode = StopWatch2016_IN_stopped;

                  /* Entry 'stopped': '<S2>:81' */
                  /* '<S2>:81:1' Dhours=SWhours; */
                  *StopWatch2016_Y_hours = StopWatch2016_DW->SWhours;

                  /* '<S2>:81:1' Dminutes=SWminutes; */
                  *StopWatch2016_Y_minutes = StopWatch2016_DW->SWminutes;

                  /* '<S2>:81:1' Dseconds=SWseconds; */
                  *StopWatch2016_Y_seconds = StopWatch2016_DW->SWseconds;

                  /* '<S2>:81:2' Dtenths=SWtenths; */
                  *StopWatch2016_Y_tenths = StopWatch2016_DW->SWtenths;
                } else {
                  /* '<S2>:83:1' if(lapmode==false) */
                  if (!StopWatch2016_DW->lapmode) {
                    /* '<S2>:83:1' Dhours=SWhours; */
                    *StopWatch2016_Y_hours = StopWatch2016_DW->SWhours;

                    /* '<S2>:83:1' Dminutes=SWminutes; */
                    *StopWatch2016_Y_minutes = StopWatch2016_DW->SWminutes;

                    /* '<S2>:83:2' Dseconds=SWseconds; */
                    *StopWatch2016_Y_seconds = StopWatch2016_DW->SWseconds;

                    /* '<S2>:83:2' Dtenths=SWtenths; */
                    *StopWatch2016_Y_tenths = StopWatch2016_DW->SWtenths;
                  }

                  /* During 'counting': '<S2>:87' */
                  /* '<S2>:90:1' sf_internal_predicateOutput = ... */
                  /* '<S2>:90:1' ttick; */
                  if (StopWatch2016_DW->sfEvent == StopWatch2016_event_ttick) {
                    /* Transition: '<S2>:90' */
                    /* '<S2>:90:1' SWtenths = mod(SWtenths + 1,10) */
                    tmp = (int32_T)(StopWatch2016_DW->SWtenths + 1U);
                    if ((uint32_T)tmp > 255U) {
                      tmp = 255;
                    }

                    StopWatch2016_DW->SWtenths = (uint8_T)((uint32_T)(uint8_T)
                      tmp - (uint8_T)((uint8_T)tmp / 10U * 10U));

                    /* '<S2>:92:1' sf_internal_predicateOutput = ... */
                    /* '<S2>:92:1' SWtenths==0; */
                    if (StopWatch2016_DW->SWtenths == 0) {
                      /* Transition: '<S2>:92' */
                      /* '<S2>:92:1' SWseconds=mod(SWseconds+1,60) */
                      tmp = (int32_T)(StopWatch2016_DW->SWseconds + 1U);
                      if ((uint32_T)tmp > 255U) {
                        tmp = 255;
                      }

                      StopWatch2016_DW->SWseconds = (uint8_T)((uint32_T)(uint8_T)
                        tmp - (uint8_T)((uint8_T)tmp / 60U * 60U));

                      /* '<S2>:94:1' sf_internal_predicateOutput = ... */
                      /* '<S2>:94:1' SWseconds==0; */
                      if (StopWatch2016_DW->SWseconds == 0) {
                        /* Transition: '<S2>:94' */
                        /* '<S2>:94:1' SWminutes=mod(SWminutes+1,60) */
                        tmp = (int32_T)(StopWatch2016_DW->SWminutes + 1U);
                        if ((uint32_T)tmp > 255U) {
                          tmp = 255;
                        }

                        StopWatch2016_DW->SWminutes = (uint8_T)((uint32_T)
                          (uint8_T)tmp - (uint8_T)((uint8_T)tmp / 60U * 60U));

                        /* '<S2>:96:1' sf_internal_predicateOutput = ... */
                        /* '<S2>:96:1' SWminutes==0; */
                        if (StopWatch2016_DW->SWminutes == 0) {
                          /* Transition: '<S2>:96' */
                          /* '<S2>:96:1' SWhours=mod(SWhours+1,60) */
                          tmp = (int32_T)(StopWatch2016_DW->SWhours + 1U);
                          if ((uint32_T)tmp > 255U) {
                            tmp = 255;
                          }

                          StopWatch2016_DW->SWhours = (uint8_T)((uint32_T)
                            (uint8_T)tmp - (uint8_T)((uint8_T)tmp / 60U * 60U));

                          /* Transition: '<S2>:97' */
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        } else {
          /* During 'stopped': '<S2>:81' */
          /* '<S2>:84:1' sf_internal_predicateOutput = ... */
          /* '<S2>:84:1' Bplus; */
          if (StopWatch2016_DW->sfEvent == StopWatch2016_event_Bplus) {
            /* Transition: '<S2>:84' */
            /* '<S2>:84:1' lapmode= false; */
            StopWatch2016_DW->lapmode = false;
            StopWatch2016_DW->is_swatchmode = StopWatch2016_IN_running;

            /* Entry Internal 'running': '<S2>:83' */
            /* Transition: '<S2>:88' */
          }
        }
        break;
      }
      break;

     case StopWatch2016_IN_timemode:
      /* During 'timemode': '<S2>:23' */
      /* '<S2>:26:1' sf_internal_predicateOutput = ... */
      /* '<S2>:26:1' Btimeset; */
      switch (StopWatch2016_DW->sfEvent) {
       case StopWatch2016_event_Btimeset:
        /* Transition: '<S2>:26' */
        StopWatch2016_DW->is_Control = StopWatch2016_IN_timesetmode;

        /* Entry 'timesetmode': '<S2>:24' */
        /* '<S2>:24:1' mode=uint8(1) */
        *StopWatch2016_Y_mode = 1U;

        /* Entry Internal 'timesetmode': '<S2>:24' */
        /* Transition: '<S2>:61' */
        StopWatch2016_DW->is_timesetmode = StopWatch2016_IN_sethours;

        /* Entry 'sethours': '<S2>:60' */
        /* '<S2>:60:1' Dhours=hours; */
        *StopWatch2016_Y_hours = StopWatch2016_DW->hours;

        /* '<S2>:60:1' Dminutes=minutes; */
        *StopWatch2016_Y_minutes = StopWatch2016_DW->minutes;

        /* '<S2>:60:1' hblink= true; */
        *StopWatch2016_Y_hblink = true;
        break;

       case StopWatch2016_event_Bstop:
        /* '<S2>:50:1' sf_internal_predicateOutput = ... */
        /* '<S2>:50:1' Bstop; */
        /* Transition: '<S2>:50' */
        StopWatch2016_DW->is_Control = StopWatch2016_IN_swatchmode;

        /* Entry 'swatchmode': '<S2>:40' */
        /* '<S2>:40:1' mode=uint8(3) */
        *StopWatch2016_Y_mode = 3U;

        /* Entry Internal 'swatchmode': '<S2>:40' */
        /* Transition: '<S2>:115' */
        /* Transition: '<S2>:82' */
        /* '<S2>:82:1' SWhours= uint8(0); */
        StopWatch2016_DW->SWhours = 0U;

        /* '<S2>:82:1' SWminutes= uint8(0); */
        StopWatch2016_DW->SWminutes = 0U;

        /* '<S2>:82:1' SWseconds= uint8(0); */
        StopWatch2016_DW->SWseconds = 0U;

        /* '<S2>:82:2' SWtenths= uint8(0); */
        StopWatch2016_DW->SWtenths = 0U;
        StopWatch2016_DW->is_swatchmode = StopWatch2016_IN_stopped;

        /* Entry 'stopped': '<S2>:81' */
        /* '<S2>:81:1' Dhours=SWhours; */
        *StopWatch2016_Y_hours = StopWatch2016_DW->SWhours;

        /* '<S2>:81:1' Dminutes=SWminutes; */
        *StopWatch2016_Y_minutes = StopWatch2016_DW->SWminutes;

        /* '<S2>:81:1' Dseconds=SWseconds; */
        *StopWatch2016_Y_seconds = StopWatch2016_DW->SWseconds;

        /* '<S2>:81:2' Dtenths=SWtenths; */
        *StopWatch2016_Y_tenths = StopWatch2016_DW->SWtenths;
        break;

       case StopWatch2016_event_Balarm:
        /* '<S2>:130:1' sf_internal_predicateOutput = ... */
        /* '<S2>:130:1' Balarm; */
        /* Transition: '<S2>:130' */
        StopWatch2016_DW->is_Control = StopWatch2016_IN_alarmmode;

        /* Entry 'alarmmode': '<S2>:39' */
        /* '<S2>:39:1' mode=uint8(2) */
        *StopWatch2016_Y_mode = 2U;

        /* Entry Internal 'alarmmode': '<S2>:39' */
        /* Transition: '<S2>:141' */
        StopWatch2016_DW->is_alarmmode = StopWatch2016_IN_sethours;

        /* Entry 'sethours': '<S2>:132' */
        /* '<S2>:132:1' Dhours=Ahours; */
        *StopWatch2016_Y_hours = StopWatch2016_DW->Ahours;

        /* '<S2>:132:1' Dminutes=Aminutes; */
        *StopWatch2016_Y_minutes = StopWatch2016_DW->Aminutes;

        /* '<S2>:132:1' hblink= true; */
        *StopWatch2016_Y_hblink = true;
        break;

       case StopWatch2016_event_ttick:
        /* '<S2>:58:1' sf_internal_predicateOutput = ... */
        /* '<S2>:58:1' ttick; */
        /* Transition: '<S2>:58' */
        /* '<S2>:58:1' Dhours=hours; */
        *StopWatch2016_Y_hours = StopWatch2016_DW->hours;

        /* '<S2>:58:1' Dminutes=minutes; */
        *StopWatch2016_Y_minutes = StopWatch2016_DW->minutes;

        /* '<S2>:58:1' Dseconds=seconds */
        *StopWatch2016_Y_seconds = StopWatch2016_DW->seconds;
        break;
      }
      break;

     default:
      StopWatch2016_timesetmode(StopWatch2016_Y_hours, StopWatch2016_Y_minutes,
        StopWatch2016_Y_seconds, StopWatch2016_Y_tenths, StopWatch2016_Y_mode,
        StopWatch2016_Y_hblink, StopWatch2016_Y_mblink, StopWatch2016_DW);
      break;
    }
  }
}

/* Function for Chart: '<S1>/SWatch' */
static void Stop_chartstep_c3_StopWatch2016(uint8_T *StopWatch2016_Y_hours,
  uint8_T *StopWatch2016_Y_minutes, uint8_T *StopWatch2016_Y_seconds, uint8_T
  *StopWatch2016_Y_tenths, uint8_T *StopWatch2016_Y_mode, boolean_T
  *StopWatch2016_Y_hblink, boolean_T *StopWatch2016_Y_mblink, boolean_T
  *StopWatch2016_Y_alarmOn, boolean_T *StopWatch2016_Y_ringing,
  DW_StopWatch2016_T *StopWatch2016_DW)
{
  int32_T tmp;

  /* During: StopWatch2016/SWatch */
  StopWatch2016_Control(StopWatch2016_Y_hours, StopWatch2016_Y_minutes,
                        StopWatch2016_Y_seconds, StopWatch2016_Y_tenths,
                        StopWatch2016_Y_mode, StopWatch2016_Y_hblink,
                        StopWatch2016_Y_mblink, StopWatch2016_Y_alarmOn,
                        StopWatch2016_Y_ringing, StopWatch2016_DW);

  /* During 'TimeCount': '<S2>:14' */
  /* During 'timecount': '<S2>:17' */
  /* '<S2>:21:1' sf_internal_predicateOutput = ... */
  /* '<S2>:21:1' ttick; */
  if (StopWatch2016_DW->sfEvent == StopWatch2016_event_ttick) {
    /* Transition: '<S2>:21' */
    /* '<S2>:21:1' tenths=mod(tenths+1,10) */
    tmp = (int32_T)(StopWatch2016_DW->tenths + 1U);
    if ((uint32_T)tmp > 255U) {
      tmp = 255;
    }

    StopWatch2016_DW->tenths = (uint8_T)((uint32_T)(uint8_T)tmp - (uint8_T)
      ((uint8_T)tmp / 10U * 10U));

    /* '<S2>:29:1' sf_internal_predicateOutput = ... */
    /* '<S2>:29:1' tenths==0; */
    if (StopWatch2016_DW->tenths == 0) {
      /* Transition: '<S2>:29' */
      /* '<S2>:29:1' seconds=mod(seconds+1, 60) */
      tmp = (int32_T)(StopWatch2016_DW->seconds + 1U);
      if ((uint32_T)tmp > 255U) {
        tmp = 255;
      }

      StopWatch2016_DW->seconds = (uint8_T)((uint32_T)(uint8_T)tmp - (uint8_T)
        ((uint8_T)tmp / 60U * 60U));

      /* '<S2>:32:1' sf_internal_predicateOutput = ... */
      /* '<S2>:32:1' seconds==0; */
      if (StopWatch2016_DW->seconds == 0) {
        /* Transition: '<S2>:32' */
        /* '<S2>:32:1' minutes=mod(minutes+1, 60) */
        tmp = (int32_T)(StopWatch2016_DW->minutes + 1U);
        if ((uint32_T)tmp > 255U) {
          tmp = 255;
        }

        StopWatch2016_DW->minutes = (uint8_T)((uint32_T)(uint8_T)tmp - (uint8_T)
          ((uint8_T)tmp / 60U * 60U));

        /* '<S2>:37:1' sf_internal_predicateOutput = ... */
        /* '<S2>:37:1' minutes==0; */
        if (StopWatch2016_DW->minutes == 0) {
          /* Transition: '<S2>:37' */
          /* '<S2>:37:1' hours=mod(hours+1,24) */
          tmp = (int32_T)(StopWatch2016_DW->hours + 1U);
          if ((uint32_T)tmp > 255U) {
            tmp = 255;
          }

          StopWatch2016_DW->hours = (uint8_T)((uint32_T)(uint8_T)tmp - (uint8_T)
            ((uint8_T)tmp / 24U * 24U));

          /* Transition: '<S2>:38' */
        } else {
          /* Transition: '<S2>:33' */
          /* Transition: '<S2>:35' */
        }
      } else {
        /* Transition: '<S2>:30' */
        /* Transition: '<S2>:35' */
      }
    } else {
      /* Transition: '<S2>:22' */
      /* Transition: '<S2>:35' */
    }
  }

  /* During 'AlarmMng': '<S2>:15' */
  if (StopWatch2016_DW->is_AlarmMng == StopWatch2016_IN_ringing) {
    /* During 'ringing': '<S2>:118' */
    /* '<S2>:125:1' sf_internal_predicateOutput = ... */
    /* '<S2>:125:1' Ahours~=hours || Aminutes~=minutes || ringing==false; */
    if ((StopWatch2016_DW->Ahours != StopWatch2016_DW->hours) ||
        (StopWatch2016_DW->Aminutes != StopWatch2016_DW->minutes) ||
        (!*StopWatch2016_Y_ringing)) {
      /* Transition: '<S2>:125' */
      /* Exit 'ringing': '<S2>:118' */
      /* '<S2>:118:1' ringing=false; */
      *StopWatch2016_Y_ringing = false;
      StopWatch2016_DW->is_AlarmMng = StopWatch2016_IN_silent;
    }
  } else {
    /* During 'silent': '<S2>:116' */
    /* '<S2>:124:1' sf_internal_predicateOutput = ... */
    /* '<S2>:124:1' alarmOn==true && hours==Ahours && minutes==Aminutes; */
    if ((*StopWatch2016_Y_alarmOn) && (StopWatch2016_DW->hours ==
         StopWatch2016_DW->Ahours) && (StopWatch2016_DW->minutes ==
         StopWatch2016_DW->Aminutes)) {
      /* Transition: '<S2>:124' */
      StopWatch2016_DW->is_AlarmMng = StopWatch2016_IN_ringing;

      /* Entry 'ringing': '<S2>:118' */
      /* '<S2>:118:1' ringing=true; */
      *StopWatch2016_Y_ringing = true;
    }
  }
}

/* Model step function */
void StopWatch2016_step(RT_MODEL_StopWatch2016_T *const StopWatch2016_M,
  boolean_T StopWatch2016_U_tick, boolean_T StopWatch2016_U_plusbutton,
  boolean_T StopWatch2016_U_minusbutton, boolean_T StopWatch2016_U_timemode,
  boolean_T StopWatch2016_U_timesetmode, boolean_T StopWatch2016_U_alarmmode,
  boolean_T StopWatch2016_U_swatchmode, boolean_T StopWatch2016_U_alarmonoff,
  uint8_T *StopWatch2016_Y_hours, uint8_T *StopWatch2016_Y_minutes, uint8_T
  *StopWatch2016_Y_seconds, uint8_T *StopWatch2016_Y_tenths, uint8_T
  *StopWatch2016_Y_mode, boolean_T *StopWatch2016_Y_hblink, boolean_T
  *StopWatch2016_Y_mblink, boolean_T *StopWatch2016_Y_alarmOn, boolean_T
  *StopWatch2016_Y_ringing)
{
  DW_StopWatch2016_T *StopWatch2016_DW = ((DW_StopWatch2016_T *)
    StopWatch2016_M->dwork);
  PrevZCX_StopWatch2016_T *StopWatch2016_PrevZCX = ((PrevZCX_StopWatch2016_T *)
    StopWatch2016_M->prevZCSigState);
  boolean_T zcEvent[8];
  boolean_T tmp;
  int32_T i;

  /* Chart: '<S1>/SWatch' incorporates:
   *  TriggerPort: '<S2>/input events'
   */
  /* Inport: '<Root>/tick' */
  zcEvent[0] = (((StopWatch2016_PrevZCX->SWatch_Trig_ZCE[0] == POS_ZCSIG) !=
                 (int32_T)StopWatch2016_U_tick) &&
                (StopWatch2016_PrevZCX->SWatch_Trig_ZCE[0] !=
                 UNINITIALIZED_ZCSIG));

  /* Inport: '<Root>/plusbutton' */
  zcEvent[1] = (((StopWatch2016_PrevZCX->SWatch_Trig_ZCE[1] == POS_ZCSIG) !=
                 (int32_T)StopWatch2016_U_plusbutton) &&
                (StopWatch2016_PrevZCX->SWatch_Trig_ZCE[1] !=
                 UNINITIALIZED_ZCSIG));

  /* Inport: '<Root>/minusbutton' */
  zcEvent[2] = (((StopWatch2016_PrevZCX->SWatch_Trig_ZCE[2] == POS_ZCSIG) !=
                 (int32_T)StopWatch2016_U_minusbutton) &&
                (StopWatch2016_PrevZCX->SWatch_Trig_ZCE[2] !=
                 UNINITIALIZED_ZCSIG));

  /* Inport: '<Root>/timemode' */
  zcEvent[3] = (((StopWatch2016_PrevZCX->SWatch_Trig_ZCE[3] == POS_ZCSIG) !=
                 (int32_T)StopWatch2016_U_timemode) &&
                (StopWatch2016_PrevZCX->SWatch_Trig_ZCE[3] !=
                 UNINITIALIZED_ZCSIG));

  /* Inport: '<Root>/timesetmode' */
  zcEvent[4] = (((StopWatch2016_PrevZCX->SWatch_Trig_ZCE[4] == POS_ZCSIG) !=
                 (int32_T)StopWatch2016_U_timesetmode) &&
                (StopWatch2016_PrevZCX->SWatch_Trig_ZCE[4] !=
                 UNINITIALIZED_ZCSIG));

  /* Inport: '<Root>/alarmmode' */
  zcEvent[5] = (((StopWatch2016_PrevZCX->SWatch_Trig_ZCE[5] == POS_ZCSIG) !=
                 (int32_T)StopWatch2016_U_alarmmode) &&
                (StopWatch2016_PrevZCX->SWatch_Trig_ZCE[5] !=
                 UNINITIALIZED_ZCSIG));

  /* Inport: '<Root>/swatchmode' */
  zcEvent[6] = (((StopWatch2016_PrevZCX->SWatch_Trig_ZCE[6] == POS_ZCSIG) !=
                 (int32_T)StopWatch2016_U_swatchmode) &&
                (StopWatch2016_PrevZCX->SWatch_Trig_ZCE[6] !=
                 UNINITIALIZED_ZCSIG));

  /* Inport: '<Root>/alarmonoff' */
  zcEvent[7] = (((StopWatch2016_PrevZCX->SWatch_Trig_ZCE[7] == POS_ZCSIG) !=
                 (int32_T)StopWatch2016_U_alarmonoff) &&
                (StopWatch2016_PrevZCX->SWatch_Trig_ZCE[7] !=
                 UNINITIALIZED_ZCSIG));
  tmp = false;
  for (i = 0; i < 8; i++) {
    tmp = (tmp || zcEvent[i]);
  }

  if (tmp) {
    /* Inport: '<Root>/tick' */
    /* Gateway: StopWatch2016/SWatch */
    if ((int8_T)(zcEvent[0] ? StopWatch2016_U_tick ? RISING_ZCEVENT :
                 FALLING_ZCEVENT : NO_ZCEVENT) != 0) {
      /* Event: '<S2>:1' */
      StopWatch2016_DW->sfEvent = StopWatch2016_event_ttick;
      Stop_chartstep_c3_StopWatch2016(StopWatch2016_Y_hours,
        StopWatch2016_Y_minutes, StopWatch2016_Y_seconds, StopWatch2016_Y_tenths,
        StopWatch2016_Y_mode, StopWatch2016_Y_hblink, StopWatch2016_Y_mblink,
        StopWatch2016_Y_alarmOn, StopWatch2016_Y_ringing, StopWatch2016_DW);
    }

    /* Inport: '<Root>/plusbutton' */
    if ((int8_T)(zcEvent[1] ? StopWatch2016_U_plusbutton ? RISING_ZCEVENT :
                 FALLING_ZCEVENT : NO_ZCEVENT) == 1) {
      /* Event: '<S2>:6' */
      StopWatch2016_DW->sfEvent = StopWatch2016_event_Bplus;
      Stop_chartstep_c3_StopWatch2016(StopWatch2016_Y_hours,
        StopWatch2016_Y_minutes, StopWatch2016_Y_seconds, StopWatch2016_Y_tenths,
        StopWatch2016_Y_mode, StopWatch2016_Y_hblink, StopWatch2016_Y_mblink,
        StopWatch2016_Y_alarmOn, StopWatch2016_Y_ringing, StopWatch2016_DW);
    }

    /* Inport: '<Root>/minusbutton' */
    if ((int8_T)(zcEvent[2] ? StopWatch2016_U_minusbutton ? RISING_ZCEVENT :
                 FALLING_ZCEVENT : NO_ZCEVENT) == 1) {
      /* Event: '<S2>:7' */
      StopWatch2016_DW->sfEvent = StopWatch2016_event_Bminus;
      Stop_chartstep_c3_StopWatch2016(StopWatch2016_Y_hours,
        StopWatch2016_Y_minutes, StopWatch2016_Y_seconds, StopWatch2016_Y_tenths,
        StopWatch2016_Y_mode, StopWatch2016_Y_hblink, StopWatch2016_Y_mblink,
        StopWatch2016_Y_alarmOn, StopWatch2016_Y_ringing, StopWatch2016_DW);
    }

    /* Inport: '<Root>/timemode' */
    if ((int8_T)(zcEvent[3] ? StopWatch2016_U_timemode ? RISING_ZCEVENT :
                 FALLING_ZCEVENT : NO_ZCEVENT) == 1) {
      /* Event: '<S2>:2' */
      StopWatch2016_DW->sfEvent = StopWatch2016_event_Btime;
      Stop_chartstep_c3_StopWatch2016(StopWatch2016_Y_hours,
        StopWatch2016_Y_minutes, StopWatch2016_Y_seconds, StopWatch2016_Y_tenths,
        StopWatch2016_Y_mode, StopWatch2016_Y_hblink, StopWatch2016_Y_mblink,
        StopWatch2016_Y_alarmOn, StopWatch2016_Y_ringing, StopWatch2016_DW);
    }

    /* Inport: '<Root>/timesetmode' */
    if ((int8_T)(zcEvent[4] ? StopWatch2016_U_timesetmode ? RISING_ZCEVENT :
                 FALLING_ZCEVENT : NO_ZCEVENT) == 1) {
      /* Event: '<S2>:3' */
      StopWatch2016_DW->sfEvent = StopWatch2016_event_Btimeset;
      Stop_chartstep_c3_StopWatch2016(StopWatch2016_Y_hours,
        StopWatch2016_Y_minutes, StopWatch2016_Y_seconds, StopWatch2016_Y_tenths,
        StopWatch2016_Y_mode, StopWatch2016_Y_hblink, StopWatch2016_Y_mblink,
        StopWatch2016_Y_alarmOn, StopWatch2016_Y_ringing, StopWatch2016_DW);
    }

    /* Inport: '<Root>/alarmmode' */
    if ((int8_T)(zcEvent[5] ? StopWatch2016_U_alarmmode ? RISING_ZCEVENT :
                 FALLING_ZCEVENT : NO_ZCEVENT) == 1) {
      /* Event: '<S2>:4' */
      StopWatch2016_DW->sfEvent = StopWatch2016_event_Balarm;
      Stop_chartstep_c3_StopWatch2016(StopWatch2016_Y_hours,
        StopWatch2016_Y_minutes, StopWatch2016_Y_seconds, StopWatch2016_Y_tenths,
        StopWatch2016_Y_mode, StopWatch2016_Y_hblink, StopWatch2016_Y_mblink,
        StopWatch2016_Y_alarmOn, StopWatch2016_Y_ringing, StopWatch2016_DW);
    }

    /* Inport: '<Root>/swatchmode' */
    if ((int8_T)(zcEvent[6] ? StopWatch2016_U_swatchmode ? RISING_ZCEVENT :
                 FALLING_ZCEVENT : NO_ZCEVENT) == 1) {
      /* Event: '<S2>:5' */
      StopWatch2016_DW->sfEvent = StopWatch2016_event_Bstop;
      Stop_chartstep_c3_StopWatch2016(StopWatch2016_Y_hours,
        StopWatch2016_Y_minutes, StopWatch2016_Y_seconds, StopWatch2016_Y_tenths,
        StopWatch2016_Y_mode, StopWatch2016_Y_hblink, StopWatch2016_Y_mblink,
        StopWatch2016_Y_alarmOn, StopWatch2016_Y_ringing, StopWatch2016_DW);
    }

    /* Inport: '<Root>/alarmonoff' */
    if ((int8_T)(zcEvent[7] ? StopWatch2016_U_alarmonoff ? RISING_ZCEVENT :
                 FALLING_ZCEVENT : NO_ZCEVENT) == 1) {
      /* Event: '<S2>:155' */
      StopWatch2016_DW->sfEvent = StopWatch2016_event_BalarmOnOff;
      Stop_chartstep_c3_StopWatch2016(StopWatch2016_Y_hours,
        StopWatch2016_Y_minutes, StopWatch2016_Y_seconds, StopWatch2016_Y_tenths,
        StopWatch2016_Y_mode, StopWatch2016_Y_hblink, StopWatch2016_Y_mblink,
        StopWatch2016_Y_alarmOn, StopWatch2016_Y_ringing, StopWatch2016_DW);
    }
  }

  /* Inport: '<Root>/tick' */
  StopWatch2016_PrevZCX->SWatch_Trig_ZCE[0] = StopWatch2016_U_tick;

  /* Inport: '<Root>/plusbutton' */
  StopWatch2016_PrevZCX->SWatch_Trig_ZCE[1] = StopWatch2016_U_plusbutton;

  /* Inport: '<Root>/minusbutton' */
  StopWatch2016_PrevZCX->SWatch_Trig_ZCE[2] = StopWatch2016_U_minusbutton;

  /* Inport: '<Root>/timemode' */
  StopWatch2016_PrevZCX->SWatch_Trig_ZCE[3] = StopWatch2016_U_timemode;

  /* Inport: '<Root>/timesetmode' */
  StopWatch2016_PrevZCX->SWatch_Trig_ZCE[4] = StopWatch2016_U_timesetmode;

  /* Inport: '<Root>/alarmmode' */
  StopWatch2016_PrevZCX->SWatch_Trig_ZCE[5] = StopWatch2016_U_alarmmode;

  /* Inport: '<Root>/swatchmode' */
  StopWatch2016_PrevZCX->SWatch_Trig_ZCE[6] = StopWatch2016_U_swatchmode;

  /* Inport: '<Root>/alarmonoff' */
  StopWatch2016_PrevZCX->SWatch_Trig_ZCE[7] = StopWatch2016_U_alarmonoff;
}

/* Model initialize function */
void StopWatch2016_initialize(RT_MODEL_StopWatch2016_T *const StopWatch2016_M,
  boolean_T *StopWatch2016_U_tick, boolean_T *StopWatch2016_U_plusbutton,
  boolean_T *StopWatch2016_U_minusbutton, boolean_T *StopWatch2016_U_timemode,
  boolean_T *StopWatch2016_U_timesetmode, boolean_T *StopWatch2016_U_alarmmode,
  boolean_T *StopWatch2016_U_swatchmode, boolean_T *StopWatch2016_U_alarmonoff,
  uint8_T *StopWatch2016_Y_hours, uint8_T *StopWatch2016_Y_minutes, uint8_T
  *StopWatch2016_Y_seconds, uint8_T *StopWatch2016_Y_tenths, uint8_T
  *StopWatch2016_Y_mode, boolean_T *StopWatch2016_Y_hblink, boolean_T
  *StopWatch2016_Y_mblink, boolean_T *StopWatch2016_Y_alarmOn, boolean_T
  *StopWatch2016_Y_ringing)
{
  DW_StopWatch2016_T *StopWatch2016_DW = ((DW_StopWatch2016_T *)
    StopWatch2016_M->dwork);
  PrevZCX_StopWatch2016_T *StopWatch2016_PrevZCX = ((PrevZCX_StopWatch2016_T *)
    StopWatch2016_M->prevZCSigState);

  /* Registration code */

  /* states (dwork) */
  (void) memset((void *)StopWatch2016_DW, 0,
                sizeof(DW_StopWatch2016_T));

  /* external inputs */
  *StopWatch2016_U_tick = false;
  *StopWatch2016_U_plusbutton = false;
  *StopWatch2016_U_minusbutton = false;
  *StopWatch2016_U_timemode = false;
  *StopWatch2016_U_timesetmode = false;
  *StopWatch2016_U_alarmmode = false;
  *StopWatch2016_U_swatchmode = false;
  *StopWatch2016_U_alarmonoff = false;

  /* external outputs */
  (*StopWatch2016_Y_hours) = 0U;
  (*StopWatch2016_Y_minutes) = 0U;
  (*StopWatch2016_Y_seconds) = 0U;
  (*StopWatch2016_Y_tenths) = 0U;
  (*StopWatch2016_Y_mode) = 0U;
  (*StopWatch2016_Y_hblink) = false;
  (*StopWatch2016_Y_mblink) = false;
  (*StopWatch2016_Y_alarmOn) = false;
  (*StopWatch2016_Y_ringing) = false;

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      StopWatch2016_PrevZCX->SWatch_Trig_ZCE[i] = UNINITIALIZED_ZCSIG;
    }

    /* SystemInitialize for Chart: '<S1>/SWatch' */
    StopWatch2016_DW->is_alarmmode = StopWatch201_IN_NO_ACTIVE_CHILD;
    StopWatch2016_DW->is_swatchmode = StopWatch201_IN_NO_ACTIVE_CHILD;
    StopWatch2016_DW->is_timesetmode = StopWatch201_IN_NO_ACTIVE_CHILD;

    /* SystemInitialize for Outport: '<Root>/hblink' incorporates:
     *  SystemInitialize for Chart: '<S1>/SWatch'
     */
    /* Entry: StopWatch2016/SWatch */
    /* Entry Internal: StopWatch2016/SWatch */
    /* Entry Internal 'Control': '<S2>:13' */
    /* Transition: '<S2>:25' */
    /* '<S2>:25:1' hblink=false, */
    *StopWatch2016_Y_hblink = false;

    /* SystemInitialize for Outport: '<Root>/mblink' incorporates:
     *  SystemInitialize for Chart: '<S1>/SWatch'
     */
    /* '<S2>:25:1' mblink= false */
    *StopWatch2016_Y_mblink = false;

    /* SystemInitialize for Chart: '<S1>/SWatch' */
    StopWatch2016_DW->is_Control = StopWatch2016_IN_timemode;

    /* SystemInitialize for Outport: '<Root>/mode' incorporates:
     *  SystemInitialize for Chart: '<S1>/SWatch'
     */
    /* Entry 'timemode': '<S2>:23' */
    /* '<S2>:23:1' mode=uint8(0) */
    *StopWatch2016_Y_mode = 0U;

    /* SystemInitialize for Chart: '<S1>/SWatch' */
    /* Entry Internal 'TimeCount': '<S2>:14' */
    /* Transition: '<S2>:18' */
    /* '<S2>:18:1' hours=uint8(0); */
    StopWatch2016_DW->hours = 0U;

    /* '<S2>:18:1' minutes=uint8(0); */
    StopWatch2016_DW->minutes = 0U;

    /* '<S2>:18:1' seconds=uint8(0); */
    StopWatch2016_DW->seconds = 0U;

    /* '<S2>:18:2' tenths=uint8(0) */
    StopWatch2016_DW->tenths = 0U;

    /* SystemInitialize for Outport: '<Root>/alarmOn' incorporates:
     *  SystemInitialize for Chart: '<S1>/SWatch'
     */
    /* Entry 'AlarmMng': '<S2>:15' */
    /* '<S2>:15:1' alarmOn=false; */
    *StopWatch2016_Y_alarmOn = false;

    /* SystemInitialize for Outport: '<Root>/ringing' incorporates:
     *  SystemInitialize for Chart: '<S1>/SWatch'
     */
    /* '<S2>:15:1' ringing=false; */
    *StopWatch2016_Y_ringing = false;

    /* SystemInitialize for Chart: '<S1>/SWatch' */
    /* Entry Internal 'AlarmMng': '<S2>:15' */
    /* Transition: '<S2>:117' */
    /* '<S2>:117:1' Ahours= uint8(0); */
    StopWatch2016_DW->Ahours = 0U;

    /* '<S2>:117:1' Aminutes= uint8(0); */
    StopWatch2016_DW->Aminutes = 0U;
    StopWatch2016_DW->is_AlarmMng = StopWatch2016_IN_silent;
  }
}

/* Model terminate function */
void StopWatch2016_terminate(RT_MODEL_StopWatch2016_T *const StopWatch2016_M)
{
  /* (no terminate code required) */
  UNUSED_PARAMETER(StopWatch2016_M);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
