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

int grad(int a[100][100] , int m , int x)
{
    int s=0;
    for(int i=1;i<=m;i++)
        s+=a[x][i];
    return s;
}

void grad_vf(int a[100][100] , int m , int & x)
{
    printf("Dati un varf pentru a-i afla gradul : ");
    scanf("%d",&x);
    printf("Gradul varfului %d este %d\n", x, grad(a,m,x));
}

void grad_max(int a[100][100] , int n , int m)
{
    int max=0, y;
    for(int i=1;i<=n;i++)
        {
            y=grad(a,m,i);
            if(y>max)
                max=y;
        }
    printf("Gradul maxim este %d\n",max);
}

void nod_terminal(int a[100][100] , int n , int m)
{
    printf("Nodurile terminale sunt : ");
    for(int i=1;i<=n;i++)
        if(grad(a,m,i)==1)
            printf("%d; ",i);
}

void noduri_adiacente(int a[100][100] , int n , int m , int & x)
{
    printf("\nDati nodul pentru care cautati nodurile adiacente : ");
    scanf("%d",&x);
    printf("Nodurile adiacente nodului %d sunt : ",x);
    for(int i=1;i<=m;i++)
        if(a[x][i]==1)
        {
            for(int j=1;j<=n;j++)
                if(a[j][i]==1 && j!=x)
                    printf("%d; ",j);
        }
}

int main()
{
    int a[100][100], n, m, x;
    citire_matrice(a,n,m);
    afisare_matrice(a,n,m);
    printf("Numarul de muchii este : %d\n",m);
    grad_vf(a,m,x);
    grad_max(a,n,m);
    nod_terminal(a,n,m);
    noduri_adiacente(a,n,m,x);
}
