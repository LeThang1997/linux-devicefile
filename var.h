#ifndef VAR_H_
#define VAR_H_

#define	   DEBUG		0
#define    FOCUSTRUE    1
#define    FOCUSFALSE   0
#define    ZOOMTRUE     1
#define    ZOOMFALSE    0
#define    IRISDIR      0

#define SPEED_MAX    100
#define SPEED_MIN    1
#define SPEED_DEFAULT 25

// Dung de cau hinh doc Pi sensor. Khi nao co IC logic PI_SENSOR_HIGH 0x00, Khi khong co IC logic PI_SENSOR_HIGH 0x10
#define     PI_SENSOR_HIGH 0x00
#define     PI_SENSOR_LOW  0x10

//#define    LENS_S213   0
/*
    - Zoom Parameter : 
                - Step angle: 9 degree ( 1-2 phase excitation)
                - Feed screww: 0.01mm/STEP at 1-2 phase excitation mode
                - Pi sensor: Zoom High => WIDE => Pi sensor status = 0x00
                             Zoom Low => TELE => Pi sensor status = 0x10
                - Mechanical: Zoom Tele: 2.81 mm = 281 step 
                              Zoom Wide: 3.02 mm = 301 step
                - Max speed: 1600pps 1-2 phase

    - Focus Parameter : 
                - Step angle: 9 degree ( 1-2 phase)
                - Feed screww: 0.01mm/STEP at 1-2 phase excitation mode
                - Pi sensor: Focus High => FAR => Pi sensor status = 0x00
                             Focus Low => NEAR => Pi sensor status = 0x10
                - Mechanical: : Focus Far: 4.81 mm  = 481 step
                                Focus Near: 4.31 mm = 431 step
                - Max speed: 1600pps 1-2 phase
*/
//#define    LENS_S212   0
/*
    - Zoom Parameter : 
                - Step angle: 18 degree ( 2-2 phase excitation)
                - Feed screww: 0.02mm/STEP at 2-2 phase excitation mode
                - Pi sensor: Zoom High => TELE
                             Zoom Low => WIDE
                - Mechanical: Zoom Tele: 3.52 mm = 176 step 
                              Zoom Wide: 9.08 mm = 454 step
                - Max speed: 800pps 2-2 phase
    - Focus Parameter : 
                - Step angle: 9 degree ( 1-2 phase excitation)
                - Feed screww: 0.01mm/STEP at 1-2 phase excitation mode
                - Pi sensor: Focus High => FAR
                             Focus Low => NEAR
                - Mechanical: : Focus Far: 481 mm  = 481 step
                                Focus Near: 431 mm = 431 step
                - Max speed: 1600pps 1-2 phase

*/
//#define    LENS_S211   1
/*
    - Zoom Parameter : 
                - Step angle: 9 degree ( 1-2 phase excitation)
                              18 degree ( 2-2 phase excitation)
                - Feed screww: 0.01mm/STEP at 1-2 phase excitation mode
                - Pi sensor: Zoom High => TELE : Pi sensor status = 0x00
                             Zoom Low => WIDE  : Pi sensor status = 0x10
                - Mechanical: Zoom Tele: 3.52 mm = 176 step 
                              Zoom Wide: 9.08 mm = 454 step
                - Max speed: 800pps 2-2 phase
    - Focus Parameter : 
                - Step angle: 4.5 degree ( 1-2 phase excitation)
                - Feed screww: 0.005mm/STEP at 1-2 phase excitation mode
                - Pi sensor: Focus High => FAR : Pi sensor status = 0x00
                             Focus Low => NEAR  : Pi sensor status = 0x10
                - Mechanical: : Focus Far: 481 mm  = 481 step
                                Focus Near: 431 mm = 431 step
                - Max speed: 800pps 1-2 phase
*/

/*-----------------------------------------------------------------------------*/
/* Global variables																
/*-----------------------------------------------------------------------------*/
static unsigned char   g_iSelectLens;
static unsigned char   g_bDirFocusNear ; 
static unsigned char   g_bDirFocusFar ;  
static unsigned char   g_bDirZoomWide ;
static unsigned char   g_bDirZoomTele ; 
static int g_iThresholdFocusNear;
static int g_iThresholdFocusFar;
static int g_iThresholdZoomWide;
static int g_iThresholdZoomTele;
static unsigned int g_iZoomSpeedMax, g_iFocusSpeedMax;

#endif