#include <iostream>
#include "a.h"
int main() {
  car first;
  car second;
  bicycle third;
  bicycle fourth;
  storage storage;
  second.start();
  fourth.start();
  storage.addCar(second);
  storage.addBicycle(fourth);
  storage.addCar(first);
  storage.addBicycle(third);
  storage.addCar(second); //повторно вносим второй автомобиль, чтобы потом его удалить
  storage.removeCar(second); // удаляем
  storage.addBicycle(fourth); // повторно вносим второй велочипед, чтобы потом его удалить
  storage.removeBicycle(fourth); // удаляем
  storage.save("memory.txt"); // сохраняем
}
