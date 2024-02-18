#include"Porumb.hpp"

Porumb::Porumb(){
    MasaperHa = 5;
    PretperTona = 1300;
    suprafata = 0;
}
Porumb::Porumb(float percent){
    MasaperHa = 5;
    PretperTona = 1300;
    suprafata = percent;
}
float Porumb::getPretperHa(){
    return PretperTona * MasaperHa;
}
float Porumb::getSuprafata(){
    return suprafata;
}
void Porumb::updateSuprafata(float newS) {
    suprafata = newS;
}
const char* Porumb::getCultura() {
    return "Porumb";
}
void Porumb::bonusProductie(int bonus) {
    MasaperHa += MasaperHa * bonus / 100;
}
void Porumb::Deflation(int penalty) {
    PretperTona -= PretperTona * penalty / 100;
}