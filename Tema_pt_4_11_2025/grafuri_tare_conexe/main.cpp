#include <stdio.h>
#include <math.h>

FILE*f=fopen("graf.in", "r");

void citire(int a[100][100], int &n)
{
    fscanf(f,"%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            fscanf(f,"%d",&a[i][j]);
}

void BF(int a[100][100], int n, int p, int c[100], int &nc , int viz[100])
{
    int cap=1;
    c[1]=p;
    nc=1;
    viz[p]=1;
    while(cap<=nc)
    {
        for(int i=1;i<=n;i++)
            if(a[c[cap]][i] && !viz[i])
            {
                viz[i]=1;
                c[++nc]=i;
            }
        cap++;
    }
}
int ex_drum(int p, int s, int ad[100][100], int n)
{

    if(p == s)
        return 0;
    int vs[100], ns, viz[100]={0};
    BF(ad, n, p, vs, ns,viz);
    for(int i=1;i<=ns;i++)
        if(vs[i]==s)
            return 1;
    return 0;
}

void afis_matr(int a[100][100], int nctc, int ad[100][100], int n)
{
    int b[100][100] = {0};
    for(int i=1;i<=nctc;i++)
        for(int j=1;j<=nctc;j++)
            b[i][j]=ex_drum(a[i][1], a[j][1], ad, n);
    for(int i=1; i <= nctc; i++)
    {
        for(int j=1; j <= nctc; j++)
            printf("%d ", b[i][j]);
        printf("\n");
    }
}

int cauta(int viz[100], int n)
{
    for(int i=1;i<=n;i++)
        if(viz[i]==0)
            return i;
    return 0;
}

void sterge(int v[100] , int x , int & n)
{
    for(int i=x;i<n;i++)
        v[i]=v[i+1];
    n--;
}

void comp_con(int a[100][100], int n)
{
    int b[100][100], nctc=0, viz[100]={0}, p;
    while(p=cauta(viz, n))
    {
        nctc++;
        BF(a, n, p, b[nctc], b[nctc][0],viz);
        for(int i=2;i<=b[nctc][0]; i++)
            for(int j=1;j<=b[nctc][0];j++)
                if(j!=i && !ex_drum(b[nctc][i], b[nctc][j], a, n))
                    sterge(b[nctc], i, b[nctc][0]);
    }
    afis_matr(b, nctc, a, n);
}

int main()
{
    int a[100][100], n;
    citire(a, n);
    comp_con(a, n);
}