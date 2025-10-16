#ifndef DATABASE_H
#define DATABASE_H

// * General Dependencies

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Utils_Database.h"

using namespace std;

template <typename T>
class Database {

    public:

        static Database<T> connect_To_Database(const string& database_Name){

            string file_Name = database_Name + "_database.txt";
            Utils_Database::create_File(file_Name);
            return Database<T>(file_Name);

        }

        bool insert_One(const T& object);
        T find_One(const string& field, const string& value);
        bool update_One(const string& query, const T& new_obj);
        bool delete_One(const string& query);

    private:

        string file_Name;
        Database(const string& file_Name) : file_Name(file_Name) {}

};

#include "Database.tpp"

#endif // DATABASE_H
