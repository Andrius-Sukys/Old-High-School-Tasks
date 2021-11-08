#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

const char duomenys[]="duomenys.txt";
const char rezultatai[]="rezultatai.txt";

void nuskaityti(double & b, double & d, double & m, int & n, double bk[], double dk[]);
void apskaiciuoti (double b, double d, double m, int n, double bk[], double dk[]);
void isvesti(int n, double bk[], double dk[]);

int main()
{
    double b;
    double d;
    double m;
    int n;
    double bk[10];
    double dk[10];
    nuskaityti(b,d,m,n,bk,dk);
    apskaiciuoti(b,d,m,n,bk,dk);
    isvesti(n,bk,dk);
    return 0;
}

void nuskaityti(double & b, double & d, double & m, int & n, double bk[], double dk[])
{
    ifstream fd(duomenys);
    fd>>b>>d>>m>>n;
    for(int i=0; i<n; i++)
    {
        fd>>bk[i]>>dk[i];
    }
    fd.close();
}

void apskaiciuoti (double b, double d, double m, int n, double bk[], double dk[])
{
    for(int i=0; i<n; i++)
    {
    bk[i]=m/100*b*bk[i];
    dk[i]=m/100*d*dk[i];
    }
}

void isvesti(int n, double bk[], double dk[])
{
    ofstream fr(rezultatai);
    for(int i=0; i<n; i++)
    {
        fr<<fixed<<setprecision(2)<<bk[i]<<" "<<dk[i]<<endl;
    }
    fr.close();
}
