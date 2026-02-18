/*
 * 67 Mustang Pixel Font Demo
 * 
 * Demonstrates the 67_mustang_pixel_font.h 7x24 pixel bitmap font
 * on a 128x64 SSD1306 OLED display.
 * 
 * Hardware:
 *   - Arduino Uno/Nano/Mega (or compatible AVR board)
 *   - SSD1306 OLED display (128x64, I2C)
 * 
 * Connections:
 *   - SDA -> A4 (Uno/Nano) or pin 20 (Mega)
 *   - SCL -> A5 (Uno/Nano) or pin 21 (Mega)
 *   - VCC -> 5V (or 3.3V depending on module)
 *   - GND -> GND
 */

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "67_mustang_pixel_font.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(9600);
  
  // Initialize the OLED display
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Halt
  }
  
  display.clearDisplay();
  display.display();
  delay(500);
}

void loop() {
  // Demo 1: Uppercase text centered
  display.clearDisplay();
  const char* msg1 = "MUSTANG";
  uint16_t w1 = stringWidth(msg1, false);
  int16_t x1 = (SCREEN_WIDTH - w1) / 2;
  drawString(display, x1, 5, msg1, SSD1306_WHITE, false);
  display.display();
  delay(2000);
  
  // Demo 2: Mixed case text
  display.clearDisplay();
  const char* msg2 = "Hello World";
  uint16_t w2 = stringWidth(msg2, true);
  int16_t x2 = (SCREEN_WIDTH - w2) / 2;
  drawString(display, x2, 10, msg2, SSD1306_WHITE, true);
  display.display();
  delay(2000);
  
  // Demo 3: Numbers
  display.clearDisplay();
  const char* msg3 = "1967";
  uint16_t w3 = stringWidth(msg3, false);
  int16_t x3 = (SCREEN_WIDTH - w3) / 2;
  drawString(display, x3, 20, msg3, SSD1306_WHITE, false);
  display.display();
  delay(2000);
  
  // Demo 4: Multi-line display
  display.clearDisplay();
  drawString(display, 5, 0, "Speed: 67", SSD1306_WHITE, true);
  drawString(display, 5, 25, "Temp: 195F", SSD1306_WHITE, true);
  display.display();
  delay(2000);
  
  // Demo 5: Punctuation and symbols
  display.clearDisplay();
  const char* msg5 = "!@#$%^&*()";
  uint16_t w5 = stringWidth(msg5, false);
  int16_t x5 = (SCREEN_WIDTH - w5) / 2;
  drawString(display, x5, 15, msg5, SSD1306_WHITE, false);
  display.display();
  delay(2000);
  
  // Demo 6: Lowercase alphabet showcase
  display.clearDisplay();
  drawString(display, 0, 0, "abcdefghijk", SSD1306_WHITE, true);
  drawString(display, 0, 25, "lmnopqrstuv", SSD1306_WHITE, true);
  display.display();
  delay(2000);
  
  display.clearDisplay();
  drawString(display, 0, 0, "wxyz", SSD1306_WHITE, true);
  drawString(display, 0, 25, "0123456789", SSD1306_WHITE, true);
  display.display();
  delay(2000);
  
  // Demo 7: Styled message
  display.clearDisplay();
  const char* msg7a = "67 Mustang";
  const char* msg7b = "Pixel Font";
  uint16_t w7a = stringWidth(msg7a, true);
  uint16_t w7b = stringWidth(msg7b, true);
  int16_t x7a = (SCREEN_WIDTH - w7a) / 2;
  int16_t x7b = (SCREEN_WIDTH - w7b) / 2;
  drawString(display, x7a, 5, msg7a, SSD1306_WHITE, true);
  drawString(display, x7b, 35, msg7b, SSD1306_WHITE, true);
  display.display();
  delay(3000);
  
  // Demo 8: Scrolling numbers (simulated counter)
  for (int i = 0; i <= 100; i += 5) {
    display.clearDisplay();
    char buffer[16];
    sprintf(buffer, "Count: %d", i);
    uint16_t w = stringWidth(buffer, true);
    int16_t x = (SCREEN_WIDTH - w) / 2;
    drawString(display, x, 20, buffer, SSD1306_WHITE, true);
    display.display();
    delay(200);
  }
  
  delay(1000);
}
