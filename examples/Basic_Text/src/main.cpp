#include <Arduino.h>
#include <Wire.h>

#include <KSJ_SSD1306Display.h>

namespace Pins
{
    constexpr uint8_t SDA = 21;
    constexpr uint8_t SCL = 22;
}

namespace DisplayConfig
{
    constexpr uint8_t WIDTH = 128;
    constexpr uint8_t HEIGHT = 64;
    constexpr uint8_t ADDRESS = 0x3C;
}

KSJ::SSD1306Display display(
    DisplayConfig::WIDTH,
    DisplayConfig::HEIGHT,
    DisplayConfig::ADDRESS
);

void setup()
{
    Serial.begin(115200);
    delay(200);

    Wire.begin(Pins::SDA, Pins::SCL);

    Serial.println();
    Serial.println("KSJ_Display Basic_Text example");

    if (!display.begin())
    {
        Serial.println("OLED initialization failed.");

        while (true)
        {
            delay(1000);
        }
    }

    display.clear();

    display.setTextSize(2);
    display.print(0, 0, "Hello KSJ");

    display.setTextSize(1);
    display.print(0, 24, "KSJ_Display");
    display.print(0, 36, "v0.1.0");

    display.drawRect(
        0,
        52,
        128,
        12
    );

    display.fillRect(
        2,
        54,
        76,
        8
    );

    display.update();

    // Demonstrates access to the complete Adafruit SSD1306 API.
    display.native().invertDisplay(false);

    Serial.println("Display initialized successfully.");
}

void loop()
{
}