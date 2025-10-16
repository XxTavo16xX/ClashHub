
// * Author: Victor Ruiz

#ifndef EQUIPO_H
#define EQUIPO_H

// * General Dependencies

#include <string>
#include <vector>
using namespace std;

// * References Required

#include "Referencia_de_Miembro_de_Equipo.h"

class Equipo
{
    public:
        Equipo(string name, string creator_Gamertag);
        bool add_Member(Referencia_de_Miembro_de_Equipo* new_Member);
        void calculate_Team_Average_ELO();

    private:
        string id;
        string name;
        string createdBy;
        vector <Referencia_de_Miembro_de_Equipo*> members;
        int average_ELO;

};

#endif // EQUIPO_H
