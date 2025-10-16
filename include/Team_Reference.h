#ifndef TEAM_REFERENCE_H
#define TEAM_REFERENCE_H

// * General Dependencies

#include <iostream>
#include <string>

using namespace std;

class Team_Reference
{
    public:

        Team_Reference();

    private:

        string id;
        string name;
        int average_ELO;

};

#endif // TEAM_REFERENCE_H
