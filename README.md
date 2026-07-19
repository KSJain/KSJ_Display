# KSJ_Display

A reusable display abstraction for Arduino-compatible embedded projects.

The library currently includes:

- A small common graphics interface
- SSD1306 OLED support
- Text and basic drawing primitives
- Access to the complete native Adafruit SSD1306 API
- PlatformIO support

## Architecture

```text
Application / UI
        ↓
IGraphicsDevice
        ↓
SSD1306Display
        ↓
Adafruit SSD1306
        ↓
SSD1306 hardware