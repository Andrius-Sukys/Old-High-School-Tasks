#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

const char duomenys[]="U1.txt";
const char rezultatai[]="U1Rez.txt";

void nuskaityti (int slyvos[]);
void suvalgyta(int slyvos[], int mokiniai[]);
void isvesti(int mokiniai[]);

int main()
{
    int slyvos[30];
    int mokiniai[30];
    nuskaityti(slyvos);
    suvalgyta(slyvos,mokiniai);
    isvesti(mokiniai);
    return 0;
}

void nuskaityti (int slyvos[])
{
    ifstream fd(duomenys);
    for(int i=0; i<10; i++)
    {
        fd>>slyvos[i];
    }
    fd.close();
}

void suvalgyta(int slyvos[], int mokiniai[])
{
    // Pagal pirminius duomenis pirmiesiems 10 priskiriamos atitinkamos reiksmes, kitiems nustatoma reiksme 0, nes jie slyvu nevalge.
    for(int i=0; i<20; i++)
    {
        if(i<10)
        {
        mokiniai[i]=slyvos[i];
        slyvos[i]=10-mokiniai[i];
        }
        else
        {
            mokiniai[i]=0;
            slyvos[i]=0;
        }
    }
    // Isskirstomas slyvu perteklius.
    for(int i=0; i<20; i++)
    {
        int j=1;
        while(slyvos[i]>0)
        {
            slyvos[i]=slyvos[i]-1;
            mokiniai[i+j]++;
            j++;
        }
    }
}

void isvesti(int mokiniai[])
{
    ofstream fr(rezultatai);
    for(int i=0; i<20; i++)
    {
        fr<<mokiniai[i]<<" ";
    }
    fr.close();
}
