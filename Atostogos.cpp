#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

const char duomenys[]="duomenys.txt";
const char rezultatai[]="rezultatai.txt";

void skaityti(int & n, int s[], int v[], double sk[], double vk[]);
void apskaiciuoti(int & n, int s[], int v[], double sk[], double vk[], int bendrasskaicius[], double bendrakaina[]);
void isvesti(int n, int bendrasskaicius[], double bendrakaina[]);

int main()
{
    int n;
    int s[10];
    int v[10];
    double sk[10];
    double vk[10];
    int bendrasskaicius[10];
    double bendrakaina[10];
    skaityti(n,s,v,sk,vk);
    apskaiciuoti(n,s,v,sk,vk,bendrasskaicius,bendrakaina);
    isvesti(n,bendrasskaicius,bendrakaina);
    return 0;
}

void skaityti(int & n, int s[], int v[], double sk[], double vk[])
{
    ifstream fd(duomenys);
    fd>>n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
        fd>>s[j];
        fd>>v[j];
        fd>>sk[j];
        fd>>vk[j];
        }
    }
    fd.close();
}

void apskaiciuoti(int & n, int s[], int v[], double sk[], double vk[], int bendrasskaicius[], double bendrakaina[])
{
    for(int i = 0; i < n; i++)
    {
        bendrasskaicius[i]=s[i]+v[i];
        bendrakaina[i]=s[i]*sk[i]+v[i]*vk[i];
    }
}

void isvesti(int n, int bendrasskaicius[], double bendrakaina[])
{
    ofstream fr(rezultatai);
    for(int i = 0; i < n; i++)
    {
        fr<<fixed<<setprecision(2)<<bendrasskaicius[i]<<" "<<bendrakaina[i]<<endl;
    }
    fr.close();
}
