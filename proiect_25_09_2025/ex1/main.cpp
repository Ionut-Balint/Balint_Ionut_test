#include <stdio.h>

int n, a[100][100], b[100][100], m=0;

struct muchii
{
    int x,y;
}v[100];

void citire_matrice()
{
    FILE *f=fopen("graf.in","r");
    fscanf(f,"%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            fscanf(f,"%d",&a[i][j]);
}

void afisare_matrice_adiacenta()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
    printf("\n");
}

void transformare()
{
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++)
            if(a[i][j])
            {
                b[i][++m]=1;
                b[j][m]=1;
            }
}

void afisare_matrice_incidenta()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            printf("%d ",b[i][j]);
        printf("\n");
    }
    printf("\n");
}

void transfer()
{
    int k=0;
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++)
            if(a[i][j])
            {
                v[++k].x=i;
                v[k].y=j;
            }
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
    afisare_matrice_adiacenta();
    transformare();
    afisare_matrice_incidenta();
    transfer();
    afisare_vector();
}
