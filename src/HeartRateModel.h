#include "Event.h"
#include <functional>

class HeartRateModel : Event {
	public:
		typedef Event super; 
		enum listeners { heartRateChange };
		void addListener(int listener, std::function<void()> c);
		void addListener(listeners listener, std::function<void()> c);
		void dispatchEvent(int listener);
};