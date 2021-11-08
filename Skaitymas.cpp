#include <iostream> // ivedamos bibliotekos
#include <fstream> // ivedamos bibliotekos
#include <cmath> // ivedamos bibliotekos
#include <iomanip> // ivedamos bibliotekos

const char duomenys[]="duomenys.txt"; // duomenu ivedimo failas
const char rezultatai[]="rezultatai.txt"; // duomenu isvedimo failas

using namespace std;

void nuskaityti(int & n, int p[], int a[], int b[]); // sukuriama duomenu nuskaitymo funkcija
int skaiciuotidienas(int puslapiai, int perskaitytipuslapiai, int puslapiupokytis); // sukuriama dienu skaiciavimo funkcija
void isvesti(int n, int dienosknygoms[]); // sukuriama isvedimo funkcija

int main()
{
    int n,knyguskaicius,puslapiai,perskaitytipuslapiai,puslapiupokytis,diena; // ivedami kintamieji - knygu skaiciaus, puslapiu, perskaitytu puslapiu ir per kita diena daugiau perskaitomu puslapiu kintamieji, dienu skaiciaus kintamasis
    int p[10]; // puslapiu skaiciaus masyvas
    int a[10]; // perskaitomu puslapiu skaiciaus masyvas
    int b[10]; // per kita diena daugiau perskaitomu puslapiu skaiciaus masyvas
    int dienosknygoms[10]; // dienu masyvas duomenu isvedimui
    nuskaityti(n, p, a, b); // duomenu ivedimo funkcija
    for(int i=0; i<n; i++)
    {
    puslapiai=p[i]; // is masyvo priskiriamas konkretus puslapiu skaicius
    perskaitytipuslapiai=a[i]; // is masyvo priskiriamas perskaitomu puslapiu skaicius
    puslapiupokytis=b[i]; // is masyvo priskiriamas per kita diena daugiau perskaitomu puslapiu skaicius
    diena=skaiciuotidienas(puslapiai,perskaitytipuslapiai,puslapiupokytis); // funkcija, apskaiciuojanti, kiek dienu prireiks knygai perskaityti
    dienosknygoms[i]=diena; // apskaiciuotas dienu skaicius ivedamas i masyva, skirta duomenu isvedimui
    }
    isvesti(n, dienosknygoms); // duomenu isvedimo funkcija
    return 0;
}

void nuskaityti(int & n, int p[], int a[], int b[]) // duomenu ivedimo funkcija
{
    ifstream fd(duomenys); // duomenu ivedimas
    fd>>n; // nuskaitomas knygu skaicius
    for(int i=0; i<n; i++)
    {
        fd>>p[i]; // nuskaitomi visu knygu puslapiu skaiciai i masyva
        fd>>a[i]; // nuskaitomi visu knygu perskaitomu puslapiu skaiciai i masyva
        fd>>b[i]; // nuskaitomi visu knygu per kita diena daugiau perskaitomu puslapiu skaiciai i masyva
    }
    fd.close(); // uzdaromas duomenu failas
}

int skaiciuotidienas(int puslapiai, int perskaitytipuslapiai, int puslapiupokytis) // funkcija, kuria skaiciuojamas dienu kiekis
{
    int dienos=0; // priskiriama reiksme dienoms apskaiciuoti
    while(puslapiai>0) // naudojant while funkcija skaiciuojamas dienu skaicius
    {
        puslapiai=puslapiai-perskaitytipuslapiai; // puslapiai atimami is kasdien perskaitytu puslapiu
        perskaitytipuslapiai=perskaitytipuslapiai+puslapiupokytis; // didinamas kasdien perskaitytu puslapiu skaicius
        dienos++; // prie bendro skaiciaus pridedama dar viena diena
    }
    return dienos; // reiksme grazinama i pagrindine funckija
}

void isvesti(int n, int dienosknygoms[]) // isvedimo funkcija
{
    ofstream fr(rezultatai); // duomenu isvedimas
    for(int i=0; i<n; i++)
    {
        fr<<dienosknygoms[i]<<endl; // isvedami rezultatai is sukurto masyvo
    }
    fr.close(); // uzdaromas duomenu failas
}
