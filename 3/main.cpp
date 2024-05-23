#include "a.h"

int main(){
    Bank bank;
    bank.start();
    bank.read_all();
    bank.to_find();
    bank.to_change();
    bank.read_all();
    bank.to_delete();
    bank.read_all();
    return 0;
    
}
