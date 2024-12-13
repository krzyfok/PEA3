#ifndef ALGABSTR_H
#define ALGABSTR_H

#include <vector>
#include <string>
#include "node.h"
#include<Algorithm>
#include<queue>
#include"LicznikCzasu.h"
class AlgAbstr {
public:



    virtual double start()=0;
    static void wynik();
    static node best_node; // Najlepszy węzeł
    static void wczytywanie(string nazwa);
    static void wyswietlanie();
    static void generacja(int n);
    static void generacja_sym(int n);
    static int oblicz_koszt();
    static void losowe_rozwiazanie();
    static vector<vector<int>> macierz;
   static vector<int> kolejnosc_przejscia;
    static vector<int> kolejnosc_przejscia_nastepnego;
    static vector<int> rozwiazanie;
    int* minima; // Dynamiczna tablica minimalnych wartości
};

#endif // ALGABSTR_H
