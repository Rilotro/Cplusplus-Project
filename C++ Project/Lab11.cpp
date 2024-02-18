// Lab11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include"Cultura.cpp"
#include"Grau.cpp"
#include"Porumb.cpp"
#include"Floarea_Soarelui.cpp"
#include"Orz.cpp"

using namespace std;

void sort(Cultura** v, int n) {
    int i, j;
    Cultura* aux = new Cultura;
    for (i = 0; i < n-1; i++) {
        for (j = i; j < n; j++) {
            if (v[i]->getPretperHa() < v[j]->getPretperHa()) {//sorteaza descrescator culturiile dupa densitatea pretului per hectar
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
}

//Venit pe Doi Ani
double VDA(Cultura** v, int n, int sTotal, float upperBound, float lowerBound, int nrAni) {
    int i, j;//ambele or sa contina suprafata exprimata in procente
    float sRamasa, sAux;
    double S = 0;
    sort(v, 3);
    for (j = 0; j < nrAni; j++) {
        sRamasa = 100;
        for (i = 0; i < n; i++) {
            sAux = sRamasa;
            sAux -= lowerBound * (n - i - 1);
            if (sAux > 100 - v[i]->getSuprafata()) {//verifica conditia 'cultura nu se poate planta pe acelasi teren ca anul trecut'
                sRamasa -= 100 - v[i]->getSuprafata();
                v[i]->updateSuprafata(100 - v[i]->getSuprafata());
                S += static_cast<double>(sTotal) * (v[i]->getSuprafata() / 100) * v[i]->getPretperHa();
                cout << v[i]->getCultura() << ": " << v[i]->getPretperHa() << " lei/Ha Anul " << j + 1 << endl;
            }
            else if (sAux > upperBound) {
                sRamasa -= upperBound;
                v[i]->updateSuprafata(upperBound);
                S += static_cast<double>(sTotal) * (v[i]->getSuprafata() / 100) * v[i]->getPretperHa();
                cout << v[i]->getCultura() << ": " << v[i]->getPretperHa() << " lei/Ha Anul " << j + 1 << endl;
            }
            else {
                sRamasa -= sAux;
                v[i]->updateSuprafata(sAux);
                S += static_cast<double>(sTotal) * (v[i]->getSuprafata() / 100) * v[i]->getPretperHa();
                cout << v[i]->getCultura() << ": " << v[i]->getPretperHa() << " lei/Ha Anul " << j + 1 << endl;
            }
        }
    }
    return S;

}

//Venit pe Doi Ani cu Orz
double VDA_O(Cultura** v, int n, int sTotal, float upperBound, float lowerBound, int nrAni) {
    int i, j;//ambele or sa contina suprafata exprimata in procente
    float sRamasa, sAux;
    double S = 0;
    bool end = false;
    Cultura* aux;
    sort(v, 3);
    //pune Orzul primul
    for (i = 0; end == false; i++) {
        if (strcmp(v[i]->getCultura(), "Orz") == 0) {
            end = true;
            for (j = i; j > 0; j--) {
                aux = v[j];
                v[j] = v[j-1];
                v[j-1] = aux;
            }
        }
    }
    for (j = 0; j < nrAni; j++) {
        sRamasa = 100;
        sRamasa -= v[0]->getSuprafata();
        S += static_cast<double>(sTotal) * (v[0]->getSuprafata() / 100) * v[0]->getPretperHa();
        cout << v[0]->getCultura() << ": " << v[0]->getPretperHa() << " lei/Ha Anul " << j+1 << endl;
        for (i = 1; i < n; i++) {
            sAux = sRamasa;
            sAux -= lowerBound * (n - i - 1);
            if (sAux > 100 - v[i]->getSuprafata()) {//verifica conditia 'cultura nu se poate planta pe acelasi teren ca anul trecut'
                sRamasa -= 100 - v[i]->getSuprafata();
                v[i]->updateSuprafata(100 - v[i]->getSuprafata());
                S += static_cast<double>(sTotal) * (v[i]->getSuprafata() / 100) * v[i]->getPretperHa();
                cout << v[i]->getCultura() << ": " << v[i]->getPretperHa() << " lei/Ha Anul " << j + 1 << endl;
            }
            else if (sAux > upperBound) {
                sRamasa -= upperBound;
                v[i]->updateSuprafata(upperBound);
                S += static_cast<double>(sTotal) * (v[i]->getSuprafata() / 100) * v[i]->getPretperHa();
                cout << v[i]->getCultura() << ": " << v[i]->getPretperHa() << " lei/Ha Anul " << j + 1 << endl;
            }
            else {
                sRamasa -= sAux;
                v[i]->updateSuprafata(sAux);
                S += static_cast<double>(sTotal) * (v[i]->getSuprafata() / 100) * v[i]->getPretperHa();
                cout << v[i]->getCultura() << ": " << v[i]->getPretperHa() << " lei/Ha Anul " << j + 1 << endl;
            }
        }
    }
    return S;

}



int main()
{
    int i, sTotal = 1000;
    Cultura** v = new Cultura*[3];
    v[0] = new Grau(40);
    v[1] = new Porumb(40);
    v[2] = new Floarea_Soarelui(20);
    double S = 0;
    for (i = 0; i < 3; i++) {
        S += static_cast<double>(sTotal) * (v[i]->getSuprafata()/100) * v[i]->getPretperHa();
    }
    cout << "venitul fermierului pe anul in care a pus 40% Grau, 40% Porumb si 20% Floarea Soarelui este de " << S << " de lei" << endl;//scuzati notatia stiintifica

    for (i = 0; i < 3; i++) {
        v[i]->updateSuprafata(0);
    }
    cout << "venitul optim al fermierului pe 2 ani ar fi de " << VDA(v, 3, sTotal, 60, 10, 2) << " lei" << endl;

    delete[] v;

    v = new Cultura*[4];

    v[0] = new Grau;
    v[1] = new Porumb;
    v[2] = new Floarea_Soarelui;
    v[3] = new Orz;
    cout<<"venitul optim al fermierului pe 2 ani dupa ce a adaugat orz ar fi de " << VDA_O(v, 4, sTotal, 60, 10, 2) << " lei" << endl;

    //fermierul intra in asociatia de fermieri
    for (i = 0; i < 4; i++) {
        v[i]->updateSuprafata(0);
        v[i]->bonusProductie(30);
    }
    //cu productia sporita decat venitul se schimba, toate culturile sunt afectate la fel, deci ordinea lor de prioritate nu se schimba
    cout << "venitul optim al fermierului pe 2 ani dupa ce s-a alturat asociatiei de fermieri ar fi de " << VDA_O(v, 4, sTotal, 60, 10, 2) << " lei" << endl;

    for (i = 0; i < 4; i++) {
        v[i]->updateSuprafata(0);
        v[i]->Deflation(40);
    }
    //la fel ca in exercitiul anterior, cum toate preturile, astfel si culturile, sunt afectate la fel, ordinea de prioritate a culturiilor nu se schimba, decat pretul
    cout << "venitul optim al fermierului pe 2 ani dupa ce au cazut preturile ar fi de " << VDA_O(v, 4, sTotal, 60, 10, 2) << " lei" << endl;
}
