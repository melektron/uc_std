/*
ELEKTRON © 2023
Written by melektron
www.elektron.work
20.07.23, 14:57

A universal representation of GPIO pins and their functionality
*/

#include "uc_gpio.hpp"


namespace uc
{
    #if defined(UC_PLATFORM_STM32F4)
    Pin::Pin(
        GPIO_TypeDef* _port,
        uint16_t _pin
    )
    {
        port = _port;
        pin = _pin;
    }

    void Pin::write(bool _state)
    {
        HAL_GPIO_WritePin(port, pin, (GPIO_PinState)_state);
    }

    bool Pin::read()
    {
        return (bool)HAL_GPIO_ReadPin(port, pin);
    }

#elif defined(UC_PLATFORM_STM32F4)    // maybe?
// to be done
#endif

};