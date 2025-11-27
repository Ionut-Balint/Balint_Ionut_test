#include <stdio.h>
#include <math.h>

int a[100][100], n, m=0;

struct muchii
{
    int x,y;
};

muchii v[100];

void citeste_matricea()
{
    FILE *f=fopen("graf.in","r");
    fscanf(f,"%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            fscanf(f,"%d",&a[i][j]);
}

void construieste_muchii()
{
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++)
            if(a[i][j])
            {
                v[++m].x=i;
                v[m].y=j;
            }
}

void trans_10_2(int x , int b[100])
{
    int k=0;
    while(x)
    {
        b[++k]=(x%2);
        x/=2;
    }
}

void afis_nr_2(int b[100])
{
    for(int i=1;i<=m;i++)
        printf("%d ",b[i]);
}

void afis_matr(int a[100][100])
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
}


void afis_vect(int x , int b[100])
{
    printf("Graful %d este : ",x+1);
    for(int i=1;i<=m;i++)
        if(b[i])
            printf("[%d , %d]  ", v[i].x, v[i].y);
}

void combinatii()
{
    int nr=pow(2,m);
    for(int i=0;i<nr;i++)
    {
        int b[100]={0}, matr[100][100]={0};
        trans_10_2(i,b);
        for(int j=1;j<=m;j++)
            if(b[j])
            {
                matr[v[j].x][v[j].y]=1;
                matr[v[j].y][v[j].x]=1;
            }
        afis_vect(i,b);
        printf("\n");
        printf("\n");
        afis_nr_2(b);
        printf("\n");
        printf("\n");
        afis_matr(matr);
        printf("\n");
    }
}

int main()
{
    citeste_matricea();
    construieste_muchii();
    combinatii();
}
