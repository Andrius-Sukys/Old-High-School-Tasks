#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

const char duomenys[]="duomenys.txt";
const char rezultatai[]="rezultatai.txt";

void nuskaityti(int & n, int & k, int vaistazoles[]);
void skaiciuoti(int n, int k, int & dezesislikucio, int vaistazoles[], int dezes[], int dezutes[]);
int rastididziausia(int n, int dezes[]);
void isvesti(int n, int dezes[], int dezutes[], int dezesislikucio, int didziausias);

int main()
{
    int n;
    int k;
    int didziausias;
    int dezesislikucio;
    int vaistazoles[35];
    int dezes[35];
    int dezutes[35];
    nuskaityti(n,k,vaistazoles);
    skaiciuoti(n,k,dezesislikucio,vaistazoles,dezes,dezutes);
    didziausias=rastididziausia(n,dezes);
    isvesti(n,dezes,dezutes,dezesislikucio,didziausias);
    return 0;
}

void nuskaityti(int & n, int & k, int vaistazoles[])
{
    ifstream fd(duomenys);
    fd>>n>>k;
    for(int i = 0; i < n; i++)
    {
        fd>>vaistazoles[i];
    }
    fd.close();
}

void skaiciuoti(int n, int k, int & dezesislikucio, int vaistazoles[], int dezes[], int dezutes[])
{
    for(int i = 0; i < n; i++)
    {
        dezes[i]=0;
        while(vaistazoles[i]>=8)
        {
        dezes[i]++;
        vaistazoles[i]=vaistazoles[i]-8;
        }
        dezutes[i]=vaistazoles[i];
    }
    int likutis=0;
    dezesislikucio=0;
    for(int i = 0; i < n; i++)
    {
        likutis=likutis+vaistazoles[i];
    }
    while(likutis>=8)
    {
        likutis=likutis-8;
        dezesislikucio++;
    }
}

int rastididziausia(int n, int dezes[])
{
    int daugiausiai;
    daugiausiai=dezes[0];
    for(int i = 0; i < n; i++)
    {
        if(dezes[i]>daugiausiai)
            daugiausiai=dezes[i];
    }
    return daugiausiai;
}

void isvesti(int n, int dezes[], int dezutes[], int dezesislikucio, int didziausias)
{
    ofstream fr(rezultatai);
    for(int i = 0; i < n; i++)
    {
        fr<<dezes[i]<<" "<<dezutes[i]<<endl;
    }
    fr<<dezesislikucio<<endl;
    fr<<didziausias<<endl;
    fr.close();
}
