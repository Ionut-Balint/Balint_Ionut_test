#include <stdio.h>

void citire_matrice(int a[100][100] , int &n)
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

void DF_r(int a[100][100] , int n , int st[100] , int k , int df[100] , int &ndf , int viz[100] , int x)
{
    for(int i=1;i<=n;i++)
        if(a[st[k-1]][i] && ! viz[i])
        {
            viz[i]=x;
            df[++ndf]=i;
            st[k]=i;
            DF_r(a,n,st,k+1,df,ndf,viz,x);
        }
}


void DF(int a[100][100] , int n , int p , int df[100] , int & ndf ,  int viz[100] , int & k)
{
    int st[100];
    k++;
    ndf=0;
    st[1]=p;
    viz[p]=k;
    df[++ndf]=p;
    DF_r(a,n,st,2,df,ndf,viz,k);
}

int main()
{
    int a[100][100], n, p, df[100], ndf, viz[100]={0}, k=0;
    citire_matrice(a,n);
    while(p=cauta(viz,n))
    {
        DF(a,n,p,df,ndf,viz,k);
        printf("Componenta %d este formata din : ",k);
        for(int i=1;i<=ndf;i++)
            printf("%d ",df[i]);
        //for(int i=1;i<=n;i++)
            //if(viz[i])
                //printf("%d ",i);
        printf("\n");
    }
}
