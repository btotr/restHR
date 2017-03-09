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
		vector < pair<function<void()>, int> >  callbacks;
};