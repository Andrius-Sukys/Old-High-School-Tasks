#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

const char duomenys[]="duomenys.txt";
const char duomenys2[]="duomenys2.txt";
const char rezultatai[]="rezultatai.txt";

void skaityti(int & n, int & n2, int numeriai[], int numeriai2[]);
void sujungti(int n, int n2, int numeriai[], int numeriai2[]);
void isvesti(int n, int n2, int numeriai[]);

int main()
{
    int n;
    int n2;
    int numeriai[20];
    int numeriai2[20];
    skaityti(n,n2,numeriai,numeriai2);
    sujungti(n,n2,numeriai,numeriai2);
    isvesti(n,n2,numeriai);
    return 0;
}

void skaityti(int & n, int & n2, int numeriai[], int numeriai2[])
{
    ifstream fd(duomenys);
    ifstream fd2(duomenys2);
    fd >> n;
    for (int i = 0; i < n; i++)
    {
        fd>>numeriai[i];
    }
    fd2 >> n2;
    for (int i = 0; i < n2; i++)
    {
        fd2>>numeriai2[i];
    }
    fd.close();
    fd2.close();
}

void sujungti(int n, int n2, int numeriai[], int numeriai2[])
{
    int z=0;
    for (int i = n; i < n+n2; i++)
    {
        numeriai[i]=numeriai2[z];
        z++;
    }
    for (int i = 0; i < n+n2-1; i++)
    for (int j = i+1; j < n+n2; j++)
    if (numeriai[i] > numeriai[j])
    {
        int sk = numeriai[i];
        numeriai[i] = numeriai[j];
        numeriai[j] = sk;
    }
}

void isvesti(int n, int n2, int numeriai[])
{
    ofstream fr(rezultatai);
    for (int i = 0; i < n+n2; i++)
    {
        fr<<numeriai[i]<<" ";
    }
    fr.close();
}
