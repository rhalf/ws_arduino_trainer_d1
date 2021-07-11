//===================================================================Helper
//#include<Helper.h>
//Helper helper;
//===================================================================Timer
#include<Timer.h>
Timer tDisplay(Timer::MILLIS);
Timer tInterrupt(Timer::MILLIS);
//===================================================================Lcd
#include <U8g2lib.h>
U8G2_SSD1306_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE, /* clock=*/ SCL, /* data=*/ SDA);
//===================================================================Encoder
#include <Encoder.h>
const uint8_t ENCODER_CLK = 2, ENCODER_DT = 3, ENCODER_SW = 4;
Encoder encoder(ENCODER_CLK, ENCODER_DT);
//===================================================================Buzzer
#include <Buzzer.h>
const uint8_t BUZZER_PIN = A0;
Buzzer buzzer = Buzzer(BUZZER_PIN, 440);
//===================================================================Temperature Sensor
const uint8_t LM35_PIN = A7;
//===================================================================Potentiometer
const uint8_t POTENTIOMETER_PIN = A6;
//===================================================================RGB Led
const uint8_t RGB_P1 = 9;
const uint8_t RGB_P2 = 10;
const uint8_t RGB_P3 = 11;
//===================================================================Motor
const uint8_t MOTOR_A1 = 10;
const uint8_t MOTOR_A2 = 9;
const uint8_t MOTOR_B1 = 6;
const uint8_t MOTOR_B2 = 5;
//===================================================================Max7219
#include "LedControl.h"
uint8_t MAX7219_CLK = A1, MAX7219_DT = A3, MAX7219_CS = A2, MAX7219_CHIP = 1;
LedControl lc = LedControl(MAX7219_DT, MAX7219_CLK, MAX7219_CS, MAX7219_CHIP);
uint8_t MAX7219_ADDRESS = 0;
//===================================================================softSerial
#include<SoftwareSerial.h>
uint8_t SOFTSERIAL_RX = 8, SOFTSERIAL_TX = 7;
SoftwareSerial softSerial(SOFTSERIAL_RX, SOFTSERIAL_TX);
//===================================================================Global
const char title[] PROGMEM = {"Arduino Trainer D1"};
const char label1[] PROGMEM = {"Encoder     : "};
const char label2[] PROGMEM = {"Tact Switch : "};
const char label3[] PROGMEM = {"Potentio/LDR: "};
const char label4[] PROGMEM = {"Temperature : "};
const char label5[] PROGMEM = {"Run Time    : "};

const char label6[] PROGMEM = {"RGB"};
const char label7[] PROGMEM = {"Buzzer"};
const char label8[] PROGMEM = {"MX1508"};
const char label9[] PROGMEM = {"MAX7219"};
const char label10[] PROGMEM = {"HC05"};
const char label11[] PROGMEM = {"SIM800l"};

const char *msgYesNo = {" Yes \n No "};
const char *msgStop = {"Stop"};
const char *msgOff = { "Off"};
const char *msgScan = {"Scan"};

const char *listMenu =
  "back\n"
  "About\n"

  "RGB\n"
  "Buzzer\n"
  "Mx1508\n"
  "Max7219\n"
  "HC05\n"
  "Sim800l";


const char *listRgb =
  "back\n"
  "P1\n"
  "P2\n"
  "P3\n"
  "off";

const char *listBuzzer =
  "back\n"
  "active\n"
  "passive\n"
  "frequency\n"
  "off";

const char *listMax7219 =
  "back\n"
  "set Number\n"
  "set Scan \n"
  "off";

const char *listMotor =
  "back\n"
  "speed\n"
  "ma_cc\n"
  "ma_cw\n"
  "mb_cc\n"
  "mb_cw\n"
  "off";

const char *listBluetooth =
  "back\n"
  "name\n"
  "version\n"
  "address";

const char *listGsm =
  "back\n"
  "manufacturer\n"
  "model\n"
  "revision\n"
  "imei";


char buff[20];

struct Inputs {
  uint8_t encoder;
  uint8_t tactA;
  uint8_t tactB;
  uint16_t pot;
  float temp;
  uint64_t runTime;
};

Inputs inputs = {0, 0, 0, 0, 0, 0};

uint8_t
stateDisplay = 0,
menuSelection = 1;


