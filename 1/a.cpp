#include "a.h"

void vehicle::setColor(string c){
    color = c;
}

string vehicle::getColor(){
    return color;
}

void car::start(){
    cout << "Введите цвет: ";
    cin >> color;
    cout << "Введите марку: ";
    cin >> brand;
}

void bicycle::start(){
    cout << "Введите цвет: ";
    cin >> color;
    cout << "Введите количество колес: ";
    cin >> wheels;
}

string car::getBrand(){
    return brand;
}

int bicycle::getWheels(){
    return wheels;
}

void storage::addBicycle(bicycle b){
    bicycles.push_back(b);
}

void storage::addCar(car c){
    cars.push_back(c);
}

void storage::removeBicycle(bicycle b){
    int i = 0;
    while(i < bicycles.size()){
        if(bicycles[i].getColor() == b.getColor() && bicycles[i].getWheels() == b.getWheels()){
            bicycles.erase(bicycles.begin() + i);
            break;
        }
        i++;
    }
}

void storage::removeCar(car c){
    int i = 0;
    while(i < cars.size()){
        if(cars[i].getColor() == c.getColor() && cars[i].getBrand() == c.getBrand()){
            cars.erase(cars.begin() + i);
            break;
        }
        i++;
    } 
}

void storage::save(string filename){
    ofstream file(filename);
    if(file.is_open()){
        file << "Велосипеды:\n";
        for(int i = 0; i < bicycles.size(); i++){
            file << i + 1 << " Велосипед: " << bicycles[i].getColor() << " " << bicycles[i].getWheels() << endl;
        }
        file << "Автомобили:\n";
        for(int i = 0; i < cars.size(); i++){
            file << i + 1 << " Автомобиль: " << cars[i].getColor() << " " << cars[i].getBrand() << endl;
        }
        file.close();
    }
    else{
        cout << "Ошибка открытия файла";
    }
}
