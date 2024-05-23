#include "a.h"

int Bank::to_find_card(string num){
    for(int i = 0; i < accounts.size(); i++){
        if(accounts[i].number == num){
            return i;
        }
    }
    return 0;
}

void Bank::to_delete(){
    string num;
    cout << "\nВведите запись, которую хотите удалить: ";
    cin >> num;
    if (is_in(num)){
        accounts.erase(accounts.begin() + to_find_card(num));
        ofstream file(fileName, ios::binary);
            if (file.is_open()){
                for (auto& i : accounts){
                    file.write(reinterpret_cast<const char*>(&i), sizeof(i));
                }
            }
            file.close();
        }
    }


void Bank::to_change(){
    cout << "\nКакую карточку вы хотите изменить?" << endl;
    string num;
    cin >> num;
    int vibor;
    if (number_is_valid(num)){
        for (auto& i : accounts){
            if (i.number == num){
                cout << "Что вы хотите изменить? (1 - ФИО, 2 - Адрес, 3 - все): " << endl;
                cin >> vibor;
                if (vibor == 1){
                cout << "ФИО: ";
                cin >> i.name;
                }
                else if (vibor == 2){
                cout << "\nАдрес: ";
                cin >> i.address;
                }
                else{
                    cout << "ФИО: ";
                    cin >> i.name;
                    cout << "\nАдрес: ";
                    cin >> i.address;
                }
            }
        }
        ofstream file(fileName, ios::binary);
        if (file.is_open()){
            for (auto& i : accounts){
                file.write(reinterpret_cast<const char*>(&i), sizeof(i));
            }
        }
        file.close();
    }
    else cout << "Неверный номер карточки" << endl;
}

void Bank::to_find(){
    string num;
    cout << "\nВведите номер счета: ";
    cin >> num;
    if (number_is_valid(num)){
        for (auto& i : accounts){
            if (i.number == num){
                cout << "\nНомер: " << i.number << "\nФИО: " << i.name << "\nАдрес: " << i.address << endl;
                return;
            }
        }
        cout << "\nСчет не найден";
    }
    else{
        cout << "\nНомер счета должен состоять из 7 цифр, а также отсутствовать в списке существующих счетов.";
    }
}

void Bank::read_all(){
    cout << "-------------------------------------------------------";
    for(auto& i : accounts){
        cout << "\nНомер: " << i.number << "\nФИО: " << i.name << "\nАдрес: " << i.address << endl;
    }
    cout << "-------------------------------------------------------";
}

bool Bank::is_in(string number){
    for (auto& i : accounts){
        if (strncmp(i.number, number.c_str(), 7) == 0){
            return true;
        }
    }
    return false;
}

bool Bank::number_is_valid(string nnumber){
    bool ok = true;
    for (int i = 0; i < nnumber.length(); i++){
        if (!isdigit(nnumber[i])){
            ok = false;
            break;
        }
    }
    return (nnumber.length() == 7 && ok);
}

void Bank::start(){
  cout << "Введите имя существующего файла (без .bin): ";
  cin >> fileName;
  fileName += ".bin"; 
  cout << endl;
  cin.ignore();
  ifstream file(fileName, ios::binary);

  if(file.is_open()){
      while (file.read(reinterpret_cast<char*>(&account), sizeof(account))) {
          accounts.push_back(account);
      }
      file.close();
  }
}

void Bank::to_add(){
    bool ok = false;
    string accountNumber, FIO, address;
    while (not ok){
        ok = true;
        cout << "\nВведите номер счета: ";
        cin >> accountNumber;
        cin.ignore();
        if (!number_is_valid(accountNumber) || is_in(accountNumber)){
            cout << "\nНомер счета должен состоять из 7 цифр, а также отсутствовать в списке существующих счетов.";
            ok = false;
        }

    }
    cout << "\nВведите адрес: ";
    getline(cin, address);
    cout << "\nВведите ФИО: ";
    getline(cin, FIO); 
    strncpy(account.number, accountNumber.c_str(), 7);
    account.number[7] = '\0';
    strncpy(account.name, FIO.c_str(), 49);
    account.name[49] = '\0';
    strncpy(account.address, address.c_str(), 49);
    account.address[49] = '\0';

    ofstream file(fileName, ios::binary | ios::app);
    if (file.is_open()){
        file.write(reinterpret_cast<const char*>(&account), sizeof(account));
        accounts.push_back(account);
    }
    file.close();
}
