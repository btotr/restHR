#ifndef ARDUINO
#include <iostream>
#include "HeartRateModel.h"
#include "SerialView.h"

void callback() {
	std::cout << "callback\n";
}

#ifndef UNIT_TEST
int main()
{
	class HeartRateModel hrModel;
	class SerialView view;

	std::cout << HeartRateModel::heartRateChange << "addlistener\n";
	hrModel.on(HeartRateModel::heartRateChange, callback);
	hrModel.emit(HeartRateModel::heartRateChange);
}
#endif
#endif