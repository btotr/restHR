#include "Event.h"
#include <functional>

class HeartRateModel : Event {
	public:
		HeartRateModel();
		enum events { heartRateChange };
		void on(int event, std::function<void()> c);
		void on(events event, std::function<void()> c);
		void emit(int event);
		int getBPM();
		
};