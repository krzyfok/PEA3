#include"AlgAbstr.h"
#include<iostream>
#include<vector>
#include<fstream>
#include<Algorithm>
#include<random>
#include <algorithm>
using namespace std;
vector<vector<int>> AlgAbstr::macierz;
 
node AlgAbstr::best_node;  
vector<int> AlgAbstr::kolejnosc_przejscia;
vector<int> AlgAbstr::kolejnosc_przejscia_nastepnego;
vector<int> AlgAbstr :: rozwiazanie;
LicznikCzasu licznik;
void AlgAbstr:: wczytywanie(string nazwa)
{
macierz.clear();
	
	int rozmiar;
	string wynik_oczekiwany;

	ifstream plik(nazwa);  

	if (plik.is_open()) {
		plik >> rozmiar;  

		macierz.resize(rozmiar, vector<int>(rozmiar));

		for (int i = 0; i < rozmiar; i++) {
			for (int j = 0; j < rozmiar; j++) {
				plik >> macierz[i][j]; 
			}
		}
		plik >> wynik_oczekiwany;
		cout << wynik_oczekiwany << endl;
		plik.close();  
	}
	else {
		cout << "BRAK PLIKU,"<<" NACISNIJ DOWOLNY PRZYCISK BY ZAKONCZYC";
		getchar();
		exit(0);
	}
}

void AlgAbstr::wyswietlanie()
{
    for (int i = 0; i < macierz.size(); i++)
	{
		for (int k = 0; k < macierz[i].size(); k++)
		{
			cout << macierz[i][k] << " ";
		}
		cout << endl;
	}
}
void AlgAbstr::generacja_sym(int n)
{

	int rozmiar = n;

	//deklaracja rozmiary wektora
	macierz.resize(rozmiar);

	for (int i = 0; i < rozmiar; i++)
	{
		macierz[i].resize(rozmiar);
	}
	//genracja macierzy symetrycznej 
	for (int i = 0; i < rozmiar; i++)
	{

		for (int k =i+1 ; k < rozmiar; k++)
		{
			int wartosc_losowa = rand();
			macierz[i][k] = wartosc_losowa;
			macierz[k][i] = wartosc_losowa;
		}
		macierz[i][i] = -1;
	}
}
void AlgAbstr::generacja(int n)
{
	int rozmiar=n;
	//deklaracja rozmiary wektora
	macierz.resize(rozmiar);
	
	for (int i = 0; i < rozmiar; i++)
	{
		macierz[i].resize(rozmiar);
	}
	//genracja macierzy asymetrycznej 
	for (int i = 0; i < rozmiar; i++)
	{
		
		for (int k = 0; k < rozmiar; k++)
		{
			if (k != i)
			{
				do
				{
					macierz[i][k] = rand();

				} while (macierz[i][k]==macierz[k][i]);
			}
			else
			{
				macierz[i][k] = -1;
			}
		}
	}
}


void AlgAbstr::wynik()
{
	cout << "Koszt trasy : ";

cout<<"  trasa: ";
   for(int i=0;i<kolejnosc_przejscia.size();i++)
   {
    cout<<kolejnosc_przejscia[i]<<" ";
   }
}

int AlgAbstr::oblicz_koszt()
{
	int koszt=0;
	
	for(int i=0;i<kolejnosc_przejscia.size()-1;i++)
	{
			koszt+=macierz[kolejnosc_przejscia[i]][kolejnosc_przejscia[i+1]];
	}
	koszt+=macierz[kolejnosc_przejscia.back()][kolejnosc_przejscia[0]];

	return koszt;
}

void AlgAbstr :: losowe_rozwiazanie()
{
	random_device rd;
	mt19937 gen(rd());
		
	shuffle(kolejnosc_przejscia.begin(),kolejnosc_przejscia.end(),rd);

}

