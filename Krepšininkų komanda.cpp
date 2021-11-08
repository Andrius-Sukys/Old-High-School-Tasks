#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include<fcntl.h>
#include<io.h>

using namespace std;

const char duomenys[]="duomenys.txt";
const char rezultatai[]="rezultatai.txt";

struct krepsininkas {
string vardas;
double ugis;
double taskai;
};

void nuskaityti (krepsininkas a[], int & n, int & p, int & k);
double nustatytididziausiaugi (krepsininkas a[], int n);
double nustatytidaugiausiaitasku (krepsininkas a[], int n);
void atrinkti (krepsininkas a[], krepsininkas b[], int n, int p, int k, int & m, double didziausiasugis, double daugiausiaitasku);
void isvesti (krepsininkas b[], int m);

int main()
{
    int n,k,p,m;
    double didziausiasugis;
    double daugiausiaitasku;
    krepsininkas a[15];
    krepsininkas b[15];
    nuskaityti(a,n,p,k);
    didziausiasugis=nustatytididziausiaugi(a,n);
    daugiausiaitasku=nustatytidaugiausiaitasku(a,n);
    atrinkti(a,b,n,p,k,m,didziausiasugis,daugiausiaitasku);
    isvesti(b,m);
    return 0;
}

void nuskaityti (krepsininkas a[], int & n, int & p, int & k)
{
    ifstream fd(duomenys);
    fd>>n;
    for (int i=0; i<n; i++)
    {
        fd>>a[i].vardas>>a[i].ugis>>a[i].taskai;
    }
    fd>>p;
    fd>>k;
    fd.close();
}

double nustatytididziausiaugi (krepsininkas a[], int n)
{
    double ugismax;
    ugismax=a[0].ugis;
    for(int i=0; i<n; i++)
    {
        if(a[i].ugis>ugismax)
        ugismax=a[i].ugis;
    }
    return ugismax;
}

double nustatytidaugiausiaitasku (krepsininkas a[], int n)
{
    double taskaimax;
    taskaimax=a[0].taskai;
    for(int i=0; i<n; i++)
    {
        if(a[i].taskai>taskaimax)
        taskaimax=a[i].taskai;
    }
    return taskaimax;
}

void atrinkti (krepsininkas a[], krepsininkas b[], int n, int p, int k, int & m, double didziausiasugis, double daugiausiaitasku)
{
    m=0;
    for(int i=0; i<n; i++)
    {
        if(a[i].ugis>=(didziausiasugis-didziausiasugis/100*p) || a[i].taskai>=(daugiausiaitasku-daugiausiaitasku/100*k))
        {
        b[m]=a[i];
        m++;
        }
    }
}

void isvesti (krepsininkas b[], int m)
{
    ofstream fr(rezultatai);
    fr<<"----------------------------------------"<<endl;
    fr<<" Vardas        Ugis        Taskai"<<endl;
    fr<<"----------------------------------------"<<endl;
    for(int i=0; i<m; i++)
    {
    fr<<" "<<setw(10)<<left<<b[i].vardas<<"    "<<setw(10)<<b[i].ugis<<"   "<<setw(10)<<b[i].taskai<<endl;
    }
    fr<<"----------------------------------------";
}
