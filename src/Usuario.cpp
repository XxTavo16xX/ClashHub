#include "Usuario.h"

// * General Dependencies

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

// * Class Required

#include "Referencia_de_Equipo.h"

// * Database Required

// #include "Database.h"

Usuario::Usuario() {

    this->gamertag = "Undefined";
    this->email = "Undefined";
    this->password = "Undefined";
    this->ELO = 0;
    this->teams = {};

}

Usuario::Usuario(string gamertag, string email, string password) {

    this->gamertag = gamertag;
    this->email = email;
    this->password = password;
    this->ELO = 0;
    this->teams = {};

}

bool Usuario::authenticate_Login_Crendentials(string user_Password) {

    return this->password == user_Password;

}

string Usuario::get_Email() {

    return this->email;

}

string Usuario::serialize() const {

    stringstream ss;
    ss << gamertag << "|" << email << "|" << password << "|" << ELO << "|";

    for (size_t i = 0; i < teams.size(); ++i) {

        ss << teams[i]->id;
        if (i != teams.size() - 1) ss << ",";

    }

    return ss.str();

}


Usuario Usuario::deserialize(const string& line) {

    stringstream ss(line);
    string token;
    vector<string> parts;

    // Split by '|'
    while (getline(ss, token, '|')) {
        parts.push_back(token);
    }

    // Create base user
    Usuario user(
        parts.size() > 0 ? parts[0] : "",
        parts.size() > 1 ? parts[1] : "",
        parts.size() > 2 ? parts[2] : ""
    );

    if (parts.size() > 3) {
        user.ELO = stoi(parts[3]);
    }

    // Deserialize teams if present
    if (parts.size() > 4) {
        stringstream teamSS(parts[4]);
        string teamId;
        while (getline(teamSS, teamId, ',')) {
            // Create a new Referencia_de_Equipo with the ID
            // Note: you can later link to actual Team objects
            Referencia_de_Equipo* teamRef = new Referencia_de_Equipo(teamId);
            user.teams.push_back(teamRef);
        }
    }

    return user;

}

