#include <Arduino.h>
#include <Wire.h>

#include "KSJ_SSD1306Display.h"
#include "PrototypeBoxConfig.h"

KSJ::SSD1306Display display(
    PrototypeBox::Display::WIDTH,
    PrototypeBox::Display::HEIGHT,
    PrototypeBox::Display::I2C_ADDRESS,
    PrototypeBox::Display::RESET_PIN
);

void haltWithError(const char* message)
{
    Serial.println(message);

    while (true)
    {
        delay(1000);
    }
}

void drawStartupScreen()
{
    display.clear();

    display.setTextSize(2);
    display.print(0, 0, "Hello, KSJ");

    display.setTextSize(1);
    display.print(0, 24, PrototypeBox::Board::NAME);
    display.print(0, 36, PrototypeBox::Board::MCU);

    display.drawRect(0, 52, 128, 12);
    display.fillRect(2, 54, 76, 8);

    display.update();
}

void setup()
{
    Serial.begin(115200);
    delay(200);

    Wire.begin(
        PrototypeBox::Pins::SDA,
        PrototypeBox::Pins::SCL
    );

    Serial.println();
    Serial.println("------------------------------");
    Serial.println(PrototypeBox::Board::NAME);
    Serial.println(PrototypeBox::Board::MCU);
    Serial.print("Firmware: ");
    Serial.println(PrototypeBox::Board::VERSION);
    Serial.println("------------------------------");

    if (!display.begin())
    {
        haltWithError("Display initialization failed.");
    }

    Serial.println("Display initialization succeeded.");

    drawStartupScreen();
}

void loop()
{
}