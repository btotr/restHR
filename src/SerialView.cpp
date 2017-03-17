#ifdef ARDUINO
#include <Arduino.h>

#include "SerialView.h"

void SerialView::showBPM(int bpm) 
{
	 Serial.println(bpm);
}
#endif