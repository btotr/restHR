#ifndef UNIT_TEST
#include <Arduino.h>
#include <OLEDView.h>
#include <HeartRateModel.h>


class OLEDView view;
class HeartRateModel hrModel;

void callback() {
	view.showBPM(hrModel.getBPM());
}

void setup() {
  view.init();
  hrModel.on(HeartRateModel::heartRateChange, callback);
}

void loop() {
      int QS = hrModel.getQS();
      if (QS){
        hrModel.emit(HeartRateModel::heartRateChange);
      }
}
#endif