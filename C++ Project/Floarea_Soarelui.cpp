#include"Floarea_Soarelui.hpp"

Floarea_Soarelui::Floarea_Soarelui(){
    MasaperHa = 2.5;
    PretperTona = 3200;
    suprafata = 0;
}
Floarea_Soarelui::Floarea_Soarelui(float percent){
    MasaperHa = 2.5;
    PretperTona = 3200;
    suprafata = percent;
}
float Floarea_Soarelui::getPretperHa(){
    return PretperTona * MasaperHa;
}
float Floarea_Soarelui::getSuprafata(){
    return suprafata;
}
void Floarea_Soarelui::updateSuprafata(float newS) {
    suprafata = newS;
}
const char* Floarea_Soarelui::getCultura() {
    return "Floarea Soarelui";
}
void Floarea_Soarelui::bonusProductie(int bonus) {
    MasaperHa += MasaperHa * bonus / 100;
}
void Floarea_Soarelui::Deflation(int penalty) {
    PretperTona -= PretperTona * penalty / 100;
}