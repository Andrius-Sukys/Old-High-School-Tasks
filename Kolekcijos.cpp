#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

const char duomenys[]="duomenys.txt";
const char rezultatai[]="rezultatai.txt";

void nuskaityti(int & n, int & m, int visi[]);
void rasti(int n, int m, int visi[], int rasa[], int rimas[], int & rasaskaicius, int & rimasskaicius);
void rikiuoti(int rasaskaicius, int rimasskaicius, int rasa[], int rimas[]);
void rasyti(int n, int masyvas[]);
void isvalyti();

int main()
{
    isvalyti();
    int n,m,rasaskaicius,rimasskaicius;
    int visi[50];
    int rasa[50];
    int rimas[50];
    int masyvas[50];
    nuskaityti(n,m,visi);
    rasti(n,m,visi,rasa,rimas,rasaskaicius,rimasskaicius);
    rikiuoti(rasaskaicius,rimasskaicius,rasa,rimas);
    ofstream fr(rezultatai,ios::app);
    n=rasaskaicius;
    fr<<"Rasos kolekcija sudaro "<<n<<" daiktai:"<<endl;
    for(int i=0; i<n; i++)
    {
        masyvas[i]=rasa[i];
    }
    rasyti(n,masyvas);
    n=rimasskaicius;
    fr<<"Rimo kolekcija sudaro "<<n<<" daiktai:"<<endl;
    for(int i=0; i<n; i++)
    {
        masyvas[i]=rimas[i];
    }
    rasyti(n,masyvas);
    fr.close();
    return 0;
}

void isvalyti()
{
    ofstream fr(rezultatai);
    fr.close();
}

void nuskaityti(int & n, int & m, int visi[])
{
    ifstream fd(duomenys);
    fd>>n;
    for(int i=0; i<n; i++)
    {
        fd>>visi[i];
    }
    fd>>m;
    for(int j=n; j<n+m; j++)
    {
        fd>>visi[j];
    }
    fd.close();
}

void rasti(int n, int m, int visi[], int rasa[], int rimas[], int & rasaskaicius, int & rimasskaicius)
{
    int skaicius;
    rasaskaicius=0;
    rimasskaicius=0;
    for(int i=0; i<n+m; i++)
    {
        skaicius=visi[i];
        int skaitmenusuma=0;
        while(skaicius>0)
        {
            skaicius=skaicius/10;
            skaitmenusuma++;
        }
        if(skaitmenusuma==2)
        {
            rasa[rasaskaicius]=visi[i];
            rasaskaicius++;
        }
        if(skaitmenusuma==3)
        {
            rimas[rimasskaicius]=visi[i];
            rimasskaicius++;
        }
    }
}

void rikiuoti(int rasaskaicius, int rimasskaicius, int rasa[], int rimas[])
{
    int sk;
    for (int i = 0;  i <  rasaskaicius - 1;  i ++ )
    for (int  j = i + 1; j <  rasaskaicius;  j++)
    if (rasa[i] > rasa[j])
    {
        int sk = rasa[i];
        rasa[i] = rasa[j];
        rasa[j] = sk;
    }
    for (int i = 0;  i <  rimasskaicius - 1;  i ++ )
    for (int  j = i + 1; j <  rimasskaicius;  j++)
    if (rimas[i] > rimas[j])
    {
        int sk = rimas[i];
        rimas[i] = rimas[j];
        rimas[j] = sk;
    }
}

void rasyti(int n, int masyvas[])
{
    ofstream fr(rezultatai,ios::app);
    for(int i=0; i<n; i++) fr<<masyvas[i]<<" ";
    fr<<endl;
    fr.close();
}
