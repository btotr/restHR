#include "HeartRateModel.h"

enum events { heartRateChange };

void HeartRateModel::on(int event, std::function<void()> c) {
	callbacks.push_back(std::make_pair(c, event));
};

void HeartRateModel::on(events event, std::function<void()> c) {
	callbacks.push_back(std::make_pair(c, static_cast<int>(event)));
};

void HeartRateModel::emit(int event) {
	for (int i=0; i< callbacks.size(); i++){
		 if (callbacks[i].second == event) {
		 	callbacks[i].first();
		 }
	 };
};