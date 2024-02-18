#ifndef CULTURA_HPP
#define CULTURA_HPP
#include<iostream>

using namespace std;

class Cultura {
protected:
    float MasaperHa, PretperTona, suprafata;
public:
    Cultura();
    Cultura(float);
    virtual float getPretperHa();
    virtual float getSuprafata();
    virtual void updateSuprafata(float);
    virtual const char* getCultura();
    virtual void bonusProductie(int);
    virtual void Deflation(int);
};
#endif