#include <U8g2lib.h>
U8G2_SSD1306_128X64_NONAME_1_HW_I2C 
u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE, /* clock=*/ SCL, /* data=*/ SDA);

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
    u8g2.setDrawColor(1);
    u8g2.drawBox(2, 2, 124, 60);

    u8g2.setDrawColor(2);
    u8g2.drawBox(4, 4, 120, 56);
  } while ( u8g2.nextPage() );
}
