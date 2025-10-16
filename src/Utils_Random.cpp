
// * Author: Armando Peralta

#include "Utils_Random.h"

// * General Dependencies

#include <string>
#include <random>
#include <ctime>

string Utils_Random::generate_UID(int length) {

    const string chars = "0123456789" "ABCDEFGHIJKLMNOPQRSTUVWXYZ" "abcdefghijklmnopqrstuvwxyz";

    string uid;
    uid.reserve(length);

    // Random engine

    static mt19937 rng(static_cast<unsigned int>(time(nullptr)));
    uniform_int_distribution<int> dist(0, chars.size() - 1);

    for (int i = 0; i < length; ++i) {
        uid += chars[dist(rng)];
    }

    return uid;

}
