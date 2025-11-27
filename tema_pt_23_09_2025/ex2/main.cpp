#include <stdio.h>

FILE *f=fopen("graf.in","r");

void citire_matrice(int a[100][100] , int & n , int & m)
{
    fscanf(f,"%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            fscanf(f,"%d",&a[i][j]);
}

void afisare_matrice(int a[100][100] , int n , int m)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
}

int grad_int(int a[100][100] , int m , int x)
{
    int s=0;
    for(int i=1;i<=m;i++)
        if(a[x][i]==1)
            s+=1;
    return s;
}

void grad_intern(int a[100][100] , int m , int & x)
{
    printf("Dati un nod pentru a-i afla gradul intern : ");
    scanf("%d",&x);
    printf("Gradul intern al nodului %d este %d\n",x,grad_int(a,m,x));
}

int grad_ext(int a[100][100] , int m , int x)
{
    int s=0;
    for(int i=1;i<=m;i++)
        if(a[x][i]==-1)
            s+=1;
    return s;
}

void grad_extern(int a[100][100] , int m , int & x)
{
    printf("Dati un nod pentru a-i afla gradul extern : ");
    scanf("%d",&x);
    printf("Gradul extern al nodului %d este %d\n",x,grad_ext(a,m,x));
}

void nod_sursa(int a[100][100] , int n , int m)
{
    printf("Nodurile sursa sunt : ");
    for(int i=1;i<=n;i++)
        if(grad_ext(a,m,i)==n-1)
            printf("%d; ",i);
}

void nod_destinatie(int a[100][100] , int n , int m)
{
    printf("\nNodurile destinatie sunt : ");
    for(int i=1;i<=n;i++)
        if(grad_int(a,m,i)==n-1)
            printf("%d; ",i);
}

void noduri_adiacente(int a[100][100] , int n , int m , int & x)
{
    printf("\nDati nodul pentru care cautati nodurile adiacente : ");
    scanf("%d",&x);
    printf("Nodurile adiacente nodului %d sunt : ",x);
    for(int i=1;i<=m;i++)
    {
        if(a[x][i]==1)
        {
            for(int j=1;j<=n;j++)
                if(a[j][i]==-1 && j!=x)
                    printf("%d; ",j);
        }

        if(a[x][i]==-1)
        {
            for(int j=1;j<=n;j++)
                if(a[j][i]==1 && j!=x)
                    printf("%d; ",j);
        }
    }
}

int main()
{
    int a[100][100], n, m, x;
    citire_matrice(a,n,m);
    afisare_matrice(a,n,m);
    grad_intern(a,m,x);
    grad_extern(a,m,x);
    nod_sursa(a,n,m);
    nod_destinatie(a,n,m);
    noduri_adiacente(a,n,m,x);
}
