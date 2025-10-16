
// * Author: Armando Peralta

#ifndef UTILS_INPUT_LISTENER_H
#define UTILS_INPUT_LISTENER_H

#include <iostream>
#include <string>

using namespace std;

class Utils_Input_Listener {
    public:

        static int get_User_Input_Selection(string input_label);
        static string get_User_Text_Input(string input_label);

};

#endif // UTILS_INPUT_LISTENER_H
