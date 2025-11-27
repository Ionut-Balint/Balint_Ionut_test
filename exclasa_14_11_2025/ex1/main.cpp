#include <stdio.h>

int c[100], nc;

void citire_matrice(int a[100][100] , int & n)
{
    FILE *f=fopen("graf.in","r");
    fscanf(f,"%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            fscanf(f,"%d",&a[i][j]);
}


void BF(int x , int a[100][100] , int n , int viz[100])
{
    int k=1;
    k++;
    c[1]=x;
    nc=1;
    int cap=1;
    viz[1]=k;
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

int grad(int x , int a[100][100] , int n)
{
    int s=0;
    for(int i=1;i<=n;i++)
        s+=a[x][i];
    return s;
}

void eulelian(int a[100][100] , int n)
{
    int m[100]={0}, k=1;
    for(int i=1;i<=n;i++)
        if(!grad(i,a,n))
            m[i]=1;
    while(!m[k] && k<=n)
        k++;
    if(k==n+1)
    {
        printf("Eulelian");
        return;
    }
    BF(k,a,n,m);
    for(int i=1;i<=n;i++)
        if(!m[i])
        {
            printf("Nu este eulelian");
            return;
        }
    for(int i=1;i<=n;i++)
        if(m[i]==2 && grad(i,a,n)%2==0)
        {
            printf("Nu este eulelian");
            return;
        }
    int b[100][100], vc=k;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            b[i][j]=a[i][j];
    printf("Ciclul eulelian este : %d",vc);
    while(grad(k,b,n)!=0)
    {
        for(int i=1;i<=n;i++)
            if(b[vc][i])
            {
                printf("->%d",i);
                b[vc][i]=b[i][vc]=0;
                vc=i;
                i=n+1;
            }
    }
    /*
    int vs[100], vsn=1, vs[1]=primul(a,n), ec=k, ns;
    while(k=primul(a,n))
    {
        int sv[100];
        sv[1]=k;
        ns=1;
        while(ec!=k || ns==1)
        {
            for(int i=1;i<=n;i++)
                if(b[ec][i])
                {
                    sv[++ns]=i;
                    b[ec][i]=b[i][ec]=0;
                    insereaza(vs,nsv,sv,ns,k);
                }
        }
    }
    for(int i=1;i<=nsv;i++)
        printf("->%d",vs[i]);
    */
}

int main()
{
    int a[100][100], n;
    citire_matrice(a,n);
    eulelian(a,n);
}
