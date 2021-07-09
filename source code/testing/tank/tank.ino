#include<Timer.h>

Timer tUi(Timer::MILLIS);
Timer tMotor(Timer::MILLIS);
Timer tControl(Timer::MILLIS);

#include <U8g2lib.h>
U8G2_SSD1306_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE, /* clock=*/ SCL, /* data=*/ SDA);

#include <Encoder.h>
uint8_t const DT = 2, CLK = 3, SW = 4;
Encoder encoder(DT, CLK);

uint8_t IN1 = 10, IN2 = 9, IN3 = 6, IN4 = 5, SPEED = 255;
uint8_t counter = 0, selector = 0, speed = 255;

String motorState = "";

void ui() {
  u8g2.firstPage();
  do {
    u8g2.setFont(u8g2_font_profont11_tr);
    u8g2.setCursor(0, 10);
    u8g2.print("Motor Driver");
    u8g2.setCursor(0, 20);
    u8g2.print("Motor ");
    if (selector == 0 || selector == 1) {
      u8g2.print("A");
    }
    if (selector == 2 || selector == 3) {
      u8g2.print("B");
    }
    u8g2.setCursor(0, 30);
    u8g2.print(motorState);
    u8g2.setCursor(0, 40);
    u8g2.print("Speed ");
    u8g2.print(speed);

  } while ( u8g2.nextPage() );
}

void motor() {
  selector = counter % 4;

  if (selector == 0) {
    analogWrite(IN1, speed);
    analogWrite(IN2, 0);
    analogWrite(IN3, 0);
    analogWrite(IN4, 0);
    motorState = "COUNTER CLOCKWISE";
  }

  if (selector == 1) {
    analogWrite(IN1, 0);
    analogWrite(IN2, speed);
    analogWrite(IN3, 0);
    analogWrite(IN4, 0);
    motorState = "CLOCKWISE";
  }
  if (selector == 2) {
    analogWrite(IN1, 0);
    analogWrite(IN2, 0);
    analogWrite(IN3, speed);
    analogWrite(IN4, 0);
    motorState = "COUNTER CLOCKWISE";
  }
  if (selector == 3) {
    analogWrite(IN1, 0);
    analogWrite(IN2, 0);
    analogWrite(IN3, 0);
    analogWrite(IN4, speed);
    motorState = "CLOCKWISE";
  }

  counter++;
}

void control() {
//  uint8_t value = encoder.read();
//  if (abs(value - speed) < 50) {
//    speed = value;
//  }
Serial.println(selector);
}



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(SW, INPUT_PULLUP);

  pinMode(IN2, OUTPUT);
  pinMode(IN4, OUTPUT);
  analogWrite(IN1, 0);
  analogWrite(IN2, 0);
  analogWrite(IN3, 0);
  analogWrite(IN4, 0);

  u8g2.begin();
  u8g2.enableUTF8Print();

  tUi.begin(Timer::FOREVER, 250, ui);
  tMotor.begin(Timer::FOREVER, 3000, motor);
  tControl.begin(Timer::FOREVER, 100, control);

  tUi.start();
  tMotor.start();
  tControl.start();
}

void loop() {
  // put your main code here, to run repeatedly:
  tUi.run();
  tMotor.run();
  tControl.run();
}
