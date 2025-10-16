
// * Author: Armando Peralta

#include "Utils_Menu.h"

// * Dependencies Required

#include <cstdlib>
#include <iostream>
#include <string>
#include <thread>
#include <chrono>

using namespace std;

// * Utils Required

#include "Utils_Input_Listener.h"

// * Class Required

#include "Usuario.h"

// * Database Required

#include "Database.h"

void Utils_Menu::clear_Screen() {

    system("cls");

}


void Utils_Menu::print_Welcome_Screen_Menu() {

    Utils_Menu::clear_Screen();

    cout<<"Bienvenido a ClashHub"<<endl<<"Donde los verdaderos gamers compiten."<<endl<<endl<<"0) Salir"<<endl<<"1) Iniciar sesión"<<endl<<"2) Crear cuenta"<<endl<<endl;

}

void Utils_Menu::print_Login_Screen_Form() {

    Utils_Menu::clear_Screen();

    // * Connecting to Database

    auto db = Database<Usuario>::connect_To_Database("usuarios");

    cout<<"Inicia Sesión"<<endl<<endl;

    // * Requesting User Input

    string user_email = Utils_Input_Listener::get_User_Text_Input("Correo Electrónico: ");

    // * Searching User Account at db

    Usuario search_result = db.find_One("email", user_email);

    if (search_result.get_Email() == "Undefined") {

        cout<<"No existe ningun usuario con este correo electronico vinculado a su cuenta.";
        return;

    }

    // * Requesting User Account Password at db

    string user_password = Utils_Input_Listener::get_User_Text_Input("Contraseña: ");

    // * Validating User Account Password

    bool validation_Result = search_result.authenticate_Login_Crendentials(user_password);

    if (validation_Result == true) {

        cout<<"Sesion iniciada exitosamente. Redirigiendo al menu principal...";
        std::this_thread::sleep_for(std::chrono::seconds(2));

        Utils_Menu::print_Login_Screen_Form();

    }else{

        cout<<"Contraseña invalida.";

    }

}

void Utils_Menu::print_Register_Screen_Form() {

    Utils_Menu::clear_Screen();

    cout<<"Crear cuenta"<<endl<<endl;

    // * Requesting User Account Gamertag

    string user_gamertag = Utils_Input_Listener::get_User_Text_Input("Gamertag: ");

    // * Requesting User Account Email

    string user_email = Utils_Input_Listener::get_User_Text_Input("Correo Electrónico: ");

    // * Requesting User Account Password

    string user_password = Utils_Input_Listener::get_User_Text_Input("Contraseña: ");

    // * Creating User Account

    Usuario new_User(user_gamertag, user_email, user_password);

    // * Connecting to Database

    auto db = Database<Usuario>::connect_To_Database("usuarios");

    // * Saving account into database

    int insert_Result = db.insert_One(new_User);

    // * Validating database operation results

    if (insert_Result == 1) {

        cout<<"Cuenta creada exitosamente. Redirigiendo al inicio de sesión...";

        std::this_thread::sleep_for(std::chrono::seconds(2));

        Utils_Menu::print_Login_Screen_Form();

    }else{

        cout<<"Error al crear la cuenta";

    }

}
