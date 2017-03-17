#ifndef UNIT_TEST
#include <Arduino.h>
#include <SerialView.h>
#include <HeartRateModel.h>

class SerialView view;
class HeartRateModel hrModel;

void callback() {
	view.test();
}

void setup() {
  Serial.begin(9600);
  hrModel.on(HeartRateModel::heartRateChange, callback);
}

void loop() {
  delay(1000);
  hrModel.emit(HeartRateModel::heartRateChange);
}
#endif