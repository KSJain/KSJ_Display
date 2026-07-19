
### Why

A stranger should be able to answer these questions without reading your source:

- What is this?
- What hardware does it support?
- How do I wire it?
- How do I install it?
- What does the simplest usage look like?
- How do I access advanced functionality?
- What intentionally does not belong here?

That last question is especially important because it protects the architecture from slowly becoming another giant `Display_Manager`.

---

# 7. Fill `docs/Wiring.md`

```markdown
# SSD1306 Wiring

## ESP32 DOIT DevKit V1

| SSD1306 Pin | ESP32 Pin |
|---|---|
| VCC | 3V3 |
| GND | GND |
| SDA | GPIO 21 |
| SCL | GPIO 22 |

## Default Configuration

- Resolution: 128 × 64
- Interface: I2C
- Address: `0x3C`
- Reset pin: `-1`

## Notes

Some SSD1306 modules use address `0x3D`.

If initialization fails:

1. Verify power and ground.
2. Confirm SDA and SCL wiring.
3. Run an I2C scanner.
4. Try address `0x3D`.
5. Confirm that the display controller is SSD1306 rather than SH1106.