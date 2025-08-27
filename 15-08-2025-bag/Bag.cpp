#include <iostream>
#include "Bag.h"
using namespace std;

Bag::Bag(){
    count = 0;
}

bool Bag::full(){
    // if(count == max) return true;
    // else return false;
    return count == maximum;
}

void Bag::insert(int number){
    if(full()){
        cout << "Sem espaço! Bag cheia! Saindo..." << endl;
        abort();
    }
    count+=1;
    //count++;
    numbers[count] = number;
}

int Bag::size(){
    return count;
}

int Bag::occurrence(int number){
    int c = 0;
    for(int i = 1; i <= count; i++){
        if(numbers[i] == number) c++;
    }
    return c;
}

void Bag::remove(int number){
    //Exercício: implementar!!!
}