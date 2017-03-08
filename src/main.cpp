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

	std::cout << "addlistener\n";
	hrModel.addListener(0, callback);
	hrModel.dispatchEvent(0);
}