#pragma once 
#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

struct BankAccounts{
    char number[8];
    char name[50];
    char address[50];
};

class Bank{
private:
    string fileName;
    BankAccounts account;
    vector<BankAccounts> accounts;
public:
    Bank() : fileName("undefined.bin"){}
    Bank(string file) : fileName(file) {}
    ~Bank() {}
    int to_find_card(string num); 
    bool is_in(string number);
    void start();
    void to_add();
    void to_change();
    void to_find();
    void read_all();
    bool number_is_valid(string nnumber);
    void to_delete();
};
