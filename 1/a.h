#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <fstream>

using namespace std;

class vehicle{
protected:
    string color;
public:
    virtual ~vehicle() {}
    vehicle(string color):color(color){}
    vehicle() : color("undefined"){}
    virtual void start() = 0;
    void setColor(string c);
    string getColor();
};

class car: public vehicle{
private:
    string brand;
public:
    car() : vehicle(),  brand("undefined") {}
    car(string brand, string color) : vehicle(color), brand(brand) {}
    car(const car &c) : vehicle(c.color), brand(c.brand) {}
    ~car() override {
        cout << "\nМашина удалена";
    }
    void start() override;
    string getBrand();
};

class bicycle: public vehicle{
private:
    int wheels;
public:
    bicycle() : vehicle(), wheels(0) {}
    bicycle(int wheels, string color) : vehicle(color), wheels(wheels) {}
    bicycle(const bicycle &b) : vehicle(b.color), wheels(b.wheels) {}
    ~bicycle() override {
        cout << "\nВелосипед удален";
    }
    void start() override;
    int getWheels();
};

class storage{
private:
    vector<bicycle> bicycles;
    vector<car> cars;
public:
    storage() {}
    ~storage() {
        cout << "\nСклад удален";
    }
    void addBicycle(bicycle b);
    void addCar(car c);
    void removeBicycle(bicycle b);
    void removeCar(car c);
    void save(string filename); 
};
