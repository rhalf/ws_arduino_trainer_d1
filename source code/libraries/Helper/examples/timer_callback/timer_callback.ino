#include<Timer.h>

Timer timer0, timer1, timer2, timer3, timer4;

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
  timerOff();
  Serial.println("pause all timers");
};



void timerOff() {
  timer0.pause();
  timer1.pause();
  timer2.pause();
  timer3.pause();
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("welcome to Timer class...");

  timer0.set(Timer::NEVER, 1000, callback0);
  timer1.set(Timer::ONCE, 1000, callback1);
  timer2.set(Timer::TWICE, 1000, callback2);
  timer3.set(Timer::FOREVER, 1000, callback3);
  timer4.set(Timer::ONCE, 10000, callback4);


  timer0.start();
  timer1.start();
  timer2.start();
  timer3.start();
  timer4.start();
}

void loop() {
  // put your main code here, to run repeatedly:
  timer0.execute();
  timer1.execute();
  timer2.execute();
  timer3.execute();
  timer4.execute();
}
