#include "Event.h"
#include <functional>

class HeartRateModel : Event {
	public:
		typedef Event super; 
		enum events { heartRateChange };
		void on(int event, std::function<void()> c);
		void on(events event, std::function<void()> c);
		void emit(int event);
};