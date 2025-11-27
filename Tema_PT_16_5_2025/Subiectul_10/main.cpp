#include <stdio.h>
#include <math.h>

int sumdivpar(int n)
{
    int s=0;
    for(int i=1;i<sqrt(n);i++)
        if(n%i==0)
        {
            if(i%2==0)
                s+=i;
            if((n/i)%2==0)
                s+=n/i;
        }
    if(sqrt(n)==(int)sqrt(n) && (int)sqrt(n)%2==0)
        s+=(int)sqrt(n);
    return s;
}

int verifica(int n)
{
    while(n/10)
    {
        if(n%10!=(n/10)%10)
            return 0;
        n/=10;
    }
    return 1;
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
    int n, v[1001], pres=0, s=0, a[1001], k=0;;
    FILE *f=fopen("atestat.in","r");
    FILE *g=fopen("atestat.out","w");
    fscanf(f,"%d",&n);
    for(int i=1;i<=n;i++)
    {
        fscanf(f,"%d",&v[i]);
        if(v[i]<=99)
        {
            printf("%d ",v[i]);
            pres=1;
        }
        if(sumdivpar(v[i]) && sumdivpar(v[i])%n==0)
            s++;
        if(verifica(v[i]))
            a[++k]=v[i];
    }
    if(!pres)
        printf("NU EXISTA");
    printf("\n%d",s);
    sorteaza(a,k);
    for(int i=1;i<=k;i++)
        fprintf(g,"%d ",a[i]);
}
