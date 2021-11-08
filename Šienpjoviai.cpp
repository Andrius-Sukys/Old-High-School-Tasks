#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

const char duomenys[]="duomenys.txt";
const char rezultatai[]="rezultatai.txt";

struct sienpjovys {
        string vardas;
        int litai;
        int centai;
        };

void skaitytiirskaiciuoti(int & n, int & m, sienpjovys info[], int visaszmogausuzdarbis[], int & visasuzdarbis);
void paversti(int n, sienpjovys info[], int visaszmogausuzdarbis[], int visasuzdarbis, int & visasuzdarbislt, int & visasuzdarbisct);
void isvesti(int n, sienpjovys info[], int visasuzdarbislt, int visasuzdarbisct);

int main()
{
    int n, m, visaszmogausuzdarbis[20],visasuzdarbis=0,visasuzdarbislt,visasuzdarbisct;
    sienpjovys info[20];
    skaitytiirskaiciuoti(n,m,info,visaszmogausuzdarbis,visasuzdarbis);
    paversti(n,info,visaszmogausuzdarbis,visasuzdarbis,visasuzdarbislt,visasuzdarbisct);
    isvesti(n,info,visasuzdarbislt,visasuzdarbisct);
    return 0;
}

void skaitytiirskaiciuoti(int & n, int & m, sienpjovys info[], int visaszmogausuzdarbis[], int & visasuzdarbis)
{
    int pinigai[20], plotas[20], gaunamipinigai;
    ifstream fd(duomenys);
    fd>>n>>m;
    for(int i=0; i<n; i++)
    {
        fd>>info[i].vardas>>info[i].litai>>info[i].centai;
        pinigai[i]=info[i].litai*100+info[i].centai;
    }
    for(int i=0; i<n; i++)
    {
        visaszmogausuzdarbis[i]=0;
    }
    for(int i=0; i<m; i++)
    {
        int darbuotojonumeris=0;
        for(int j=0; j<n; j++)
        {
            fd>>plotas[j];
            gaunamipinigai=plotas[j]*pinigai[j];
            visaszmogausuzdarbis[j]=visaszmogausuzdarbis[j]+gaunamipinigai;
        }
    }
    for(int i=0; i<n; i++) visasuzdarbis=visasuzdarbis+visaszmogausuzdarbis[i];
    fd.close();
}

void paversti(int n, sienpjovys info[], int visaszmogausuzdarbis[], int visasuzdarbis, int & visasuzdarbislt, int & visasuzdarbisct)
{
    visasuzdarbislt=0;
    visasuzdarbisct=0;
    for(int i=0; i<n; i++)
    {
        info[i].litai=0;
        info[i].centai=0;
        while(visaszmogausuzdarbis[i]>=100)
        {
            info[i].litai++;
            visaszmogausuzdarbis[i]=visaszmogausuzdarbis[i]-100;
        }
        info[i].centai=visaszmogausuzdarbis[i];
    }
    while(visasuzdarbis>=100)
    {
        visasuzdarbislt++;
        visasuzdarbis=visasuzdarbis-100;
    }
    visasuzdarbisct=visasuzdarbis;
}

void isvesti(int n, sienpjovys info[], int visasuzdarbislt, int visasuzdarbisct)
{
    ofstream fr(rezultatai);
    for (int i=0; i<n; i++)
    {
        fr<<info[i].vardas<<" "<<setw(5)<<left<<" "<<info[i].litai<<" Lt "<<info[i].centai<<" ct"<<endl;
    }
    fr<<"Is viso"<<setw(5)<<left<<" "<<visasuzdarbislt<<" Lt "<<visasuzdarbisct<<" ct";
    fr.close();
}
