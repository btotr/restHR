#include "Event.h"
#include <functional>

class HeartRateModel : Event {
	public:
		void addListener(int listener, std::function<void()> c);
		void dispatchEvent(int listener);
};