void ring() {
  buzzer.play();
  delay(100);
  buzzer.stop();
}
//===================================================================Functions Display Rendering
void uiMain() {
  u8g2.firstPage();
  do {
    //--------------------------------------Title
    u8g2.setFontMode(1);
    u8g2.setDrawColor(2);
    u8g2.drawBox(0, 0, 128, 11);

    u8g2.setCursor(4, 10);
    strcpy_P(buff, title);
    u8g2.print(buff);

    //--------------------------------------encoder
    u8g2.setCursor(0, 20);
    strcpy_P(buff, label1);
    u8g2.print(buff);

    u8g2.setCursor(90, 20);
    u8g2.print(inputs.encoder);
    //--------------------------------------tact
    u8g2.setCursor(0, 30);
    strcpy_P(buff, label2);
    u8g2.print(buff);

    u8g2.setCursor(90, 30);
    u8g2.print(inputs.tactA);
    u8g2.print(" | ");
    u8g2.print(inputs.tactB);
    //
    //--------------------------------------pot
    u8g2.setCursor(0, 40);
    strcpy_P(buff, label3);
    u8g2.print(buff);

    u8g2.setCursor(90, 40);
    u8g2.print(inputs.pot);
    //--------------------------------------temp
    u8g2.setCursor(0, 50);
    strcpy_P(buff, label4);
    u8g2.print(buff);

    u8g2.setCursor(90, 50);
    u8g2.print(inputs.temp);
    //--------------------------------------runTime
    u8g2.setCursor(0, 60);
    strcpy_P(buff, label5);
    u8g2.print(buff);

    u8g2.setCursor(90, 60);
    //u8g2.print(helper.toUtf8Time(inputs.runTime));
    u8g2.print((long) inputs.runTime);

  } while (u8g2.nextPage());
}
void uiRgb() {
  uint8_t result = 0;
  uint8_t value1 = 0, value2 = 0, value3 = 0;
  while (true) {
    strcpy_P(buff, label6);
    uint8_t subMenuSelection = u8g2.userInterfaceSelectionList(
                                 buff,
                                 subMenuSelection,
                                 listRgb);

    ring();

    switch (subMenuSelection) {
      case 1:
        return;
        break;
      case 2:
        u8g2.userInterfaceInputValue(
          "",
          "",
          &value1,
          0,
          10,
          2,
          "");
        analogWrite(RGB_P1, value1);
        break;
      case 3:
        u8g2.userInterfaceInputValue(
          "",
          "",
          &value2,
          0,
          10,
          2,
          "");
        analogWrite(RGB_P2, value2);
        break;
      case 4:
        u8g2.userInterfaceInputValue(
          "",
          "",
          &value3,
          0,
          10,
          2,
          "");
        analogWrite(RGB_P3, value3);
        break;
      case 5:
        result = u8g2.userInterfaceMessage(
                   "",
                   msgOff,
                   "",
                   msgYesNo);
        if (result == 1) {
          analogWrite(RGB_P1, 0);
          analogWrite(RGB_P2, 0);
          analogWrite(RGB_P3, 0);
        }
        break;
    }
  }
}
void uiBuzzer() {
  uint8_t result = 0;
  uint8_t value = 4;
  while (true) {
    strcpy_P(buff, label7);
    uint8_t subMenuSelection = u8g2.userInterfaceSelectionList(
                                 buff,
                                 subMenuSelection,
                                 listBuzzer);

    ring();
    switch (subMenuSelection) {
      case 1:
        return;
        break;
      case 2:
        digitalWrite(BUZZER_PIN, !digitalRead(BUZZER_PIN));
        result = u8g2.userInterfaceMessage(
                   "",
                   msgStop,
                   "",
                   msgYesNo);
        if (result == 1) {
          digitalWrite(BUZZER_PIN, !digitalRead(BUZZER_PIN));
        }
        break;
      case 3:
        tone(BUZZER_PIN, value * 100);
        result = u8g2.userInterfaceMessage(
                   "",
                   msgStop,
                   "",
                   msgYesNo);
        if (result == 1) {
          noTone(BUZZER_PIN);
        }
        break;
      case 4:
        u8g2.userInterfaceInputValue(
          "",
          "",
          &value,
          0,
          40,
          2,
          "00 hz");
      case 5:
        noTone(BUZZER_PIN);
        break;

    }
  }
}
void uiMotor() {
  uint8_t result = 0;
  uint8_t value = 10;
  while (true) {
    strcpy_P(buff, label8);
    uint8_t subMenuSelection = u8g2.userInterfaceSelectionList(
                                 buff,
                                 subMenuSelection,
                                 listMotor);

    ring();

    switch (subMenuSelection) {
      case 1:
        return;
        break;
      case 2:
        u8g2.userInterfaceInputValue(
          "",
          "",
          &value,
          0,
          10,
          2,
          "");
        break;
      case 3:
        analogWrite(MOTOR_A1, value * 25);
        analogWrite(MOTOR_A2, 0);
        analogWrite(MOTOR_B1, 0);
        analogWrite(MOTOR_B2, 0);
        result = u8g2.userInterfaceMessage(
                   "MA_CC",
                   msgStop,
                   "",
                   msgYesNo);
        if (result == 1) {
          analogWrite(MOTOR_A1, 0);
        }
        break;
      case 4:
        analogWrite(MOTOR_A1, 0);
        analogWrite(MOTOR_A2, value * 25);
        analogWrite(MOTOR_B1, 0);
        analogWrite(MOTOR_B2, 0);
        result = u8g2.userInterfaceMessage(
                   "MA_CW",
                   msgStop,
                   "",
                   msgYesNo);
        if (result == 1) {
          analogWrite( MOTOR_A2, 0);
        }
        break;
      case 5:
        analogWrite(MOTOR_A1, 0);
        analogWrite(MOTOR_A2, 0);
        analogWrite(MOTOR_B1, value * 25);
        analogWrite(MOTOR_B2, 0);

        result = u8g2.userInterfaceMessage(
                   "MB_CC",
                   msgStop,
                   "",
                   msgYesNo);
        if (result == 1) {
          analogWrite( MOTOR_B1, 0);
        }
        break;
      case 6:
        analogWrite(MOTOR_A1, 0);
        analogWrite(MOTOR_A2, 0);
        analogWrite(MOTOR_B1, 0);
        analogWrite(MOTOR_B2, value * 25);


        result = u8g2.userInterfaceMessage(
                   "MB_CW",
                   msgStop,
                   "",
                   msgYesNo);
        if (result == 1) {
          analogWrite( MOTOR_B2, 0);
        }
        break;
      case 7:
        result = u8g2.userInterfaceMessage(
                   "",
                   msgOff,
                   "",
                   msgYesNo);
        if (result == 1) {
          analogWrite( MOTOR_A1, 0);
          analogWrite( MOTOR_A2, 0);
          analogWrite( MOTOR_B1, 0);
          analogWrite( MOTOR_B2, 0);
        }
        break;
    }
  }
}
void uiMax7219() {
  uint8_t result = 0;
  uint8_t value = 0;
  while (true) {
    strcpy_P(buff, label9);
    uint8_t subMenuSelection = u8g2.userInterfaceSelectionList(
                                 buff,
                                 subMenuSelection,
                                 listMax7219);

    ring();

    switch (subMenuSelection) {
      case 1:
        return;
        break;
      case 2:
        u8g2.userInterfaceInputValue(
          "",
          "",
          &value,
          0,
          255,
          3,
          "");
        show7segment(value);
        break;
      case 3:
        result = u8g2.userInterfaceMessage(
                   "",
                   msgScan,
                   "",
                   msgYesNo);
        if (result == 1) {
          showDotMatrix();
        }
        break;
      case 4:
        result = u8g2.userInterfaceMessage(
                   "",
                   msgOff,
                   "",
                   msgYesNo);
        if (result == 1) {
          lc.clearDisplay(MAX7219_ADDRESS);
        }
        break;

    }
  }
}

