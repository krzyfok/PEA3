#include<vector>
#include<String>
using namespace std;
class Menu {
public:
	void main_menu();
	void wczytanie_konfiguracji();

	//zmienne konfiguracyjne
	static vector<int> rozmiary_macierzy;
	static int powtorzenia, liczba_instancji, progres, tryb;
	static string dane_wejsciowe, dane_wyjsciowe;
};
