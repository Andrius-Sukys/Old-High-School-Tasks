#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>

using namespace std;

const char duomenys[]="U1.txt";
const char rezultatai[]="U1rez.txt";

void nuskaityti(int & n, int pestininkai[], int bokstai[], int zirgai[], int rikiai[], int karaliai[], int karalienes[]);
void apskaiciuotirinkinius(int n, int pestininkai[], int bokstai[], int zirgai[], int rikiai[], int karaliai[], int karalienes[], int & rinkiniai);

int main()
{
    int n, rinkiniai=0, pestininkai[10], bokstai[10], zirgai[10], rikiai[10], karaliai[10], karalienes[10];
    nuskaityti(n,pestininkai,bokstai,zirgai,rikiai,karaliai,karalienes);
    apskaiciuotirinkinius(n,pestininkai,bokstai,zirgai,rikiai,karaliai,karalienes,rinkiniai);
    ofstream fr(rezultatai);
    fr<<rinkiniai;
    fr.close();
    return 0;
}

void nuskaityti(int & n, int pestininkai[], int bokstai[], int zirgai[], int rikiai[], int karaliai[], int karalienes[])
{
    ifstream fd(duomenys);
    fd>>n;
    for(int i=0; i<n; i++)
    {
        fd>>pestininkai[i]>>bokstai[i]>>zirgai[i]>>rikiai[i]>>karaliai[i]>>karalienes[i];
    }
    fd.close();
}

void apskaiciuotirinkinius(int n, int pestininkai[], int bokstai[], int zirgai[], int rikiai[], int karaliai[], int karalienes[], int & rinkiniai)
{
    int pestininkairinkiniams=0, bokstairinkiniams=0, zirgairinkiniams=0, rikiairinkiniams=0, karaliairinkiniams=0, karalienesrinkiniams=0;
    for(int i=0; i<n; i++)
    {
    pestininkairinkiniams=pestininkairinkiniams+pestininkai[i];
    bokstairinkiniams=bokstairinkiniams+bokstai[i];
    zirgairinkiniams=zirgairinkiniams+zirgai[i];
    rikiairinkiniams=rikiairinkiniams+rikiai[i];
    karaliairinkiniams=karaliairinkiniams+karaliai[i];
    karalienesrinkiniams=karalienesrinkiniams+karalienes[i];
    }
    while(pestininkairinkiniams>=8 && bokstairinkiniams>=2 && zirgairinkiniams>=2 && rikiairinkiniams>=2 && karaliairinkiniams>=1 && karalienesrinkiniams>=1)
    {
        pestininkairinkiniams=pestininkairinkiniams-8;
        bokstairinkiniams=bokstairinkiniams-2;
        zirgairinkiniams=zirgairinkiniams-2;
        rikiairinkiniams=rikiairinkiniams-2;
        karaliairinkiniams=karaliairinkiniams-1;
        karalienesrinkiniams=karalienesrinkiniams-1;
        rinkiniai++;
    }
}