void uiBluetooth() {
  uint8_t result = 0;
  String info = "";
  while (true) {
    strcpy_P(buff, label10);
    uint8_t subMenuSelection = u8g2.userInterfaceSelectionList(
                                 buff,
                                 subMenuSelection,
                                 listBluetooth);

    ring();

    switch (subMenuSelection) {
      case 1:
        return;
        break;
      case 2:
        info = sendCommand("NAME");
        result = u8g2.userInterfaceMessage(
                   info.c_str(),
                   "",
                   "",
                   "");
        break;
      case 3:
        info = sendCommand("VERSION");
        result = u8g2.userInterfaceMessage(
                   info.c_str(),
                   "",
                   "",
                   "");
        break;
      case 4:
        info = sendCommand("ADDR");
        result = u8g2.userInterfaceMessage(
                   info.c_str(),
                   "",
                   "",
                   "");
        break;

    }
  }
}

void uiSoftSerialGsm() {
  uint8_t result = 0;
  String info = "";
  while (true) {
    strcpy_P(buff, label11);
    uint8_t subMenuSelection = u8g2.userInterfaceSelectionList(
                                 buff,
                                 subMenuSelection,
                                 listGsm);

    ring();

    switch (subMenuSelection) {
      case 1:
        return;
        break;
      case 2:
        info = sendCommand("CGMI");
        result = u8g2.userInterfaceMessage(
                   info.c_str(),
                   "",
                   "",
                   "");
        break;
      case 3:
        info = sendCommand("CGMM");
        result = u8g2.userInterfaceMessage(
                   info.c_str(),
                   "",
                   "",
                   "");
        break;
      case 4:
        info = sendCommand("CGMR");
        result = u8g2.userInterfaceMessage(
                   info.c_str(),
                   "",
                   "",
                   "");
        break;
      case 5:
        info = sendCommand("CGSN");
        result = u8g2.userInterfaceMessage(
                   info.c_str(),
                   "",
                   "",
                   "");
        break;
    }
  }
}
void uiMenu() {
  uint8_t result = 0;
  ring();
  strcpy_P(buff, title);
  menuSelection = u8g2.userInterfaceSelectionList(
                    buff,
                    menuSelection,
                    listMenu);

  ring();
  switch (menuSelection) {
    case 1:
      stateDisplay = 0;
      break;
    case 2:
      result = u8g2.userInterfaceMessage(
                 "v0.2 (20210710)",
                 "",
                 "09176088771",
                 "rhalfcaacbay@gmail.com");
      break;
    case 3:
      uiRgb();
      break;
    case 4:
      uiBuzzer();
      break;
    case 5:
      uiMotor();
      break;
    case 6:
      uiMax7219();
      break;
    case 7:
      uiBluetooth();
      break;
    case 8:
      uiSoftSerialGsm();
      break;
  }
  ring();
}
//===================================================================Functions Display
void cbDisplay() {
  uiMain();
}
//===================================================================Functions Interrupt
void cbInterrupt() {
  uint8_t key = u8g2.getMenuEvent();
  Serial.println(key);
  switch (key) {
    case U8X8_MSG_GPIO_MENU_SELECT:
      uiMenu();
      break;
    case U8X8_MSG_GPIO_MENU_NEXT:
      break;
    case U8X8_MSG_GPIO_MENU_PREV:
      break;
    case U8X8_MSG_GPIO_MENU_HOME:
      break;
    case U8X8_MSG_GPIO_MENU_UP:
      break;
    case U8X8_MSG_GPIO_MENU_DOWN:
      break;
  }

  inputs.encoder = encoder.read();

  inputs.tactA = !digitalRead(ENCODER_DT);
  inputs.tactB = !digitalRead(ENCODER_CLK);

  inputs.pot = analogRead(POTENTIOMETER_PIN);
  inputs.temp = analogRead(LM35_PIN) * (5000.0 / 1024.0) / 10 ;
  inputs.runTime =  Timer::getSeconds();
}


