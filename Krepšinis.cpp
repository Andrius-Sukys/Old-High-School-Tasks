#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

const char duomenys[]="U1.txt";
const char rezultatai[]="U1Rez.txt";

void nuskaityti(int & n, int & z, int laikai, int numeris[], int zaide[], int ilsejosi[], int startinispenketas[], int visilaikai[]);
int rasti(int n, int masyvas[]);
void rastidaugmaz(int n, int maziausiaizaide[], int daugiausiaizaide[], int laikaszaista, int laikasilsetasi, int numeris[], int zaide[], int ilsejosi[]);
void rasyti(int n, int z, int laikaszaista, int laikasilsetasi, int maziausiaizaide[], int daugiausiaizaide[], int startinispenketas[]);

int main()
{
    int n, z=0, laikai,laikaszaista,laikasilsetasi,numeris[20],visilaikai[30],zaide[30],ilsejosi[30],startinispenketas[10],maziausiaizaide[30],daugiausiaizaide[30];
    nuskaityti(n,z,laikai,numeris,zaide,ilsejosi,startinispenketas,visilaikai);
    laikaszaista = rasti(n,zaide);
    laikasilsetasi = rasti(n,ilsejosi);
    rastidaugmaz(n,maziausiaizaide,daugiausiaizaide,laikaszaista,laikasilsetasi,numeris,zaide,ilsejosi);
    rasyti(n,z,laikaszaista,laikasilsetasi,maziausiaizaide,daugiausiaizaide,startinispenketas);
    return 0;
}

void nuskaityti(int & n, int & z, int laikai, int numeris[], int zaide[], int ilsejosi[], int startinispenketas[], int visilaikai[])
{
    ifstream fd(duomenys);
    fd>>n;
    for(int i=0; i<n; i++)
    {
        int zaista=0;
        int ilsetasi=0;
        fd>>numeris[i];
        fd>>laikai;
        for(int j=0; j<laikai;j++)
        {
            fd>>visilaikai[j];
            if(visilaikai[j]>0) zaista=zaista+visilaikai[j];
            if(visilaikai[j]<0) ilsetasi=ilsetasi-visilaikai[j];
        }
        zaide[i]=zaista;
        ilsejosi[i]=ilsetasi;
        if(visilaikai[0]>0)
        {
            startinispenketas[z]=numeris[i];
            z++;
        }
    }
    fd.close();
}

int rasti(int n, int masyvas[])
{
    int daugiausiai = masyvas[0];
    for(int i=0; i<n;i++)
    {
        if(masyvas[i]>daugiausiai)
        daugiausiai=masyvas[i];
    }
    return daugiausiai;
}

void rastidaugmaz(int n, int maziausiaizaide[], int daugiausiaizaide[], int laikaszaista, int laikasilsetasi, int numeris[], int zaide[], int ilsejosi[])
{
    int maz=0;
    int daug=0;
    for(int i=0; i<n;i++)
    {
        if(laikaszaista==zaide[i])
        {
            daugiausiaizaide[daug]=numeris[i];
            daug++;
        }
        if(laikasilsetasi==ilsejosi[i])
        {
            maziausiaizaide[maz]=numeris[i];
            maz++;
        }
    }
    for (int i = 0;  i <  n - 1;  i ++ )
    for (int  j = i + 1; j <  n;  j++)
    {
    if(daug>1)
    if (daugiausiaizaide[i] > daugiausiaizaide[j])
    {
        int sk = daugiausiaizaide[i];
        daugiausiaizaide[i] = daugiausiaizaide[j];
        daugiausiaizaide[j] = sk;
    }
    if(maz>1)
    if (maziausiaizaide[i] > maziausiaizaide[j])
    {
        int sk = maziausiaizaide[i];
        maziausiaizaide[i] = maziausiaizaide[j];
        maziausiaizaide[j] = sk;
    }
    }
}

void rasyti(int n, int z, int laikaszaista, int laikasilsetasi, int maziausiaizaide[], int daugiausiaizaide[], int startinispenketas[])
{
    ofstream fr(rezultatai);
    for (int i = 0; i < z - 1; i ++ )
    for (int j = i + 1; j < z; j++)
    if (startinispenketas[i] > startinispenketas[j])
    {
        int sk = startinispenketas[i];
        startinispenketas[i] = startinispenketas[j];
        startinispenketas[j] = sk;
    }
    for(int i=0; i<z; i++)
    fr<<startinispenketas[i]<<" ";
    fr<<endl;
    fr<<daugiausiaizaide[0]<<" "<<laikaszaista<<endl;
    fr<<maziausiaizaide[0]<<" "<<laikasilsetasi;
    fr.close();
}
