#ifndef DATABASE_CPP
#define DATABASE_CPP

#include "Database.h"
#include <sstream>

template<typename T>
bool Database<T>::insert_One(const T& obj) {

    ofstream ofs(file_Name, ios::app);
    if (!ofs.is_open()) throw runtime_error("Cannot open file for writing.");
    ofs << obj.serialize() << endl;
    return true;

}

template<typename T>
T Database<T>::find_One(const string& field, const string& value) {
    ifstream ifs(file_Name);
    if (!ifs.is_open()) throw runtime_error("Cannot open file for reading.");

    string line;
    while (getline(ifs, line)) {
        T obj = T::deserialize(line);
        auto fields = obj.toMap();
        if (fields.find(field) != fields.end() && fields[field] == value) {
            return obj;
        }
    }

    return T(); // default object if not found
}

template<typename T>
bool Database<T>::update_One(const string& query, const T& new_obj) {

    ifstream ifs(file_Name);
    if (!ifs.is_open()) throw runtime_error("Cannot open file for reading.");

    vector<string> lines;
    string line;
    bool updated = false;

    while (getline(ifs, line)) {
        if (!updated && line.find(query) != string::npos) {
            lines.push_back(new_obj.serialize());
            updated = true;
        } else {
            lines.push_back(line);
        }
    }
    ifs.close();

    if (updated) {
        ofstream ofs(file_Name, ios::trunc);
        for (const auto& l : lines) ofs << l << endl;
    }
    return updated;
}

template<typename T>
bool Database<T>::delete_One(const string& query) {

    ifstream ifs(file_Name);
    if (!ifs.is_open()) throw runtime_error("Cannot open file for reading.");

    vector<string> lines;
    string line;
    bool deleted = false;

    while (getline(ifs, line)) {
        if (!deleted && line.find(query) != string::npos) {
            deleted = true; // skip line
        } else {
            lines.push_back(line);
        }
    }
    ifs.close();

    if (deleted) {
        ofstream ofs(file_Name, ios::trunc);
        for (const auto& l : lines) ofs << l << endl;
    }
    return deleted;
}

#endif // DATABASE_CPP
