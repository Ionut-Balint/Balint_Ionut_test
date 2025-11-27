#include <stdio.h>

int a[100][100], n, viz[100]={0}, k=0, p, c[100], nc;

void citire_matrice(int a[100][100] , int & n)
{
    FILE *f=fopen("graf.in","r");
    fscanf(f,"%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            fscanf(f,"%d",&a[i][j]);
}

int cauta(int viz[100] , int n)
{
    for(int i=1;i<=n;i++)
        if(!viz[i])
            return i;
    return 0;
}
/*
void BF(int a[100][100] , int n , int p , int c[100] , int &nc , int viz[100] , int &k)
{
    k++;
    c[1]=p;
    nc=1;
    int cap=1;
    viz[p]=k;
    while(cap<=nc)
    {
        viz[c[cap]]=k;
        for(int i=1;i<=n;i++)
            if(a[c[cap]][i]==1 && !viz[i])
            {
                viz[i]=k;
                c[++nc]=i;
            }
        cap++;
    }
}
*/

void BF()
{
    k++;
    c[1]=p;
    nc=1;
    int cap=1;
    viz[p]=k;
    while(cap<=nc)
    {
        viz[c[cap]]=k;
        for(int i=1;i<=n;i++)
            if(a[c[cap]][i]==1 && !viz[i])
            {
                viz[i]=k;
                c[++nc]=i;
            }
        cap++;
    }
}

int main()
{
    //int a[100][100], n, viz[100]={0}, k=0, p, c[100], nc;
    citire_matrice(a,n);
    while(p=cauta(viz,n))
    {
        //BF(a,n,p,c,nc,viz,k);
        BF();
        printf("Componenta %d este formata din vf : ",k);
        for(int i=1;i<=nc;i++)
            printf("%d ",c[i]);
        printf("\n");
    }
}
