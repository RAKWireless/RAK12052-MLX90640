| <center><img src="./assets/rakstar.jpg" alt="RAKstar" width=25%></center>  | ![RAKWireless](./assets/RAK-Whirls.png) | [![Build Status](https://github.com/RAKWireless/RAK13005-TLE7259-Library/workflows/RAK%20Library%20Build%20CI/badge.svg)](https://github.com/RAKWireless/RAK13005-TLE7259-Library/actions) |
| -- | -- | -- |

# <RAK12052>

Library for Melexis MLX90640 32x24 IR array. It realizes the configuration and reading of MLX90640. Implement reading, configuration, and display examples to facilitate the realization of your ideas.

[*RAKWireless <RAK#> <function>*](https://store.RAKWireless.com/products/lin-bus-module-rak13005)

# Documentation

* **[Product Repository](https://github.com/RAKWireless/RAK12052-MLX90640)** - Product repository for the RAKWireless RAK12052 32x24 IR module.
* **[Documentation](https://docs.RAKWireless.com/Product-Categories/WisBlock/RAK12052/Overview/)** - Documentation and Quick Start Guide for the RAK12052 32x24 IR module.

# Installation

In Arduino IDE open Sketch->Include Library->Manage Libraries then search for RAK12052.

In PlatformIO open PlatformIO Home, switch to libraries and search for RAK12052 .
Or install the library project dependencies by adding

```log
lib_deps =
  RAKWireless/RAKWireless MLX90640 32x24 IR library
```

into **`platformio.ini`**

For manual installation download the archive, unzip it and place the RAK12052-MLX90640 folder into the library directory.
In Arduino IDE this is usually <arduinosketchfolder>/libraries/
In PlatformIO this is usually <user/.platformio/lib>

# Usage

The library provides RAK_MLX90640 class, which allows communication with MLX90640 via IIC. These examples show how to use RAK12052.

- [RAK12052_32x24_IR_Read_MLX90640](./examples/RAK12052_32x24_IR_Read_MLX90640) Read the temperature array collected by the sensor and output it through the serial port.
- [RAK12052_32x24_IR_Display_MLX90640](./examples/RAK12052_32x24_IR_Display_MLX90640) Serial output temperature array data and display the binarized graphics through RAK1921.

## This class provides the following methods:

**bool begin( TwoWire *wire , uint8_t i2c_addr) **

Initalizes the MLX90640 sensor.

#### Parameters:

| Direction | Name     | Function                                                     |
| --------- | -------- | ------------------------------------------------------------ |
| in        | wire     | IIC interface used.                                          |
| in        | i2c_addr | Device address should be 0x33.                               |
| return    |          | If the device init successful return true else return false. |

**mlx90640_mode_t getMode(void)**

Get the frame-read mode.

#### Parameters:

| Direction | Name | Function                   |
| --------- | ---- | -------------------------- |
| return    |      | Chess or interleaved mode. |

**void setMode(mlx90640_mode_t mode) **

Set the frame-read mode.

#### Parameters:

| Direction | Name | Function                   |
| --------- | ---- | -------------------------- |
| in        | mode | Chess or interleaved mode. |
| return    |      | none                       |

**mlx90640_resolution_t getResolution(void)**

Get resolution for temperature precision.

#### Parameters:

| Direction | Name | Function                       |
| --------- | ---- | ------------------------------ |
| return    |      | The desired resolution (bits). |

**void setResolution(mlx90640_resolution_t res)**

Set resolution for temperature precision.

#### Parameters:

| Direction | Name | Function                       |
| --------- | ---- | ------------------------------ |
| in        | res  | The desired resolution (bits). |
| return    |      | none                           |

**mlx90640_refreshrate_t getRefreshRate(void)**

Get max refresh rate.

#### Parameters:

| Direction | Name | Function                                               |
| --------- | ---- | ------------------------------------------------------ |
| return    |      | How many pages per second to read (2 pages per frame). |

**void setRefreshRate(mlx90640_refreshrate_t res)**

Set max refresh rate - too fast and we can't read the the pages in time, start low and then increment while speeding up I2C!

#### Parameters:

| Direction | Name | Function                                               |
| --------- | ---- | ------------------------------------------------------ |
| in        | res  | How many pages per second to read (2 pages per frame). |
| return    |      | none                                                   |

**int getFrame(float *framebuf); **

Read 2 pages, calculate temperatures and place into framebuf.

#### Parameters:

| Direction | Name     | Function                            |
| --------- | -------- | ----------------------------------- |
| in        | framebuf | 24*32 floating point memory buffer. |
| return    |          | 0 on success.                       |

