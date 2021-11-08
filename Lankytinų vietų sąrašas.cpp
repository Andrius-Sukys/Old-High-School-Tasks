#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

const char duomenys[]="duomenys.txt";
const char rezultatai[]="rezultatai.txt";

void nuskaityti(int & n, string LankytinosVietos[]);
void rasyti(int n, string LankytinosVietos[], string komentaras);
void rikiuoti(int n, string LankytinosVietos[]);

int main()
{
    int n;
    string LankytinosVietos[30];
    ofstream fr(rezultatai);
    fr.close();
    nuskaityti(n,LankytinosVietos);
    rasyti(n,LankytinosVietos,"Pradiniai duomenys");
    rikiuoti(n,LankytinosVietos);
    rasyti(n,LankytinosVietos,"Surikiuoti duomenys");
    return 0;
}

void nuskaityti(int & n, string LankytinosVietos[])
{
    ifstream fd(duomenys);
    fd>>n;
    fd.ignore(80, '\n');
    for(int i=0; i<n; i++)
    {
        getline(fd,LankytinosVietos[i]);
    }
    fd.close();
}

void rasyti(int n, string LankytinosVietos[], string komentaras)
{
    ofstream fr(rezultatai, ios::app);
    fr<<"----------------------------------"<<endl;
    fr<< komentaras << endl;
    fr<<"----------------------------------"<<endl;
    for(int i=0; i<n; i++)
    {
        fr<<LankytinosVietos[i]<<endl;
    }
    fr.close();
}

void rikiuoti(int n, string LankytinosVietos[])
{
    string laikinaeilute;
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(LankytinosVietos[j]<LankytinosVietos[i])
            {
                laikinaeilute=LankytinosVietos[j];
                LankytinosVietos[j]=LankytinosVietos[i];
                LankytinosVietos[i]=laikinaeilute;
            }
        }
    }
}
