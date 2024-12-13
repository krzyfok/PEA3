#include<iostream>
#include"Menu.h"
#include"Alg1.h"
#include"Testowanie.h"
#include<fstream>
#include<string>
#include<vector>
using namespace std;

vector<int> Menu::rozmiary_macierzy;
int Menu::powtorzenia;
int Menu::liczba_instancji;
int Menu::progres;
int Menu::tryb;
string Menu::dane_wejsciowe;
string Menu::dane_wyjsciowe;

void Menu::wczytanie_konfiguracji()
{	//wczytywanie danych z pliku konfiguraycjnego
	string nazwa_pliku = "config.txt";
	ifstream plik(nazwa_pliku);

	if (plik.is_open()) {

		string nazwa;
		int dane;

		cout << "KONFIGURACJA: " << endl;
		plik >> nazwa;
		plik >> tryb;
		cout << nazwa << " " << tryb << endl;

		plik >> nazwa;
		plik >> dane_wejsciowe;
		cout << nazwa << " " << dane_wejsciowe << endl;

		plik >> nazwa;
		plik >> dane_wyjsciowe;
		cout << nazwa << " " << dane_wyjsciowe << endl;

		plik >> nazwa;
		plik >> progres;
		cout << nazwa << " " << progres << endl;


		plik >> nazwa;
		plik >> liczba_instancji;
		cout << nazwa << " " << liczba_instancji << endl;


		for (int i = 0; i < liczba_instancji; i++)
		{
			plik >> nazwa;
			plik >> dane;
			cout << nazwa << " " << dane << endl;
			rozmiary_macierzy.push_back(dane);
		}

		plik >> nazwa;
		plik >> powtorzenia;
		cout << nazwa << " " << powtorzenia << endl << endl << endl;

		plik.close();

	}
	else {
		cout << "BRAK PLIKU KONFIGURACYJNEGO\n";
		exit(0);
	}
}
void Menu::main_menu() {
	wczytanie_konfiguracji();

	if (tryb == 1)
	{
		
		Alg1 a1;
		
		AlgAbstr::wczytywanie(dane_wejsciowe);
		AlgAbstr::wyswietlanie();
		cout<<"SA: "<<a1.start()<<" milisekund ";
		//a1.wynik();
	
		
	}
	else
	{
		Testowanie t;
		t.test_start(rozmiary_macierzy, powtorzenia, progres, dane_wyjsciowe);
	}

	cout << "NACISNIJ DOWOLNY PRZYCISK BY ZAKONCZYC";
	getchar();

}

