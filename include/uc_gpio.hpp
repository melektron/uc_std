/*
ELEKTRON © 2023
Written by melektron
www.elektron.work
20.07.23, 14:57

A universal representation of GPIO pins and their functionality
*/

#pragma once

#include <stdint.h>
#include <stdbool.h>

#include "uc_platform.h"

#if defined(UC_PLATFORM_STM32F4)
#include <stm32f4xx_hal.h>
#elif defined(UC_PLATFORM_STM32F4)    // maybe?
// to be done
#endif


namespace uc
{
    struct Pin
    {
        // == common API

        /**
         * @brief writes a digital VALUE to the output GPIO pin
         * 
         * @param _state SET (1) or RESET(0)
         */
        void write(bool _state);

        /**
         * @brief returns the current digital value of the GPIO pin
         * 
         * @retval true high/SET/1
         * @retval false low/RESET/0
         */
        bool read();


        // == framework specific API

        #if defined(UC_PLATFORM_STM32F4)
        
        GPIO_TypeDef* port;
        uint16_t pin;

        /**
         * @brief Construct a new STM32 Pin object
         * 
         * @param _port port that the pin is of (e.g. PA6 -> Port A)
         * @param _pin index of the port (PA5 -> Pin 5)
         */
        Pin(
            GPIO_TypeDef* _port,
            uint16_t _pin
        );

        #endif
    };
};