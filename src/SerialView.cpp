#include <Arduino.h>

#include "SerialView.h"

void SerialView::init()
{
      Serial.begin(9600);
}

void SerialView::showBPM(int bpm) 
{
	 Serial.println(bpm);
}