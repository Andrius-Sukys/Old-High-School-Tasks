#include<iostream>
#include<fstream>
#include<iomanip>
#include<cmath>

using namespace std;

const char duomenys[]="duomenys.txt"; // duomenu ivedimas
const char rezultatai[]="rezultatai.txt"; // duomenu isvedimas

void nuskaityti (int a[], int b[], int & n); // funkcija nuskaitymui
void skaiciuoti (int a[], int b[], int n, int & isleista, int & laimeta); // funkcija isleistiems ir laimetiems pinigams skaiciuoti
void skaiciuotididziausia (int b[], int n, int & didziausiaslaimejimas); // funkcija didziausiam laimejimui rasti

int main ()
{
   int a[30]; // ivedamas isleistu pinigu masyvas
   int b[30]; // ivedamas laimetu pinigu masyvas
   int n; // bilietu skaicius
   int isleista=0;
   int laimeta=0;
   int didziausiaslaimejimas=0;
   int laimejimas=0;
   ofstream fr(rezultatai);
   nuskaityti(a,b,n);
   skaiciuoti(a,b,n,isleista,laimeta);
   skaiciuotididziausia(b,n,didziausiaslaimejimas);
   if(laimeta>isleista)
   laimejimas=laimeta-isleista;
   if(isleista>laimeta)
   laimejimas=isleista-laimeta;
   fr<<isleista<<"     ";
   fr<<laimeta<<endl;
   fr<<"Didziausias laimejimas: "<<didziausiaslaimejimas<<endl;
   if(laimeta>isleista)
   fr<<"Pelnas: "<<laimejimas;
   if(isleista>laimeta)
   fr<<"Nuostolis: "<<laimejimas;
   if(laimeta==isleista)
   fr<<"Lygiosios";
   fr.close();
return 0;
}

void nuskaityti (int a[], int b[], int & n)
{
    ifstream fd(duomenys);
    fd>>n;
    for (int i=0;i<n;i++)
    {
    fd>>a[i];
    fd>>b[i];
    }
    fd.close();
}

void skaiciuoti (int a[], int b[], int n, int & isleista, int & laimeta)
{
    for(int i=0; i<n; i++)
    {
    isleista=isleista+a[i];
    laimeta=laimeta+b[i];
    }
}

void skaiciuotididziausia (int b[], int n, int & didziausiaslaimejimas)
{
    b[0]=didziausiaslaimejimas;
    for(int i=0; i<n; i++)
    {
        if(b[i]>didziausiaslaimejimas)
        didziausiaslaimejimas=b[i];
    }
}
