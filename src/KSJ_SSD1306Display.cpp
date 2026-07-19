#include "KSJ_SSD1306Display.h"

namespace KSJ
{

SSD1306Display::SSD1306Display(
    uint8_t width,
    uint8_t height,
    uint8_t address,
    int8_t resetPin,
    TwoWire& wire
)
    : _address(address),
      _display(width, height, &wire, resetPin)
{
}

bool SSD1306Display::begin()
{
    const bool started = _display.begin(
        SSD1306_SWITCHCAPVCC,
        _address
    );

    if (!started)
    {
        return false;
    }

    _display.clearDisplay();
    _display.setTextColor(SSD1306_WHITE);
    _display.setTextWrap(false);
    _display.display();

    return true;
}

void SSD1306Display::clear()
{
    _display.clearDisplay();
}

void SSD1306Display::update()
{
    _display.display();
}

void SSD1306Display::setTextSize(uint8_t size)
{
    _display.setTextSize(size);
}

void SSD1306Display::print(
    int16_t x,
    int16_t y,
    const String& text
)
{
    _display.setCursor(x, y);
    _display.print(text);
}

void SSD1306Display::drawLine(
    int16_t x0,
    int16_t y0,
    int16_t x1,
    int16_t y1
)
{
    _display.drawLine(
        x0,
        y0,
        x1,
        y1,
        SSD1306_WHITE
    );
}

void SSD1306Display::drawRect(
    int16_t x,
    int16_t y,
    int16_t width,
    int16_t height
)
{
    _display.drawRect(
        x,
        y,
        width,
        height,
        SSD1306_WHITE
    );
}

void SSD1306Display::fillRect(
    int16_t x,
    int16_t y,
    int16_t width,
    int16_t height
)
{
    _display.fillRect(
        x,
        y,
        width,
        height,
        SSD1306_WHITE
    );
}

Adafruit_SSD1306& SSD1306Display::native()
{
    return _display;
}

const Adafruit_SSD1306& SSD1306Display::native() const
{
    return _display;
}

}