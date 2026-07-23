# KSJ_Display

Simple, reusable display abstractions for embedded projects.

KSJ_Display provides a consistent interface for displays while hiding the
details of individual display controllers. Applications should think about
drawing information—not talking to display hardware.

---

## Philosophy

Information builds knowledge.

Knowledge builds intuition.

Intuition builds instinct.

Instinct frees you to create.

---

## Why KSJ_Display?

Most projects begin by directly using a hardware library.

```cpp
Adafruit_SSD1306 display(...);
```

As projects grow, hardware details begin to spread throughout the application.

KSJ_Display separates those concerns.

Instead, applications simply work with a display.

```cpp
KSJ::SSD1306Display display(...);
```

The application describes **what** should be shown.

The library handles **how** it reaches the hardware.

---

## Features

- Simple object-oriented API
- SSD1306 support
- Non-blocking drawing
- Hardware abstraction
- Native driver access when needed
- Designed for reuse

---

## Current Support

| Display | Status |
|----------|--------|
| SSD1306 OLED | ✅ |
| SH1106 | Planned |
| TFT Displays | Planned |
| E-Paper | Planned |

---

## Quick Start

```cpp
KSJ::SSD1306Display display(
    128,
    64,
    0x3C
);

display.begin();

display.clear();

display.print(
    0,
    0,
    "Hello RAMU"
);

display.update();
```

---

## Example Projects

Included examples:

- Basic_Text

Used by:

- Prototype Box
- Future RAMU Dashboard
- Future Greenhouse Controller

---

## Repository Structure

include/
Public headers

src/
Library implementation

examples/
Standalone PlatformIO examples

docs/
Architecture and design notes

---

## Related Libraries

KSJ_Input

KSJ_UI

KSJ_Environment

Future:

KSJ_Output

KSJ_Control

---

## Learning Path

1. KSJ_Display
2. KSJ_Input
3. KSJ_UI
4. KSJ_Environment
5. KSJ_Output
6. KSJ_Control

---

## License

MIT License