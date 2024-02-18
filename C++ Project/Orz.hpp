#include<iostream>
#include"Cultura.hpp"

using namespace std;

class Orz :public Cultura {
public:
    Orz();
    float getPretperHa();
    float getSuprafata();
    void updateSuprafata(float);
    const char* getCultura();
    void bonusProductie(int);
    void Deflation(int);
};