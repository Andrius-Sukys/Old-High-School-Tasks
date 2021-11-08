#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

const char duomenys[]="U1.txt";
const char rezultatai[]="U1rez.txt";

void skaityti(int & k, int logo1[], int logo2[], int logo3[]);
void skaiciuoti(int k, int logo1[], int logo2[], int logo3[], int logotaskai[], int & skyrius, int & gaunami1taskai, int & gaunami2taskai, int & gaunami3taskai);
int rasti(int logotaskai[]);
void rasyti(int logobalsai[], int logotaskai[], int geriausias);

int main()
{
    int k,logo1[20],logo2[20],logo3[20],logotaskai[20],logobalsai[20],gaunami1taskai,gaunami2taskai,gaunami3taskai,geriausias;
    logobalsai[0]=0; logobalsai[1]=0; logobalsai[2]=0; logotaskai[0]=0; logotaskai[1]=0; logotaskai[2]=0;
    skaityti(k,logo1,logo2,logo3);
    int skyrius=0;
    for (int i=0; i<k; i++)
    {
        logobalsai[0]=logobalsai[0]+logo1[i];
        logobalsai[1]=logobalsai[1]+logo2[i];
        logobalsai[2]=logobalsai[2]+logo3[i];
        skaiciuoti(k,logo1,logo2,logo3,logotaskai,skyrius,gaunami1taskai,gaunami2taskai,gaunami3taskai);
        logotaskai[0]=logotaskai[0]+gaunami1taskai;
        logotaskai[1]=logotaskai[1]+gaunami2taskai;
        logotaskai[2]=logotaskai[2]+gaunami3taskai;
    }
    if(logotaskai[0]==logotaskai[1] && logotaskai[1]==logotaskai[2])
    {
        logotaskai[0]=logotaskai[0]+logo1[k];
        logotaskai[1]=logotaskai[1]+logo2[k];
        logotaskai[2]=logotaskai[2]+logo3[k];
    }
    if(logotaskai[0]==logotaskai[1] && logotaskai[0]>logotaskai[2])
    {
        logotaskai[0]=logotaskai[0]+logo1[k];
        logotaskai[1]=logotaskai[1]+logo2[k];
        logotaskai[2]=logotaskai[2]+logo3[k];
    }
    if(logotaskai[0]==logotaskai[2] && logotaskai[0]>logotaskai[1])
    {
        logotaskai[0]=logotaskai[0]+logo1[k];
        logotaskai[1]=logotaskai[1]+logo2[k];
        logotaskai[2]=logotaskai[2]+logo3[k];
    }
    if(logotaskai[1]==logotaskai[2] && logotaskai[1]>logotaskai[0])
    {
        logotaskai[0]=logotaskai[0]+logo1[k];
        logotaskai[1]=logotaskai[1]+logo2[k];
        logotaskai[2]=logotaskai[2]+logo3[k];
    }
    geriausias=rasti(logotaskai);
    rasyti(logobalsai,logotaskai,geriausias);
    return 0;
}

void skaityti(int & k, int logo1[], int logo2[], int logo3[])
{
    ifstream fd(duomenys);
    fd>>k;
    for(int i=0; i<k+1; i++)
    {
        fd>>logo1[i]>>logo2[i]>>logo3[i];
    }
}

void skaiciuoti(int k, int logo1[], int logo2[], int logo3[], int logotaskai[], int & skyrius, int & gaunami1taskai, int & gaunami2taskai, int & gaunami3taskai)
{
    gaunami1taskai=0, gaunami2taskai=0, gaunami3taskai=0;
    if(logo1[skyrius]>logo2[skyrius] && logo1[skyrius]>logo3[skyrius]) gaunami1taskai=gaunami1taskai+4;
    if(logo2[skyrius]>logo1[skyrius] && logo2[skyrius]>logo3[skyrius]) gaunami2taskai=gaunami2taskai+4;
    if(logo3[skyrius]>logo2[skyrius] && logo3[skyrius]>logo1[skyrius]) gaunami3taskai=gaunami3taskai+4;
    if(logo1[skyrius]==logo2[skyrius] && logo1[skyrius]!=logo3[skyrius] && logo1[skyrius]>logo3[skyrius])
    {
        gaunami1taskai=gaunami1taskai+2;
        gaunami2taskai=gaunami2taskai+2;
    }
    if(logo1[skyrius]==logo3[skyrius] && logo1[skyrius]!=logo2[skyrius] && logo1[skyrius]>logo2[skyrius])
    {
        gaunami1taskai=gaunami1taskai+2;
        gaunami3taskai=gaunami3taskai+2;
    }
    if(logo2[skyrius]==logo3[skyrius] && logo2[skyrius]!=logo1[skyrius] && logo2[skyrius]>logo1[skyrius])
    {
        gaunami2taskai=gaunami2taskai+2;
        gaunami3taskai=gaunami3taskai+2;
    }
    skyrius++;
}

int rasti(int logotaskai[])
{
    int laimejeslogotipas,maxtaskai;
    maxtaskai=logotaskai[0];
    for(int i=0; i<3; i++)
    {
        if(logotaskai[i]>maxtaskai)
        {
            maxtaskai=logotaskai[i];
            laimejeslogotipas=i+1;
        }
    }
    return laimejeslogotipas;
}

void rasyti(int logobalsai[], int logotaskai[], int geriausias)
{
    ofstream fr(rezultatai);
    for(int i=0; i<3; i++)
    {
        fr<<logobalsai[i]<<" ";
    }
    fr<<endl;
    for(int i=0; i<3; i++)
    {
        fr<<logotaskai[i]<<" ";
    }
    fr<<endl;
    fr<<geriausias;
    fr.close();
}
