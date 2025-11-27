#include <stdio.h>
#include <math.h>

int n, m=0, tot;

struct muchie
{
    int x , y;
};

muchie v[100];

void trans_10_3sp(int n , int b[100])
{
    int i=0;
    while(n)
    {
        b[++i]=(n%3);
        n/=3;
    }
}

void construieste_muchii(int n)
{
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++)
        {
            v[++m].x=i;
            v[m].y=j;
        }
}

void construieste_matrice(int b[100] , int a[100][100])
{
    for(int i=1;i<=m;i++)
    {
        if(b[i]==0)
            a[v[i].x][v[i].y]=1;
        if(b[i]==1)
            a[v[i].y][v[i].x]=1;
        if(b[i]==2)
        {
            a[v[i].x][v[i].y]=1;
            a[v[i].y][v[i].x]=1;
        }
    }
}

void afiseaza_graf(int x , int b[100])
{
    printf("Graful %d este : ",x+1);
    for(int i=1;i<=m;i++)
    {
        if(b[i]==0)
            printf("[%d ; %d]  ",v[i].x, v[i].y);
        if(b[i]==1)
            printf("[%d ; %d]  ",v[i].y, v[i].x);
        if(b[i]==2)
        {
            printf("[%d ; %d]  ",v[i].x, v[i].y);
            printf("[%d ; %d]  ",v[i].y, v[i].x);
        }
    }
    printf("\n");
}

void afisare_matrice(int a[100][100])
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
    printf("\n");
}


int main()
{
    scanf("%d",&n);
    tot=pow(3,(n*(n-1))/2);
    construieste_muchii(n);
    for(int i=0;i<tot;i++)
    {
        int b[100]={0}, a[100][100]={0};
        trans_10_3sp(i,b);
        construieste_matrice(b,a);
        afiseaza_graf(i,b);
        afisare_matrice(a);
    }
}
