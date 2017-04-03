#ifndef UNIT_TEST
#include <Arduino.h>
#include <Ticker.h>
#include <SerialView.h>
#include <HeartRateModel.h>

class SerialView view;
class HeartRateModel hrModel;

void callback() {
	view.showBPM(hrModel.getBPM());
}

void setup() {
  Serial.begin(9600);
  hrModel.on(HeartRateModel::heartRateChange, callback);
}

void loop() {
      int QS = hrModel.getQS();
      // view.showQS(QS);
      if (QS){
        hrModel.emit(HeartRateModel::heartRateChange);
      }
      
}
#endif