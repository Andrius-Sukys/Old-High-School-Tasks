#include<iostream>
#include<fstream>
#include<iomanip>
#include<cmath>

using namespace std;

const char duomenys[]="duomenys.txt"; // duomenu ivedimas
const char rezultatai[]="rezultatai.txt"; // duomenu isvedimas

void nuskaitytiirpirmanaktis (int zibintai[], int & zibintuskaicius, int & naktuskaicius, int & pirmanaktisvietezibintai);
void kitunaktuzibintai (int zibintai[], int naujasmasyvas[], int & naktiesnumeris, int naktuskaicius, int zibintuskaicius, int svieciantystanakti, int & naktiskaidaugiausiai, int & naktiskaimaziausiai, int & maxzibintai, int & minzibintai);
void isvedimas (int zibintai[], int naktiskaimaziausiai, int naktiskaidaugiausiai, int zibintuskaicius);

int main ()
{
    int zibintai[30];
    int naujasmasyvas[30];
    int zibintuskaicius;
    int naktuskaicius;
    int pirmanaktisvietezibintai=0;
    int naktiesnumeris=1;
    int maxzibintai;
    int minzibintai;
    int naktiskaimaziausiai=1;
    int naktiskaidaugiausiai=1;
    int svieciantystanakti=0;
    nuskaitytiirpirmanaktis(zibintai,zibintuskaicius,naktuskaicius,pirmanaktisvietezibintai);
    maxzibintai=pirmanaktisvietezibintai;
    minzibintai=pirmanaktisvietezibintai;
    kitunaktuzibintai(zibintai,naujasmasyvas,naktiesnumeris,naktuskaicius,zibintuskaicius,svieciantystanakti,naktiskaidaugiausiai,naktiskaimaziausiai,maxzibintai,minzibintai);
    isvedimas(zibintai,naktiskaimaziausiai,naktiskaidaugiausiai,zibintuskaicius);
    return 0;
}

void nuskaitytiirpirmanaktis (int zibintai[], int & zibintuskaicius, int & naktuskaicius, int & pirmanaktisvietezibintai)
{
    ifstream fd(duomenys);
    fd>>zibintuskaicius>>naktuskaicius;
    for (int i=0;i<zibintuskaicius;i++)
    {
    fd>>zibintai[i];
    if(zibintai[i]==1) pirmanaktisvietezibintai++;
    }
    fd.close();
}

void kitunaktuzibintai (int zibintai[], int naujasmasyvas[], int & naktiesnumeris, int naktuskaicius, int zibintuskaicius, int svieciantystanakti, int & naktiskaidaugiausiai, int & naktiskaimaziausiai, int & maxzibintai, int & minzibintai)
{
    for(int i=1;i<naktuskaicius;i++)
    {
    naktiesnumeris++;
    svieciantystanakti=0;
    for(int i=0;i<zibintuskaicius;i++)
    {
        if(zibintai[i-1]==1 && zibintai[i+1]==1) naujasmasyvas[i]=0;
        else if((zibintai[i-1]==1 && zibintai [i+1]==0) || (zibintai[i-1]==0 && zibintai[i+1]==1)) naujasmasyvas[i]=1;
        else if(naktiesnumeris%2==0) naujasmasyvas[i]=1;
        else if(naktiesnumeris%2!=0) naujasmasyvas[i]=0;
    }
    for(int i=0;i<zibintuskaicius;i++)
    {
        if(naujasmasyvas[i]==1) svieciantystanakti++;
        zibintai[i]=naujasmasyvas[i];
    }
    if(svieciantystanakti>maxzibintai)
    {
        maxzibintai=svieciantystanakti;
        naktiskaidaugiausiai=naktiesnumeris;
    }
    if(svieciantystanakti<minzibintai)
    {
        minzibintai=svieciantystanakti;
        naktiskaimaziausiai=naktiesnumeris;
    }
    }
}

void isvedimas (int zibintai[], int naktiskaimaziausiai, int naktiskaidaugiausiai, int zibintuskaicius)
{
    ofstream fr(rezultatai);
    for(int i=0;i<zibintuskaicius;i++)
    {
        fr<<zibintai[i]<<" ";
    }
    fr<<endl;
    fr<<"Naktis, kai sviete daugiausiai: "<<naktiskaidaugiausiai<<endl;
    fr<<"Naktis, kai sviete maziausiai: "<<naktiskaimaziausiai;
    fr.close();
}
