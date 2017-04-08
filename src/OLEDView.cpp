#include "OLEDView.h"
#include "SSD1306.h"

SSD1306 display(0x3c, D2, D1);

void OLEDView::init() 
{
	display.init();
	display.setFont(ArialMT_Plain_24);
	display.setTextAlignment(TEXT_ALIGN_CENTER_BOTH);
	display.flipScreenVertically();
}



void OLEDView::showBPM(int bpm) 
{
	display.clear();
	display.drawString(10, 10, String(bpm));
	display.display();
}