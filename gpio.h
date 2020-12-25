/*
*Name:gpio.h
*Purpose: 
*Author: ThangLMb
*Date: 06/08/2019
*Purpose: Control Gpio qcs
*/

#ifndef GPIO_H__
#define GPIO_H__
#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <linux/spi/spidev.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "LC898201Typedef.h"
#define GPIO_IN  0
#define GPIO_OUT 1

#define GPIO_LOW  0
#define GPIO_HIGH 1

#define BUFFER_MAX 5
#define DIRECTION_MAX 35
#define VALUE_MAX 30

int GPIOExport(INT pin);
INT GPIOUnexport(INT pin);
INT  GPIODirection(INT pin, INT dir);
INT GPIOWrite(INT pin, INT value);
#endif 