#include"Orz.hpp"

Orz::Orz() {
    MasaperHa = 4;
    PretperTona = 1700;
    suprafata = 20;
}
float Orz::getPretperHa() {
    return PretperTona * MasaperHa;
}
float Orz::getSuprafata() {
    return suprafata;
}
void Orz::updateSuprafata(float newS) {
    newS = 20;
    suprafata = newS;
}
const char* Orz::getCultura() {
    return "Orz";
}
void Orz::bonusProductie(int bonus) {
    MasaperHa += MasaperHa * bonus / 100;
}
void Orz::Deflation(int penalty) {
    PretperTona -= PretperTona * penalty / 100;
}