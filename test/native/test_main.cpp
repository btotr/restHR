#include <unity.h>
#include "HeartRateModel.h"

#ifdef UNIT_TEST
bool callbackCalled = false;

void test_callback_is_not_called(void) {
    TEST_ASSERT_FALSE(callbackCalled);
}

void test_callback_is_called(void) {
    TEST_ASSERT_TRUE(callbackCalled);
}

void callback() {
	callbackCalled = true;
}

int main()
{
	class HeartRateModel hrModel;
	
	UNITY_BEGIN();
	hrModel.on(HeartRateModel::heartRateChange, callback);
	RUN_TEST(test_callback_is_not_called);
	hrModel.emit(HeartRateModel::heartRateChange);
	RUN_TEST(test_callback_is_called);
	UNITY_END();
}

#endif