/**
   @file RAK12029_LDC1614.h
   @author rakwireless.com
   @brief  This is a library for the inductive sensor
   @version 1.0
   @date 2021-11-17
   @copyright Copyright (c) 2021
**/

#ifndef _RAK12052_MLX90640_H
#define _RAK12052_MLX90640_H

#include "utility/Adafruit_MLX90640.h"

class RAK_MLX90640 : public Adafruit_MLX90640
{
public:
  RAK_MLX90640() : Adafruit_MLX90640(){};
	bool begin(TwoWire *wire = &Wire , uint8_t i2c_addr = MLX90640_I2CADDR_DEFAULT);

	
#ifdef RAK4630
	float *frame;
#else
  float frame[32*24];
#endif

		~RAK_MLX90640();	
};

#endif
