#pragma once 
#include <iostream>
#include <vector>
#include <memory>
#include <fstream>

using namespace std;

class editFile{
private:
    string filename;
    string newfilename;
    string line;
    vector<string> lines;
public:
    editFile(string filename, string newfilename) : filename(filename), newfilename(newfilename) {}
    editFile() : filename("undefined"), newfilename("undefinedNew") {}
    ~editFile() {}
    void start();
    void readMyFile();
    void add_to_end();
    void make_new_file();
};