String sendCommand(String command) {
  softSerial.print("AT+" + command + "\r\n");
  String info;
  uint16_t timeout = 1000;
  for (uint16_t counter = 0; counter < timeout; counter++ ) {
    delay(1);
    while (softSerial.available()) {
      char data = (char) softSerial.read();
      info += data;
    }
  }
  return info;
}
void show7segment(uint32_t number) {
  lc.clearDisplay(MAX7219_ADDRESS);
  for (uint8_t index = 0; index < 8; index++) {
    float value =  number / (pow(10, index));
    uint8_t digit = ((int)value) % 10;
    lc.setDigit(MAX7219_ADDRESS, index, digit, false);
  }
}

void showDotMatrix() {
  lc.clearDisplay(MAX7219_ADDRESS);
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 8; col++) {
      delay(50);
      lc.setLed(MAX7219_ADDRESS, row, col, true);
      delay(50);
    }
  }
}

void setup(void) {
  Serial.begin(9600);
  softSerial.begin(9600);

  u8g2.begin(/*Select=*/ ENCODER_SW, /*Right/Next=*/ ENCODER_DT, /*Left/Prev=*/ENCODER_CLK , /*Up=*/ -1, /*Down=*/ -1, /*Home/Cancel=*/ -1); // Arduboy DevKit
  u8g2.setFont(u8g2_font_profont11_tf);
  u8g2.enableUTF8Print();

  tDisplay.begin(Timer::FOREVER, 250, cbDisplay);
  tDisplay.start();

  tInterrupt.begin(Timer::FOREVER, 1, cbInterrupt);
  tInterrupt.start();

  lc.shutdown(MAX7219_ADDRESS, false);
  lc.setIntensity(MAX7219_ADDRESS, 4);
  lc.clearDisplay(MAX7219_ADDRESS);
}

void loop(void) {
  tInterrupt.run();
  tDisplay.run();
}
