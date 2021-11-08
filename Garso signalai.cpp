#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

const char duomenys[]="duomenys.txt";
const char rezultatai[]="rezultatai.txt";

void nuskaityti (int & n, int originalussignalas[]);
void islyginti (int n, int originalussignalas[], int naujassignalas[]);
void rasyti (int n, int naujassignalas[]);

int main()
{
    int n;
    int originalussignalas[55];
    int naujassignalas[55];
    nuskaityti(n,originalussignalas);
    islyginti(n,originalussignalas,naujassignalas);
    rasyti(n,naujassignalas);
}

void nuskaityti (int & n, int originalussignalas[])
{
    ifstream fd(duomenys);
    fd>>n;
    for(int i=0; i<n; i++)
    {
        fd>>originalussignalas[i];
    }
    fd.close();
}

void islyginti (int n, int originalussignalas[], int naujassignalas[])
{
    int j=0;
    int vidurkis;
    for(int i=0;i<n;i++)
    {
    if(i==0)
    {
        vidurkis=(originalussignalas[i]+originalussignalas[i+1])/2;
        naujassignalas[j]=vidurkis;
        j++;
    }
    if(i==n-1)
    {
        vidurkis=(originalussignalas[i]+originalussignalas[i-1])/2;
        naujassignalas[j]=vidurkis;
        j++;
    }
    else if (i!=0 && i!=n-1)
    {
        vidurkis=(originalussignalas[i-1]+originalussignalas[i+1]+originalussignalas[i])/3;
        naujassignalas[j]=vidurkis;
        j++;
    }
    }
}

void rasyti (int n, int naujassignalas[])
{
    ofstream fr(rezultatai);
    for(int i=0; i<n; i++)
    {
        fr<<naujassignalas[i]<<" ";
    }
    fr.close();
}
