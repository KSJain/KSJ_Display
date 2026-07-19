#pragma once

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "IGraphicsDevice.h"

namespace KSJ
{

class SSD1306Display final : public IGraphicsDevice
{
public:
    SSD1306Display(
        uint8_t width = 128,
        uint8_t height = 64,
        uint8_t address = 0x3C,
        int8_t resetPin = -1,
        TwoWire& wire = Wire
    );

    bool begin() override;

    void clear() override;
    void update() override;

    void setTextSize(uint8_t size) override;

    void print(
        int16_t x,
        int16_t y,
        const String& text
    ) override;

    void drawLine(
        int16_t x0,
        int16_t y0,
        int16_t x1,
        int16_t y1
    ) override;

    void drawRect(
        int16_t x,
        int16_t y,
        int16_t width,
        int16_t height
    ) override;

    void fillRect(
        int16_t x,
        int16_t y,
        int16_t width,
        int16_t height
    ) override;

    Adafruit_SSD1306& native();
    const Adafruit_SSD1306& native() const;

private:
    uint8_t _address;
    Adafruit_SSD1306 _display;
};

}