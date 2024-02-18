#include"Grau.hpp"

Grau::Grau(){
    MasaperHa = 3;
    PretperTona = 2000;
    suprafata = 0;
}
Grau::Grau(float percent){
    MasaperHa = 3;
    PretperTona = 2000;
    suprafata = percent;
}
float Grau::getPretperHa(){
    return PretperTona * MasaperHa;
}
float Grau::getSuprafata(){
    return suprafata;
}
void Grau::updateSuprafata(float newS) {
    suprafata = newS;
}
const char* Grau::getCultura() {
    return "Grau";
}
void Grau::bonusProductie(int bonus) {
    MasaperHa += MasaperHa * bonus/100;
}
void Grau::Deflation(int penalty) {
    PretperTona -= PretperTona * penalty/100;
}