#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include<string>

using namespace std;

const char duomenys[]="U1.txt";
const char rezultatai[]="U1rez.txt";

void nuskaityti(int & n, string spalva, int skaicius, int & raudjuosteles, int & zaljuosteles, int & geljuosteles, string R, string Z, string G);
void rikiuoti(int spalvos[], int raudjuosteles, int zaljuosteles, int geljuosteles);
int skaiciuotiveliaveles(int spalvos[]);
void skaiciuotilikuti(int veliaveles, int & raudjuosteles, int & zaljuosteles, int & geljuosteles);
void isvesti(int veliaveles, int raudjuosteles, int zaljuosteles, int geljuosteles, string R, string Z, string G);

int main()
{
    int n,skaicius,spalvos[5],veliaveles,likoraudonu,likozaliu,likogeltonu,raudjuosteles=0,zaljuosteles=0,geljuosteles=0;
    string spalva, R="R",Z="Z",G="G";
    nuskaityti(n,spalva,skaicius,raudjuosteles,zaljuosteles,geljuosteles,R,Z,G);
    rikiuoti(spalvos,raudjuosteles,zaljuosteles,geljuosteles);
    veliaveles=skaiciuotiveliaveles(spalvos);
    skaiciuotilikuti(veliaveles,raudjuosteles,zaljuosteles,geljuosteles);
    isvesti(veliaveles,raudjuosteles,zaljuosteles,geljuosteles,R,Z,G);
    return 0;
}

void nuskaityti(int & n, string spalva, int skaicius, int & raudjuosteles, int & zaljuosteles, int & geljuosteles, string R, string Z, string G)
{
    ifstream fd(duomenys);
    fd>>n;
    for(int i=0; i<n; i++)
    {
        fd>>spalva>>skaicius;
        if(spalva==R) raudjuosteles=raudjuosteles+skaicius;
        if(spalva==Z) zaljuosteles=zaljuosteles+skaicius;
        if(spalva==G) geljuosteles=geljuosteles+skaicius;
    }
    fd.close();
}

void rikiuoti(int spalvos[], int raudjuosteles, int zaljuosteles, int geljuosteles)
{
    spalvos[0]=raudjuosteles;
    spalvos[1]=zaljuosteles;
    spalvos[2]=geljuosteles;
    for (int i = 0;  i <  2;  i ++ )
    for (int  j = i + 1; j <  3;  j++)
    if (spalvos[i] > spalvos[j])
    {
        int sk = spalvos[i];
        spalvos[i] = spalvos[j];
        spalvos[j] = sk;
    }
}

int skaiciuotiveliaveles(int spalvos[])
{
    int veliaveles;
    veliaveles=spalvos[0]/2;
    return veliaveles;
}

void skaiciuotilikuti(int veliaveles, int & raudjuosteles, int & zaljuosteles, int & geljuosteles)
{
    raudjuosteles=raudjuosteles-2*veliaveles;
    zaljuosteles=zaljuosteles-2*veliaveles;
    geljuosteles=geljuosteles-2*veliaveles;
}

void isvesti(int veliaveles, int raudjuosteles, int zaljuosteles, int geljuosteles, string R, string Z, string G)
{
    ofstream fr(rezultatai);
    fr<<veliaveles<<endl;
    fr<<G<<" = "<<geljuosteles<<endl;
    fr<<Z<<" = "<<zaljuosteles<<endl;
    fr<<R<<" = "<<raudjuosteles;
    fr.close();
}
