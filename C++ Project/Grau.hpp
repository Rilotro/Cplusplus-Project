#include<iostream>
#include"Cultura.hpp"

using namespace std;

class Grau :public Cultura {
public:
    Grau();
    Grau(float);
    float getPretperHa();
    float getSuprafata();
    void updateSuprafata(float);
    const char* getCultura();
    void bonusProductie(int);
    void Deflation(int);
};