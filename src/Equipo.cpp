
#include "Equipo.h"

// * General Dependencies

#include <vector>

// * Class Required

#include "Referencia_de_Miembro_de_Equipo.h"

// * Utils Required

#include "Utils_Random.h"

Equipo::Equipo(string name, string creator_Gamertag) {


    this->id = Utils_Random::generate_UID(16);
    this->name = name;
    this->createdBy = creator_Gamertag;

    this->members = { new Referencia_de_Miembro_de_Equipo(creator_Gamertag, "owner") };

    this->average_ELO = 0;

}
