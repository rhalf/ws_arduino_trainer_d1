#include<Timer.h>

Timer timer0(Timer::MILLIS), timer1(Timer::MILLIS), timer2(Timer::MILLIS), timer3(Timer::MILLIS), timer4(Timer::MILLIS);

void callback0() {
  Serial.println("never print");
}
void callback1() {
  Serial.println("print once");
}
void callback2() {
  Serial.println("print twice");
}
void callback3() {
  Serial.println("print forever");
}
void callback4() {
  timerStop();
  Serial.println("stop all timers");
};

void timerStop() {
  timer0.stop();
  timer1.stop();
  timer2.stop();
  timer3.stop();
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println(F("Welcome to Timer class..."));
  Serial.println(F("rhalfcaacbay@gmail.com"));

  timer0.begin(Timer::NEVER, 1000, callback0);
  timer1.begin(Timer::ONCE, 1000, callback1);
  timer2.begin(Timer::TWICE, 1000, callback2);
  timer3.begin(Timer::FOREVER, 1000, callback3);
  timer4.begin(Timer::ONCE, 10000, callback4);


  timer0.start();
  timer1.start();
  timer2.start();
  timer3.start();
  timer4.start();
}

void loop() {
  // put your main code here, to run repeatedly:
  timer0.run();
  timer1.run();
  timer2.run();
  timer3.run();
  timer4.run();
}