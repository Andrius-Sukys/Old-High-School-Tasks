#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

const char duomenys[]="U1.txt";
const char rezultatai[]="U1rez.txt";

using namespace std;

void skaitytiirrasti(int & n, int & sunkiausiosmase);
void rastilengvesnes(int n, int sunkiausiosmase, int & kiekis);
void isvesti (int sunkiausiosmase, int kiekis);

int main()
{
    int n, sunkiausiosmase=0, kiekis=0;
    skaitytiirrasti(n,sunkiausiosmase);
    rastilengvesnes(n,sunkiausiosmase,kiekis);
    isvesti(sunkiausiosmase,kiekis);
    return 0;
}

void skaitytiirrasti(int & n, int & sunkiausiosmase)
{
    ifstream fd(duomenys);
    int kuprinesmase;
    fd>>n;
    for(int i=0; i<n; i++)
    {
        fd>>kuprinesmase;
        if(kuprinesmase>sunkiausiosmase) sunkiausiosmase=kuprinesmase;
    }
    fd.close();
}

void rastilengvesnes(int n, int sunkiausiosmase, int & kiekis)
{
    ifstream fd(duomenys);
    int kuprinesmase;
    fd>>n;
    for(int i=0; i<n; i++)
    {
        fd>>kuprinesmase;
        if(kuprinesmase*2<=sunkiausiosmase) kiekis++;
    }
    fd.close();
}

void isvesti (int sunkiausiosmase, int kiekis)
{
    ofstream fr(rezultatai);
    fr<<sunkiausiosmase<<" "<<kiekis;
    fr.close();
}
