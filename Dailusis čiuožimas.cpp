#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

const char duomenys[]="duomenys.txt";
const char rezultatai[]="rezultatai.txt";

void nuskaityti(int & n, double balai1[], double balai2[]);
void rikiuoti(int n, double balai1[], double balai2[]);
double sutvarkytibalus(int n, double masyvas[]);
void isvesti(int n, double balai1vidurkis, double balai2vidurkis);

int main()
{
    int n;
    double balai1[50];
    double balai2[50];
    double balai1vidurkis;
    double balai2vidurkis;
    nuskaityti(n,balai1,balai2);
    rikiuoti(n,balai1,balai2);
    balai1vidurkis=sutvarkytibalus(n,balai1);
    balai2vidurkis=sutvarkytibalus(n,balai2);
    isvesti(n,balai1vidurkis,balai2vidurkis);
    return 0;
}

void nuskaityti(int & n, double balai1[], double balai2[])
{
    ifstream fd(duomenys);
    fd>>n;
    for(int i=0; i<n; i++)
    {
        fd>>balai1[i];
        fd>>balai2[i];
    }
    fd.close();
}

void rikiuoti(int n, double balai1[], double balai2[])
{
    for (int i = 0;  i <  n - 1;  i++)
    for (int  j = i + 1; j <  n;  j++)
    {
    if (balai1[i] > balai1[j])
    {
        double sk = balai1[i];
        balai1[i] = balai1[j];
        balai1[j] = sk;
    }
    if(balai2[i] > balai2[j])
    {
        double sk = balai2[i];
        balai2[i] = balai2[j];
        balai2[j] = sk;
    }
    }
}

double sutvarkytibalus(int n, double masyvas[])
{
    double balusuma=0;
    double vidurkis=0;
    for(int i=1; i<n-1; i++) balusuma=balusuma+masyvas[i];
    vidurkis=balusuma/(n-2);
    return vidurkis;
}

void isvesti(int n, double balai1vidurkis, double balai2vidurkis)
{
    ofstream fr(rezultatai);
    fr<<setprecision(2)<<balai1vidurkis<<endl;
    fr<<setprecision(2)<<balai2vidurkis;
    fr.close();
}
