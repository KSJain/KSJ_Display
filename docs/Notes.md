# Notes

## Verified Configuration

- Board: ESP32 DOIT DevKit V1
- Display: SSD1306
- Resolution: 128 × 64
- Interface: I2C
- Address: `0x3C`
- SDA: GPIO 21
- SCL: GPIO 22

## Native API

`SSD1306Display::native()` returns a reference to the underlying `Adafruit_SSD1306` object.

Example:

```cpp
display.native().invertDisplay(true);