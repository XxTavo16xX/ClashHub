
// * Author: Armando Peralta

#ifndef UTILS_DATABASE_H
#define UTILS_DATABASE_H

// * General Dependencies

#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

class Utils_Database{

    public:

        // * Method to validate the existance of database (txt file)

        static bool file_Exists(const string& file_Name);

        // * Method to create the database (txt file) if doesn't exists

        static void create_File(const string& file_Name);

};

#endif // UTILS_DATABASE_H
