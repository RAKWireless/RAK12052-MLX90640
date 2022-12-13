/**
   @file RAK12029_LDC1614_Inductive.cpp
   @author rakwireless.com
   @brief  This is a library for the inductive sensor
   @version 1.0
   @date 2021-11-17
   @copyright Copyright (c) 2021
**/

#include "RAK12052-MLX90640.h"

RAK_MLX90640::~RAK_MLX90640()
{
#ifdef MLX90640_DEBUG
	Serial.println("Free up storage space.");
#endif
	
#ifdef RAK4630
  free(frame);
#endif
}

bool RAK_MLX90640::begin( TwoWire *wire , uint8_t i2c_addr) 
{
  i2c_dev = new Adafruit_I2CDevice(i2c_addr, wire);

  if (!i2c_dev->begin()) 
	{
    return false;
  }
  MLX90640_I2CRead(0, MLX90640_DEVICEID1, 3, serialNumber);
	
#ifdef RAK4630
  uint16_t *eeMLX90640;
  eeMLX90640 = (uint16_t *)malloc(832 * sizeof(uint16_t));
  if (eeMLX90640 == NULL)
  {
    return false;
  }
#else
	uint16_t eeMLX90640[832];
#endif
  
  if (MLX90640_DumpEE(0, eeMLX90640) != 0)
  {
#ifdef RAK4630
    free(eeMLX90640);
#endif
    return false;
  }


#ifdef MLX90640_DEBUG

  for (int i = 0; i < 832; i++) 
  {
    Serial.printf("0x%x, ", eeMLX90640[i]);
  }
  Serial.println();
  
#endif

  MLX90640_ExtractParameters(eeMLX90640, &_params);

#ifdef RAK4630
  free(eeMLX90640);
	
  frame = (float *)malloc( 32*24 * sizeof(float));
  if (frame == NULL)
  {
	#ifdef MLX90640_DEBUG
		Serial.println("Insufficient heap space!");
	#endif
		return false;
  }
#endif
	
  return true;
}

