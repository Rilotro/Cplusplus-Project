#include<iostream>
#include"Cultura.hpp"

using namespace std;

class Porumb :public Cultura {
public:
    Porumb();
    Porumb(float);
    float getPretperHa();
    float getSuprafata();
    void updateSuprafata(float);
    const char* getCultura();
    void bonusProductie(int);
    void Deflation(int);
};