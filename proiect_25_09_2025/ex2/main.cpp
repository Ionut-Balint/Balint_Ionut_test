#include <stdio.h>

int n, m, a[100][100], b[100][100]={0};

struct muchii
{
    int x,y;
}v[100];

void citire_matrice()
{
    FILE *f=fopen("graf.in","r");
    fscanf(f,"%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            fscanf(f,"%d",&a[i][j]);
}

void afisare_matrice_incidenta()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
    printf("\n");
}

void transformare(int b[100][100])
{
    int xx,yy,pres,k;
    for(int i=1;i<=m;i++)
    {
        k=1, pres=0;
        while(k<=n)
        {
            if(a[k][i] && !pres)
            {
                xx=k;
                pres=k;
            }
            if(a[k][i] && pres!=k)
                yy=k;
            k++;
        }
        if(pres)
        {
            b[xx][yy]=1;
            b[yy][xx]=1;
            v[i].x=xx;
            v[i].y=yy;
        }

    }
}

void afisare_matrice_adiacenta()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            printf("%d ",b[i][j]);
        printf("\n");
    }
    printf("\n");
}

void afisare_vector()
{
    for(int i=1;i<=m;i++)
        printf("[%d;%d]   ",v[i].x,v[i].y);
    printf("\n");
}

int main()
{
    citire_matrice();
    afisare_matrice_incidenta();
    transformare(b);
    afisare_matrice_adiacenta();
    afisare_vector();
}
