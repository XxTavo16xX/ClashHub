
// * Author: Armando Peralta

#include "Utils_Menu_Handler.h"

// * General Dependencies

#include <iostream>
#include <string>

using namespace std;

// * Utils Required

#include "Utils_Input_Listener.h"
#include "Utils_Menu.h"


void Utils_Menu_Handler::handle_Welcome_Menu_Selection() {

    // * Getting user selection

    int menu_selection;

    menu_selection = Utils_Input_Listener::get_User_Input_Selection("Selecciona la opcion que deseas ejecutar: ");


    switch(menu_selection){

        case 0:{

            break;

        }

        case 1:{

            Utils_Menu::print_Login_Screen_Form();
            break;

        }

        case 2:{

            Utils_Menu::print_Register_Screen_Form();
            break;

        }

        default: {

            cout<<"Opcion invalida.";
            break;

        }

    }


}
