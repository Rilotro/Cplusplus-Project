#include<iostream>
#include"Cultura.hpp"

using namespace std;

class Floarea_Soarelui :public Cultura {
public:
    Floarea_Soarelui();
    Floarea_Soarelui(float);
    float getPretperHa();
    float getSuprafata();
    void updateSuprafata(float);
    const char* getCultura();
    void bonusProductie(int);
    void Deflation(int);
};