#include "Utils_Database.h"

#include <string>
#include <fstream>
#include <filesystem>
#include <iostream>

using namespace std;
namespace fs = std::filesystem;

bool Utils_Database::file_Exists(const string& file_Name) {

    return fs::exists(file_Name);

}

void Utils_Database::create_File(const string& file_Name) {

    if (!file_Exists(file_Name)) {

        ofstream ofs(file_Name);

        if (!ofs.is_open()){

            throw runtime_error("Cannot create file: " + file_Name);

        }

        ofs.close();

    }

}
