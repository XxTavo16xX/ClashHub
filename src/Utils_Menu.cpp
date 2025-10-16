
// * Author: Armando Peralta

#include "Utils_Menu.h"

// * Dependencies Required

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

// * Utils Required

#include "Utils_Input_Listener.h"

void Utils_Menu::clear_Screen() {

    system("cls");

}


void Utils_Menu::print_Welcome_Screen_Menu() {

    Utils_Menu::clear_Screen();

    cout<<"Bienvenido a ClashHub"<<endl<<"Donde los verdaderos gamers compiten."<<endl<<endl<<"0) Salir"<<endl<<"1) Iniciar sesión"<<endl<<"2) Crear cuenta"<<endl<<endl<<endl;

}

void Utils_Menu::print_Login_Screen_Form() {

    Utils_Menu::clear_Screen();

    string user_email;
    string user_password;

    cout<<"Inicia Sesión"<<endl<<endl;

    cout<<"Correo Electrónico: ";
    user_email = Utils_Input_Listener::get_User_Text_Input();

    cout<<"Contraseña: ";
    user_password = Utils_Input_Listener::get_User_Text_Input();

    cout<<user_email;
    cout<<user_password;

}

void Utils_Menu::print_Register_Screen_Form() {

    Utils_Menu::clear_Screen();

    string user_gamertag;
    string user_email;
    string user_password;

    cout<<"Crear cuenta"<<endl<<endl;

    cout<<"Gamertag: ";
    user_gamertag = Utils_Input_Listener::get_User_Text_Input();

    cout<<"Correo Electrónico: ";
    user_email = Utils_Input_Listener::get_User_Text_Input();

    cout<<"Contraseña: ";
    user_password = Utils_Input_Listener::get_User_Text_Input();

    cout<<user_gamertag;
    cout<<user_email;
    cout<<user_password;

}
