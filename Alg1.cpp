#include<iostream>
#include"Alg1.h"
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
 //SA
  
double Alg1::prawdopodobienstwo(int roznica, double temperatura)
{
return exp(roznica/temperatura);
}
double Alg1::start()
 {

   for(int i =0;i< macierz.size();i++)
   {
      kolejnosc_przejscia.push_back(i);
   }
   licznik.start();
   double temperatura=70;
   double temperatura_start=50;
   double alfa = 0.95;
   double kryteriumStopuCzasu=20;
   double czas;
   int iteracje_epoki=macierz.size()*2;
   int swap1;
   int swap2;
   int koszt_obecny=INT_MAX;
   clock_t start;
   start = clock();
   losowe_rozwiazanie();

   while(true){
      while(temperatura>=0.1)
         {     kolejnosc_przejscia_nastepnego=kolejnosc_przejscia;
               int koszt_nastepny = oblicz_koszt();
               for(int i =0;i<iteracje_epoki;i++)
               {
                     swap1=rand()%macierz.size();
                     swap2=rand()%macierz.size();
                     while(swap1!=swap2)
                     {
                        swap1=rand()%macierz.size();
                     swap2=rand()%macierz.size();
                     }
                     swap(kolejnosc_przejscia_nastepnego[swap1],kolejnosc_przejscia_nastepnego[swap2]);

                  koszt_nastepny=oblicz_koszt();

                  int roznica=koszt_obecny-koszt_nastepny;
                  if(roznica>0)
                  {
                     koszt_obecny=koszt_nastepny;
                     rozwiazanie=kolejnosc_przejscia_nastepnego;
                  }

                  if(roznica<0 || (roznica<0 && prawdopodobienstwo(roznica,temperatura)>((double)rand()/ RAND_MAX)+1))
                  {
                     kolejnosc_przejscia=kolejnosc_przejscia_nastepnego;
                     break;
                  }
                  else{
                     swap(kolejnosc_przejscia_nastepnego[swap1],kolejnosc_przejscia_nastepnego[swap2]);
                  }
                  czas = (clock()-start)/(double)CLOCKS_PER_SEC;
                  if(czas>=kryteriumStopuCzasu)
                  {wynik();
                     cout<<"wynik "<<koszt_obecny<<endl;
                     return licznik.stop();
                  }
               }
               temperatura=temperatura*alfa;


         }
      temperatura=temperatura_start;
      losowe_rozwiazanie();
   }


   return licznik.stop();
}


 