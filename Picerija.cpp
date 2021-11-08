#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

const char duomenys[]="U1.txt";
const char rezultatai[]="U1rez.txt";

void skaityti (int & n, int x[], int y[], int & kmplanas);
int skaiciuoti (int yatstumas, int xatstumas);
void isvesti (int neaptarnauti, int kmnuvaziuota);

int main()
{
    int n,x[20],y[20],kmplanas,kmnuvaziuota=0,neaptarnauti;
    skaityti(n,x,y,kmplanas);
    int yatstumas,xatstumas,kmklientui;
    neaptarnauti=n;
    for(int i=0; i<n; i++)
    {
    if(kmnuvaziuota<kmplanas)
    {
        yatstumas=y[i];
        xatstumas=x[i];
        kmklientui=skaiciuoti(yatstumas,xatstumas);
        kmnuvaziuota=kmnuvaziuota+kmklientui;
        neaptarnauti--;
    }
    }
    isvesti(neaptarnauti,kmnuvaziuota);
    return 0;
}

void skaityti (int & n, int x[], int y[], int & kmplanas)
{
    ifstream fd(duomenys);
    fd>>n;
    fd>>kmplanas;
    for(int i=0; i<n; i++)
    {
        fd>>x[i]>>y[i];
    }
    fd.close();
}

int skaiciuoti (int yatstumas, int xatstumas)
{
    int bendrasatstumas;
    if(yatstumas<0) yatstumas=yatstumas*(-1);
    if(xatstumas<0) xatstumas=xatstumas*(-1);
    bendrasatstumas=yatstumas+xatstumas;
    return bendrasatstumas;
}

void isvesti (int neaptarnauti, int kmnuvaziuota)
{
    ofstream fr(rezultatai);
    fr<<neaptarnauti<<" "<<kmnuvaziuota;
    fr.close();
}
