
// * Author: Armando Peralta

// * General Dependencies

#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

// * Class Required

#include "Administrador.h"
#include "Usuario.h"
#include "Equipo.h"
#include "Torneo.h"
#include "Juego.h"

// * Utils Required

#include "Utils_Menu.h"
#include "Utils_Menu_Handler.h"
#include "Utils_Input_Listener.h"

int main() {

    // * Sets the program character classification to Spanish

    setlocale(LC_CTYPE, "spanish");

    // * Displaying Welcome Screen

    Utils_Menu::print_Welcome_Screen_Menu();

    // * Handling Welcome Screen User Selection

    Utils_Menu_Handler::handle_Welcome_Menu_Selection();

    return 0;

}
