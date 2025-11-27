#include <stdio.h>

void citire_matrice(int a[100][100] , int & n)
{
    FILE *f=fopen("graf.in","r");
    fscanf(f,"%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            fscanf(f,"%d",&a[i][j]);
}

void roy_warshall(int a[100][100] , int n)
{
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(a[i][j]==0 && i!=k && j!=k)
                    a[i][j]=a[i][k]*a[k][j];
}

void afisare_matrice(int a[100][100] , int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
}

int main()
{
    int a[100][100], n;
    citire_matrice(a,n);
    afisare_matrice(a,n);
    printf("\n");
    roy_warshall(a,n);
    afisare_matrice(a,n);
}
