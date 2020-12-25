
/*
*Name:gpio.c
*Purpose: 
*Author: ThangLMb
*Date: 06/08/2019
*Purpose: Control Gpio qcs
*/
#include"gpio.h"
/*-------------------------------------------------------------------------
* Function:  INT GPIOExport(INT pin)
* Purpose: SEt up gpio for export
* Parameter: None	 
* Return: None
* Comment: 
---------------------------------------------------------------------------*/
 INT GPIOExport(INT pin)
{
        char buffer[BUFFER_MAX];
        ssize_t bytes_written;
        INT fd;

        fd = open("/sys/class/gpio/export", O_WRONLY);    
        if (-1 == fd) 
        {
                fprintf(stderr, "Failed to open export for writing!\n");
                return(-1);
        }

       // bytes_written = snprintf(buffer, BUFFER_MAX, "%d", pin);
       // write(fd, buffer, bytes_written);
       
        bytes_written = sprintf(buffer, "%d", pin);
        write(fd, buffer, strlen(buffer));
        close(fd);
        return(0);
}
/*-------------------------------------------------------------------------
* Function:  int GPIOUnexport(int pin)
* Purpose: SEt up gpio for export
* Parameter: None	 
* Return: None
* Comment: 
---------------------------------------------------------------------------*/
INT GPIOUnexport(INT pin)
{
        char buffer[BUFFER_MAX];
        ssize_t bytes_written;
        INT fd;

        fd = open("/sys/class/gpio/unexport", O_WRONLY);
        if (-1 == fd) {
                fprintf(stderr, "Failed to open unexport for writing!\n");
                return(-1);
        }

        bytes_written = snprintf(buffer, BUFFER_MAX, "%d", pin);
        write(fd, buffer, bytes_written);
        close(fd);
        return(0);
}
/*-------------------------------------------------------------------------
* Function: INT  GPIODirection(INT pin, INT dir)
* Purpose: Set direction of gpio ( out or in)
* Parameter:INT pin: pin of gpio 	 
* Return: None
* Comment: 
---------------------------------------------------------------------------*/
 INT  GPIODirection(INT pin, INT dir)
{
        const char s_directions_str[]  = "in\0out";
        char path[DIRECTION_MAX];
        INT fd;

        snprintf(path, DIRECTION_MAX, "/sys/class/gpio/gpio%d/direction", pin);
        fd = open(path, O_WRONLY);
        if (-1 == fd) {
                fprintf(stderr, "Failed to open gpio direction for writing!\n");
                return(-1);
        }

        if (-1 == write(fd, &s_directions_str[GPIO_IN == dir ? 0 : 3], GPIO_IN == dir ? 2 : 3)) 
        {
                fprintf(stderr, "Failed to set direction!\n");
                return(-1);
        }
        close(fd);
        return(0);
}
/*-------------------------------------------------------------------------
* Function:  INT GPIOWrite(INT pin, INT value)
* Purpose: set value at gpio 
* Parameter: INT pin: pin of gpio 
                INT value: GPIO_HIGH or GPIO_LOW	 
* Return: None
* Comment: 
---------------------------------------------------------------------------*/
INT GPIOWrite(INT pin, INT value)
{
        const char s_values_str[] = "01";

        char path[VALUE_MAX];
        INT fd;

        snprintf(path, VALUE_MAX, "/sys/class/gpio/gpio%d/value", pin);
        fd = open(path, O_WRONLY);
        if (-1 == fd) {
                fprintf(stderr, "Failed to open gpio value for writing!T\n");
                return(-1);
        }

        if (1 != write(fd, &s_values_str[GPIO_LOW == value ? 0 : 1], 1))
        {
                fprintf(stderr, "Failed to write value!\n");
                return(-1);
        }
        close(fd);
        return(0);
}
