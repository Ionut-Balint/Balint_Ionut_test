#include <stdio.h>
#include <math.h>

int prim(int n)
{
    if(n==0 || n==1)
        return 0;
    if(n<4)
        return 1;
    if(n%2==0)
        return 0;
    for(int i=3;i<=sqrt(n);i+=2)
        if(n%i==0)
            return 0;
    return 1;
}

int verifica(int n)
{
    int ni=0, np=0;
    while(n)
    {
        if((n%10)%2==0)
            np++;
        else
            ni++;
        n/=10;
    }
    if(ni==np)
        return 1;
    return 0;

}

void sorteaza(int v[1001] , int n)
{
    int pres;
    do
    {
        pres=1;
        for(int i=1;i<=n-1;i++)
            if(v[i]>v[i+1])
            {
                int aux=v[i];
                v[i]=v[i+1];
                v[i+1]=aux;
                pres=0;
            }
    }
    while(!pres);
}

int main()
{
    int n, v[1001], pres=0, s=0, k=0, a[1001];
    FILE *f=fopen("atestat.in","r");
    FILE *g=fopen("atestat.out","w");
    fscanf(f,"%d",&n);
    for(int i=1;i<=n;i++)
    {
        fscanf(f,"%d",&v[i]);
        s+=prim(v[i]);
        if(verifica(v[i]))
            a[++k]=v[i];
    }
    for(int i=n;i>=1;i--)
        if(v[i]>=10)
        {
            printf("%d ", v[i]);
            pres=1;
        }
    if(!pres)
        printf("NU EXISTA");
    printf("\n%d",s);
    sorteaza(a,k);
    for(int i=1;i<=k;i++)
        fprintf(g,"%d ",a[i]);
}
