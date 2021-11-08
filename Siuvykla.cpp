#include<iostream>
#include<fstream>
#include<iomanip>
#include<cmath>

using namespace std;

const char duomenys[]="duomenys.txt";
const char rezultatai[]="rezultatai.txt";

struct gamybosduomenys {
        string lytis;
        string drabuzis;
        double kaina;
        };

void skaityti (int & n, gamybosduomenys gamyba[]);
void rikiuoti (int n, gamybosduomenys gamyba[]);
void skaiciuoti (int n, gamybosduomenys gamyba[], double & pvidurkis, double & svidurkis, double & kvidurkis);
void isvesti (int n, gamybosduomenys gamyba[], double pvidurkis, double svidurkis, double kvidurkis, string palyginimas);
void nustatyti (int n, gamybosduomenys gamyba[], double pvidurkis, double svidurkis, double kvidurkis, string & palyginimas);

int main()
{
    int n;
    double pvidurkis,svidurkis,kvidurkis;
    string p,s,k,palyginimas;
    gamybosduomenys gamyba[20];
    skaityti(n,gamyba);
    rikiuoti(n,gamyba);
    skaiciuoti(n,gamyba,pvidurkis,svidurkis,kvidurkis);
    nustatyti(n,gamyba,pvidurkis,svidurkis,kvidurkis,palyginimas);
    isvesti(n,gamyba,pvidurkis,svidurkis,kvidurkis,palyginimas);
    return 0;
}

void skaityti (int & n, gamybosduomenys gamyba[])
{
    ifstream fd(duomenys);
    fd>>n;
    for(int i=0; i<n; i++)
    {
        fd>>gamyba[i].lytis>>gamyba[i].drabuzis>>gamyba[i].kaina;
    }
    fd.close();
}

void rikiuoti (int n, gamybosduomenys gamyba[])
{
    for (int i=0; i<n-1; i++)
    for (int j=i+1; j<n; j++)
    if (gamyba[i].kaina < gamyba[j].kaina)
    {
        int skk=gamyba[i].kaina;
        gamyba[i].kaina=gamyba[j].kaina;
        gamyba[j].kaina=skk;
        string skl=gamyba[i].lytis;
        gamyba[i].lytis=gamyba[j].lytis;
        gamyba[j].lytis=skl;
        string skd=gamyba[i].drabuzis;
        gamyba[i].drabuzis=gamyba[j].drabuzis;
        gamyba[j].drabuzis=skd;
    }
}

void skaiciuoti (int n, gamybosduomenys gamyba[], double & pvidurkis, double & svidurkis, double & kvidurkis)
{
    float paltaisud=0, striukessud=0, kostiumaisud=0;
    int pkmasyvas[20], skmasyvas[20], kkmasyvas[20], paltai=0, striukes=0, kostiumai=0;
    string p="p", s="s", k="k";
    for(int i=0; i<n; i++)
    {
        if(gamyba[i].drabuzis==p)
        {
            pkmasyvas[paltai]=gamyba[i].kaina;
            paltai++;
        }
        if(gamyba[i].drabuzis==s)
        {
            skmasyvas[striukes]=gamyba[i].kaina;
            striukes++;
        }
        if(gamyba[i].drabuzis==k)
        {
            kkmasyvas[kostiumai]=gamyba[i].kaina;
            kostiumai++;
        }
    }
    for(int i=0; i<paltai; i++)
    {
        paltaisud=paltaisud+pkmasyvas[i];
    }
    for(int i=0; i<striukes; i++)
    {
        striukessud=striukessud+skmasyvas[i];
    }
    for(int i=0; i<kostiumai; i++)
    {
        kostiumaisud=kostiumaisud+kkmasyvas[i];
    }
    pvidurkis=paltaisud/paltai;
    svidurkis=striukessud/striukes;
    kvidurkis=kostiumaisud/kostiumai;
}

void nustatyti (int n, gamybosduomenys gamyba[], double pvidurkis, double svidurkis, double kvidurkis, string & palyginimas)
{
    float bendrakainam=0, bendrakainav=0;
    string m="m", v="v";
    for(int i=0; i<n; i++)
    {
    if(gamyba[i].lytis==m) bendrakainam=bendrakainam+gamyba[i].kaina;
    if(gamyba[i].lytis==v) bendrakainav=bendrakainav+gamyba[i].kaina;
    }
    if(bendrakainam>bendrakainav) palyginimas="Moteru drabuziai siuvami brangiau";
    if(bendrakainav>bendrakainam) palyginimas="Vyru drabuziai siuvami brangiau";
    if(bendrakainav==bendrakainam) palyginimas="Vyru ir moteru drabuziai siuvami ta pacia kaina";
}

void isvesti (int n, gamybosduomenys gamyba[], double pvidurkis, double svidurkis, double kvidurkis, string palyginimas)
{
    ofstream fr(rezultatai);
    for(int i=0; i<n; i++)
    {
        fr<<gamyba[i].lytis<<" "<<gamyba[i].drabuzis<<" "<<gamyba[i].kaina<<endl;
    }
    fr<<fixed<<setprecision(2)<<"Paltu "<<setw(9)<<right<<pvidurkis<<endl;
    fr<<fixed<<setprecision(2)<<"Striukiu "<<setw(6)<<right<<svidurkis<<endl;
    fr<<fixed<<setprecision(2)<<"Kostiumu "<<setw(5)<<right<<kvidurkis<<endl;
    fr<<palyginimas;
    fr.close();
}
