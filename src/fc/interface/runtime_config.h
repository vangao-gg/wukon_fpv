#ifndef __RUNTIME_CONFIG_H
#define __RUNTIME_CONFIG_H
#include "sys.h"

/********************************************************************************	 
 * 本程序只供学习使用，未经作者许可，不得用于其它任何用途
 * ATKflight飞控固件
 * 运行监测代码	
 * 正点原子@ALIENTEK
 * 技术论坛:www.openedv.com
 * 创建日期:2018/5/2
 * 版本：V1.0
 * 版权所有，盗版必究。
 * Copyright(C) 广州市星翼电子科技有限公司 2014-2024
 * All rights reserved
********************************************************************************/


//解锁标志位
typedef enum 
{
    ARMED                                           = (1 << 1), // 如果是1 就是解锁了
    WAS_EVER_ARMED                                  = (1 << 2), 
    ARMING_DISABLED_NOT_LEVEL                       = (1 << 3), // 如果是1 就是不能解锁  原因是不水平
    ARMING_DISABLED_SENSORS_CALIBRATING             = (1 << 4), // 如果是1 就是不能解锁  原因是传感器没有校准
    ARMING_DISABLED_COMPASS_NOT_CALIBRATED          = (1 << 5), // 如果是1 就是不能解锁  原因是罗盘没有校准 
    ARMING_DISABLED_ACCELEROMETER_NOT_CALIBRATED    = (1 << 6), // 如果是1 就是不能解锁  原因是加速度计没有校准
    ARMING_DISABLED_HARDWARE_FAILURE                = (1 << 7), // 如果是1 就是不能解锁  原因是硬件失败
	ARMING_DISABLED_FLASH_WRITING                   = (1 << 8), // 如果是1 就是不能解锁  原因是flash还在写
	ARMING_DISABLED_PID_BYPASS			            = (1 << 9), // 如果是1 就是不能解锁  原始是pid被取消了
	
    ARMING_DISABLED_ALL_FLAGS                       = (ARMING_DISABLED_NOT_LEVEL | ARMING_DISABLED_SENSORS_CALIBRATING | ARMING_DISABLED_COMPASS_NOT_CALIBRATED | 
                                                       ARMING_DISABLED_ACCELEROMETER_NOT_CALIBRATED | ARMING_DISABLED_HARDWARE_FAILURE | ARMING_DISABLED_FLASH_WRITING |
													   ARMING_DISABLED_PID_BYPASS
													   )
} armingFlag_e;
extern uint32_t armingFlags;

#define isArmingDisabled()          (armingFlags & (ARMING_DISABLED_ALL_FLAGS))
#define DISABLE_ARMING_FLAG(mask)   (armingFlags &= ~(mask))
#define ENABLE_ARMING_FLAG(mask)    (armingFlags |= (mask))
#define ARMING_FLAG(mask)           (armingFlags & (mask))


//飞行模式标志位
typedef enum 
{
	ANGLE_MODE        = (1 << 0), //自稳模式
	ACRO_MODE         = (1 << 1), //手动模式
	HEADFREE_MODE     = (1 << 2), //无头模式
	NAV_ALTHOLD_MODE  = (1 << 3), //定高模式                 
	NAV_RTH_MODE      = (1 << 4),
	NAV_POSHOLD_MODE  = (1 << 5),
	NAV_LAUNCH_MODE   = (1 << 7),  
	FAILSAFE_MODE     = (1 << 8),  //失控保护模式
	BEEPER_ON_MODE    = (1 << 9),//蜂鸣器常开，寻机模式。
} flightModeFlags_e;
extern uint32_t flightModeFlags;

#define DISABLE_FLIGHT_MODE(mask) disableFlightMode(mask)
#define ENABLE_FLIGHT_MODE(mask) enableFlightMode(mask)
#define FLIGHT_MODE(mask) (flightModeFlags & (mask))


//运行状态标志位
typedef enum 
{
	ACCELEROMETER_CALIBRATED  = (1 << 1),
	COMPASS_CALIBRATED        = (1 << 2),
	CALIBRATE_MAG             = (1 << 3),
	SMALL_ANGLE               = (1 << 4),
	FLASH_WRITING             = (1 << 5),
} stateFlags_t;
extern uint32_t stateFlags;

#define DISABLE_STATE(mask) (stateFlags &= ~(mask))
#define ENABLE_STATE(mask) (stateFlags |= (mask))
#define STATE(mask) (stateFlags & (mask))


uint32_t enableFlightMode(flightModeFlags_e mask);
uint32_t disableFlightMode(flightModeFlags_e mask);

void mwDisarm(void);
void mwArm(void);
void updateArmingStatus(void);

#endif

