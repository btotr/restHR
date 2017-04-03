#ifdef ARDUINO
#include <Arduino.h>

#include "SerialView.h"

void SerialView::showBPM(int bpm) 
{
	 Serial.println(bpm);
}

void SerialView::showQS(int QS) 
{
	 Serial.println(QS);
}
#endif