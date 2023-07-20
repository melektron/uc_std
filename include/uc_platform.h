/*
ELEKTRON © 2023
Written by melektron
www.elektron.work
20.07.23, 15:04

detection of microcontroller platform depending on some defines
*/

#ifndef __UC_PLATFORM
#define __UC_PLATFORM




// check for STM32s
#if defined(STM32F4)
#define UC_PLATFORM_STM32F4

#elif defined(SOMETHINGELSE)
#define UC_PLATFORM_SOMETHINGELSE

#endif



#endif // __UC_PLATFORM