#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct uczen
{
        string imie, nazwisko;
        int numer;
};

class klasa
{
    vector <struct uczen> spis;
       
public:
    void wprowadz();
    void wypisz();
    void zapiszDoPliku(const char *);
    void wczytajZPliku(const char *);                
};

void klasa::wczytajZPliku(const char *dane)
{
    ifstream plik2;
    plik2.open(dane);
    
     struct uczen wprowadzany;
    
    while(!plik2.eof())
        {
         plik2 >> wprowadzany.numer
            	>> wprowadzany.imie
            	>> wprowadzany.nazwisko;
            spis.push_back(wprowadzany);
}
    
    plik2.close();
}

void klasa::wypisz()
{
        for (vector<struct uczen>::iterator it = spis.begin(); it != spis.end(); ++it)
        {
        cout << it->numer << " "
        		<< it->imie << " "
        		<< it->nazwisko << "\n";
        }
}

void klasa::zapiszDoPliku(const char *dane2)
{
        ofstream plik;
        plik.open(dane2);
        for (vector<struct uczen>::iterator it = spis.begin(); it != spis.end(); ++it)
        {	
			plik << it->numer << " "
        		<< it->imie << " "
        		<< it->nazwisko << "\n";
        }
        plik.close();  
}

int main(int argc, char** argv) {
        klasa vec;
        vec.wczytajZPliku("dane.txt");
        vec.wypisz();
        vec.zapiszDoPliku("dane2.txt");
        return 0;
}
