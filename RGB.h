#pragma once

struct RGB {
  uint8_t red = 255, green = 255, blue = 255;
public:
  RGB() {}
  RGB(uint8_t red, uint8_t green, uint8_t blue): red(red), green(green), blue(blue) {}
};
