#include "Bag.h"
#include  <iostream>
using namespace std;

int main(){
    Bag b1;
    b1.insert(15);
    b1.insert(3);
    b1.insert(4);
    b1.insert(7);
    b1.insert(15);

    cout << "A quantidade total de elementos atualmente na bag eh: "
    << b1.size() <<endl;

    cout << "A quantidade atual de ocorrencias do numero 15 na bag eh: "
    << b1.occurrence(15) <<endl;

    cout << "A quantidade atual de ocorrencias do numero 9 na bag eh: "
    << b1.occurrence(9) <<endl;
    
    return 0;
}