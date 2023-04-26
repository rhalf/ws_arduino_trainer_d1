#include <U8g2lib.h>
U8G2_SSD1306_128X64_NONAME_1_HW_I2C 
u8g2(U8G2_R0, /*reset=*/U8X8_PIN_NONE, /*clock=*/SCL, /*data=*/SDA);

void setup() {
  u8g2.begin();
  u8g2.enableUTF8Print();
  u8g2.setFont(u8g2_font_profont11_tr);
}
void loop() {
  u8g2.firstPage();
  do {
    u8g2.setCursor(0, 10);
    u8g2.print("Hello world!");
    u8g2.setCursor(0, 60);
    u8g2.print("Hello DMMMSU!");
  } while ( u8g2.nextPage() );
}
