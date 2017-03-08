#include "HeartRateModel.h"

enum listeners { heartRateChange };

void HeartRateModel::addListener(int listener, std::function<void()> c) {
	callbacks.push_back(std::make_pair(c, listener));
};

void HeartRateModel::dispatchEvent(int listener) {
	for (int i=0; i< callbacks.size(); i++){
		 if (callbacks[i].second == listener) {
		 	callbacks[i].first();
		 }
	 };
};