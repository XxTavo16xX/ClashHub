
// * Author: Armando Peralta

#include "Utils_Input_Listener.h"

// * General Dependencies

#include <iostream>
#include <string>

using namespace std;


int Utils_Input_Listener::get_User_Input_Selection() {

    int temporal_string;

    cin >> temporal_string;
    cin.ignore();

    return temporal_string;

}

string Utils_Input_Listener::get_User_Text_Input() {

    string temporal_string;

    getline(cin, temporal_string);

    return temporal_string;

}
