#include <stdio.h>
#include <math.h>

int nrdiv(int n)
{
    int s=0;
    for(int i=1;i<sqrt(n);i++)
        if(n%i==0)
            s+=2;
    if(sqrt(n)==(int)sqrt(n))
        s++;
    return s;
}

void inv(int & n)
{
    int inv=0;
    while(n)
    {
        inv=inv*10+n%10;
        n/=10;
    }
    n=inv;
}

void sorteaza(int v[1001] , int n)
{
    int pres;
    do
    {
        pres=1;
        for(int i=1;i<=n-1;i++)
            if(v[i]<v[i+1])
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
    int n, v[1001], pres=0, s=0;
    FILE *f=fopen("atestat.in","r");
    FILE *g=fopen("atestat.out","w");
    fscanf(f,"%d",&n);
    for(int i=1;i<=n;i++)
    {
        fscanf(f,"%d",&v[i]);
        if(v[i]%nrdiv(v[i])==0)
            s++;
    }
    for(int i=n-1;i>=1;i--)
        if(v[i]%v[n]==0)
        {
            pres=1;
            printf("%d ",v[i]);
        }
    if(!pres)
        printf("NU EXISTA");
    printf("\n%d",s);
    for(int i=1;i<=n;i++)
        inv(v[i]);
    sorteaza(v,n);
    for(int i=1;i<=n;i++)
        fprintf(g,"%d ",v[i]);

}
