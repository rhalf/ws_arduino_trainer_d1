#include <U8g2lib.h>
U8G2_SSD1306_128X64_NONAME_1_HW_I2C
u8g2(U8G2_R0, /*reset=*/U8X8_PIN_NONE, /*clock=*/SCL, /*data=*/SDA);

#include <Encoder.h>
uint8_t const DT = 2, CLK = 3, SW = 4;

Encoder encoder(DT, CLK);
int8_t data = -128;

String value;
bool isPressed;

void readEncoder() {
  int8_t newData = encoder.read();
  if (newData != data) {
    data = newData;
    value = String(newData);
  }
  isPressed = digitalRead(SW) == LOW;
}

void setup() {
  u8g2.begin();
  u8g2.enableUTF8Print();
  u8g2.setFont(u8g2_font_profont11_tr);

  pinMode(SW, INPUT_PULLUP);
}

void render() {
  u8g2.firstPage();
  do {
    u8g2.setCursor(0, 10);
    u8g2.print(value);
    u8g2.setCursor(0, 20);
    if (isPressed) {
      u8g2.print("button is pressed");
    } else {
      u8g2.print("                 ");
    }
  } while (u8g2.nextPage());
}

void loop() {
  readEncoder();
  render();
}
