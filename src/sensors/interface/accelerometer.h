#ifndef __ACCELEROMETER_H
#define __ACCELEROMETER_H

#include "sys.h"
#include "stabilizer_types.h"
/********************************************************************************	 
 * 本程序只供学习使用，未经作者许可，不得用于其它任何用途
 * ATKflight飞控固件
 * 加速度计驱动代码	
 * 正点原子@ALIENTEK
 * 技术论坛:www.openedv.com
 * 创建日期:2018/5/2
 * 版本：V1.2
 * 版权所有，盗版必究。
 * Copyright(C) 广州市星翼电子科技有限公司 2014-2024
 * All rights reserved
********************************************************************************/


#define GRAVITY_CMSS    980.665f
#define GRAVITY_MSS     9.80665f

#define CALIBRATING_ACC_CYCLES          400

			
extern Axis3i16 accADC;

bool accIsCalibrationComplete(void);
void accSetCalibrationCycles(uint16_t calibrationCyclesRequired);
bool accInit(float accUpdateRate);
void accUpdate(Axis3f *acc);

#endif

