#pragma once

#include <Arduino.h>

namespace PrototypeBox
{

namespace Board
{
    inline constexpr char NAME[] = "Prototype_Box v1";
    inline constexpr char VERSION[] = "1.0.0";
    inline constexpr char MCU[] = "ESP32_DevKit V1";
}

namespace Pins
{
    inline constexpr uint8_t SDA = 21;
    inline constexpr uint8_t SCL = 22;

    inline constexpr uint8_t LED_RED = 14;
    inline constexpr uint8_t LED_GREEN = 26;

    inline constexpr uint8_t LDR = 34;

    inline constexpr uint8_t ROTARY_A = 16;
    inline constexpr uint8_t ROTARY_B = 17;
    inline constexpr uint8_t ROTARY_SW = 33;

    inline constexpr uint8_t SD_CS = 5;
}

namespace Display
{
    inline constexpr uint8_t WIDTH = 128;
    inline constexpr uint8_t HEIGHT = 64;
    inline constexpr uint8_t I2C_ADDRESS = 0x3C;
    inline constexpr int8_t RESET_PIN = -1;
}

namespace Features
{
    inline constexpr bool HAS_DISPLAY = true;
    inline constexpr bool HAS_SD = true;
    inline constexpr bool HAS_BMP280 = true;
    inline constexpr bool HAS_AHT20 = true;
    inline constexpr bool HAS_ROTARY = true;
    inline constexpr bool HAS_LDR = true;
}

}