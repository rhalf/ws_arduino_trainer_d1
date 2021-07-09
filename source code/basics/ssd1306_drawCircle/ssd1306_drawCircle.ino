#include <U8g2lib.h>
U8G2_SSD1306_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE, /* clock=*/ SCL, /* data=*/ SDA);

void setup() {
  // put your setup code here, to run once:
  u8g2.begin();
  u8g2.enableUTF8Print();
}

void loop() {
  // put your main code here, to run repeatedly:
  u8g2.setFont(u8g2_font_profont11_tr);
  u8g2.firstPage();
  do {
    u8g2.drawCircle(64, 32, 10, U8G2_DRAW_ALL);
  } while ( u8g2.nextPage() );
}
