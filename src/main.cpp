#include <iostream>
#include "HeartRateModel.h"
#include "SerialView.h"

void callback() {
	std::cout << "callback\n";
}

int main()
{
	class HeartRateModel hrModel;
	class SerialView view;

	std::cout << HeartRateModel::listeners::heartRateChange << "addlistener\n";
	hrModel.addListener(HeartRateModel::heartRateChange, callback);
	hrModel.dispatchEvent(HeartRateModel::heartRateChange);
}