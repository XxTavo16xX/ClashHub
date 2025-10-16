#ifndef USUARIO_H
#define USUARIO_H


// General Dependencies

#include <vector>
#include <map>

// * Class Required

#include "Referencia_de_Equipo.h"

class Usuario
{
    public:

        Usuario();
        Usuario(string gamertag, string email, string password);

        // static bool validate_User_Existance_By_Email();
        bool authenticate_Login_Crendentials(string user_Password);
        static bool update_User_Gamertag(string new_Gamertag);
        static bool update_User_ELO(int new_ELO);
        static bool add_User_Team_Reference(string Referencia_de_Equipo);

        string get_Email();

        // * Database Methods

        string serialize() const;
        static Usuario deserialize(const string& line);
        map<string,string> toMap() const {
            map<string,string> m;
            m["gamertag"] = gamertag;
            m["email"] = email;
            m["password"] = password;
            m["ELO"] = to_string(ELO);
            return m;
        }

    private:

        string gamertag;
        string email;
        string password;
        int ELO;
        vector<Referencia_de_Equipo*> teams;

};

#endif // USUARIO_H
