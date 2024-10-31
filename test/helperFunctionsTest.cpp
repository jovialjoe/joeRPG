#include <gtest/gtest.h>
#include <time.h>

#include "../header/helperFunctions.hpp"

TEST(HelperFunctionsTestSuite, RandomInteger) {
    for(int i = 0; i < 3; i++) {
        ASSERT_TRUE(0 <= helperGenerateRandomInteger(0, 10) <= 10);
        helperWait(1);
    }
}

TEST(HelperFunctionsTestSuite, Wait) {
    double testTime = 1.0;
    
    time_t startTime;
    time(&startTime);
    time_t currentTime;

    helperWait(testTime);
    time(&currentTime);

    ASSERT_DOUBLE_EQ(difftime(currentTime, startTime), testTime);
}