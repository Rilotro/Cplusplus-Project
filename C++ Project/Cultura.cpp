#include"Cultura.hpp"

Cultura::Cultura(){
    MasaperHa = 0;
    PretperTona = 0;
    suprafata = 0;
}
Cultura::Cultura(float percent){
    MasaperHa = 0;
    PretperTona = 0;
    suprafata = percent;
}
float Cultura::getPretperHa() {
    return 0;
}
float Cultura::getSuprafata(){
    return suprafata;
}
void Cultura::updateSuprafata(float newS) {
    suprafata = newS;
}
const char* Cultura::getCultura() {
    return "N/C";
}
void Cultura::bonusProductie(int bonus) {
    MasaperHa += MasaperHa * bonus / 100;
}
void Cultura::Deflation(int penalty) {
    PretperTona -= PretperTona * penalty / 100;
}
