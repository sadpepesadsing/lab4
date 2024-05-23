#include "a.h"

void editFile::start(){
    cout << "Введите имя существующего файла (без .txt): ";
    cin >> filename;
    cout << "\nВведите имя нового файла (без .txt): ";
    cin >> newfilename;
    cout << endl;
    cin.ignore();
}

void editFile::readMyFile(){
    ifstream MyFile(filename + ".txt");
    if (MyFile.is_open()){
        while (getline(MyFile, line)) {
            cout << line << endl;
        }
    }
    else{
        cout << "Не получилось открыть файл" << endl;
    }
}

void editFile::add_to_end(){
    ofstream MyFile(filename + ".txt", std::ios_base::app);
    if (MyFile.is_open()){
        cout << "Введите строку, которую хотите добавить в конец файла: ";
        getline(cin, line);
        cout << endl;
        MyFile << line;
    }
    else cout << "Не получилось открыть файл" << endl;
}


void editFile::make_new_file(){
    ifstream MyFile(filename + ".txt");
    ofstream NewFile(newfilename + ".txt");
    if (MyFile.is_open()){
        cout << "Введите строчку, которую хотите добавить в начало нового файла: ";
        getline(cin, line);
        NewFile << line + "\n";
        cout << endl;
        while (getline(MyFile, line)) {
            NewFile << line << endl;
        }
    }
    else cout << "Не получилось открыть файл" << endl;
    
}
