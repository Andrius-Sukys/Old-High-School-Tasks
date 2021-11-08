#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

const char duomenys[]="duomenys.txt";
const char rezultatai[]="rezultatai.txt";

void nuskaityti(int & n, int diena[], int temperatura[]);
void rastiauksciausia (int n, int & auksciausiatemperatura, int temperatura[]);
void rastidienaskuriomisauksciausia(int n, int auksciausiatemperatura, int diena[], int temperatura[], int dienoskaiauksciausia[], int & j);
void rasyti (int auksciausiatemperatura, int dienoskaiauksciausia[],  int j);

int main()
{
    int n;
    int diena[35];
    int temperatura[35];
    int dienoskaiauksciausia[35];
    int auksciausiatemperatura;
    int j;
    nuskaityti(n,diena,temperatura);
    rastiauksciausia(n,auksciausiatemperatura,temperatura);
    rastidienaskuriomisauksciausia(n,auksciausiatemperatura,diena,temperatura,dienoskaiauksciausia,j);
    rasyti(auksciausiatemperatura,dienoskaiauksciausia,j);
    return 0;
}

void nuskaityti(int & n, int diena[], int temperatura[])
{
    ifstream fd(duomenys);
    fd>>n;
    for (int i=0; i<n; i++)
    {
        fd>>diena[i];
        fd>>temperatura[i];
    }
    fd.close();
}

void rastiauksciausia (int n, int & auksciausiatemperatura, int temperatura[])
{
    temperatura[0]=auksciausiatemperatura;
    for(int i=0; i<n; i++)
    {
        if(temperatura[i]>auksciausiatemperatura)
        auksciausiatemperatura=temperatura[i];
    }
}

void rastidienaskuriomisauksciausia (int n, int auksciausiatemperatura, int diena[], int temperatura[], int dienoskaiauksciausia[], int & j)
{
    j=0;
    for(int i=0; i<n; i++)
    {
        if(auksciausiatemperatura==temperatura[i])
        {
            dienoskaiauksciausia[j]=diena[i];
            j++;
        }
    }
}

void rasyti (int auksciausiatemperatura, int dienoskaiauksciausia[],  int j)
{
    ofstream fr(rezultatai);
    fr<<"Maksimali temperatura "<<auksciausiatemperatura<<" buvo siomis dienomis:"<<endl;
    for(int i=0; i<j; i++)
    {
        fr<<dienoskaiauksciausia[i]<<" ";
    }
    fr.close();
}
