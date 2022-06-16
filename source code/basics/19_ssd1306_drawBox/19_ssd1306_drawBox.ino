#include <U8g2lib.h>
U8G2_SSD1306_128X64_NONAME_1_HW_I2C 
u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE, /* clock=*/ SCL, /* data=*/ SDA);

void setup() {
  u8g2.begin();
  u8g2.enableUTF8Print();
  u8g2.setFont(u8g2_font_profont11_tr);
}
void loop() {
  u8g2.firstPage();
  do {
    //draw box
    u8g2.setDrawColor(1);
    u8g2.drawBox(2, 2, 124, 60);

    u8g2.setDrawColor(2);
    u8g2.drawBox(4, 4, 120, 56);
    //draw circle
    u8g2.drawCircle(64, 32, 10, U8G2_DRAW_ALL);
    //draw lines
    u8g2.drawLine(2, 0, 126, 62);
    u8g2.drawHLine(0, 32, 128);
    u8g2.drawVLine(64, 0, 64);
    //draw string
    u8g2.drawStr(0, 64, "Line");

  } while ( u8g2.nextPage() );
}
