#include <random>
#include <time.h>
#include <iostream>

#include "../header/helperFunctions.hpp"

using std::cout;
using std::endl;

void helperPrintLargerSpacer() { // prints 25 new lines
    for (int i = 0; i < 25; i++) {
        cout << endl;
    }
}

void helperWait(double seconds) { // delays program by n seconds by being stuck in a while loop
    time_t startTime;
    time(&startTime);
    time_t currentTime;
    while (true) {
        time(&currentTime);
        if (difftime(currentTime, startTime) >= seconds) {
            break;
        }
    }
}

int helperGenerateRandomInteger(int start, int end) {
    srand(time(NULL));
    return ((rand() % (end - start)) + start);
}