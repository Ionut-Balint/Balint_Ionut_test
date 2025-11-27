#include <stdio.h>
#include <math.h>

void citire_matrice(int a[100][100] , int & n)
{
    FILE *f=fopen("graf.in","r");
    fscanf(f,"%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            fscanf(f,"%d",&a[i][j]);
}

void creeaza_vect(int x , int n , int baza , int v[100])
{
    int k=n;
    while(x)
    {
        v[k--]=x%baza;
        x/=baza;
    }
}

void copiaza_matrice(int matr[100][100] , int a[100][100] , int n)
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            matr[i][j]=a[i][j];
}

void sterge_nod(int a[100][100] , int & n , int x)
{
    for(int i=x;i<n;i++)
        for(int j=1;j<=n;j++)
        {
            a[i][j]=a[i+1][j];
            a[j][i]=a[j][i+1];
        }
    n--;
    for(int i=1;i<=n;i++)
        a[i][i]=0;
}


/*void sterge_nod(int a[100][100] , int & n , int x)
{
    for(int i=x;i<n;i++)
        for(int j=1;j<=n;j++)
            a[i][j]=a[i+1][j];
    for(int i=x;i<n;i++)
        for(int j=1;j<=n;j++)
            a[j][i]=a[j][i+1];
    n--;
    for(int i=1;i<=n;i++)
        a[i][i]=0;
}*/

void afisare_matr(int matr[100][100] , int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            printf("%d ",matr[i][j]);
        printf("\n");
    }
}

void afisare_vect(int v[100] , int n)
{
    for(int i=1;i<=n;i++)
        printf("%d ",v[i]);
}

void combinatii(int a[100][100] , int n , int baza)
{
    int nr=pow(2,n);
    int matr[100][100];
    for(int k=0;k<nr-1;k++)
    {
        int v[100]={0}, num=n;
        copiaza_matrice(matr,a,n);
        creeaza_vect(k,n,2,v);
        printf("Nodurile sterse din graf pentru a avea subgraful %d sunt : ",k+1);
        for(int i=n;i>=1;i--)
            if(v[i])
            {
                sterge_nod(matr,num,i);
                //printf("%d ",i);
            }
        for(int i=1;i<=n;i++)
            if(v[i])
                printf("%d ",i);
        printf("\nSubgraful %d este : \n",k+1);
        printf("\n");
        afisare_vect(v,n);
        printf("\n\n");
        afisare_matr(matr,num);
        printf("\n");
    }
}

int main()
{
    int n, a[100][100];
    citire_matrice(a,n);
    combinatii(a,n,2);
}
