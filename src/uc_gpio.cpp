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
        GPIO_TypeDef *_port,
        uint16_t _pin,
        IRQn_Type _it_channel
    )
        : port(_port),
        pin(_pin),
        it_channel(_it_channel)
    {
    }

    void Pin::write(bool _state)
    {
        HAL_GPIO_WritePin(port, pin, (GPIO_PinState)_state);
    }

    bool Pin::read()
    {
        return (bool)HAL_GPIO_ReadPin(port, pin);
    }

    void Pin::disableInterrupt()
    {
        if (it_channel == UC_GPIO_NO_INTERRUPT)
            return;

        HAL_NVIC_DisableIRQ(it_channel);
    }

    void Pin::enableInterrupt()
    {
        if (it_channel == UC_GPIO_NO_INTERRUPT)
            return;

        HAL_NVIC_EnableIRQ(it_channel);
    }

    void Pin::clearPendingInterrupt()
    {
        if (it_channel == UC_GPIO_NO_INTERRUPT)
            return;

        // Implemented according to:
        // https://community.st.com/t5/stm32-mcu-products/exti-pending-interrupt-exti-pr1-still-getting-serviced-even-when/td-p/322146

        // This loop only runs once usually
        while (HAL_NVIC_GetPendingIRQ(it_channel))
        {
            // the important part here is this macro which is needed
            // because just clearing the pending bit with the function below would cause it to
            // immediately be set again by hardware
            __HAL_GPIO_EXTI_CLEAR_IT(pin);
            // this call is also needed
            HAL_NVIC_ClearPendingIRQ(it_channel);
        }
    }

#elif defined(UC_PLATFORM_STM32F4)    // maybe?
// to be done
#endif

};