#pragma once

#include <Arduino.h>

namespace KSJ
{

class IGraphicsDevice
{
public:
    virtual ~IGraphicsDevice() = default;

    virtual bool begin() = 0;

    virtual void clear() = 0;
    virtual void update() = 0;

    virtual void setTextSize(uint8_t size) = 0;

    virtual void print(
        int16_t x,
        int16_t y,
        const String& text
    ) = 0;

    virtual void drawLine(
        int16_t x0,
        int16_t y0,
        int16_t x1,
        int16_t y1
    ) = 0;

    virtual void drawRect(
        int16_t x,
        int16_t y,
        int16_t width,
        int16_t height
    ) = 0;

    virtual void fillRect(
        int16_t x,
        int16_t y,
        int16_t width,
        int16_t height
    ) = 0;
};

}