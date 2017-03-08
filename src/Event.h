#include <vector>
#include <functional>
#include <iostream>
#include <utility>

using namespace std;

class Event {
	public:
		void addListener(std::function<void()> c, int listener);
		void dispatchEvent(int listener);
	protected:
		// std::vector<std::reference_wrapper<std::function<void()>>> callbacks;
		
		vector < pair<function<void()>, int> >  callbacks;
};