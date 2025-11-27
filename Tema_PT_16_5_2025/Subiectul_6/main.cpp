#include <stdio.h>
#include <math.h>

int sumdiv(int n)
{
    if(n==0 || n==1)
        return 0;
    int s=1;
    for(int i=2;i<sqrt(n);i++)
        if(n%i==0)
        {
            s+=i;
            s+=n/i;
        }
    if(sqrt(n)==(int)sqrt(n))
        s+=(int)sqrt(n);
    return s;
}

int palindrom(int n)
{
    int cn=n;
    int inv=0;
    while(n)
    {
        inv=inv*10+n%10;
        n/=10;
    }
    if(inv==cn)
        return 1;
    return 0;
}

void bubblesort(int a[1001] , int n)
{
    int pres;
    do
    {
        pres=1;
        for(int i=1;i<=n-1;i++)
            if(a[i]>a[i+1])
            {
                int aux=a[i];
                a[i]=a[i+1];
                a[i+1]=aux;
                pres=0;
            }
    }
    while(!pres);
}

int main()
{
    int n, a[1001], pres=0, nr=0, k=0, v[1001];
    FILE *f=fopen("atestat.in","r");
    FILE *g=fopen("atestat.out","w");
    fscanf(f,"%d",&n);
    for(int i=1;i<=n;i++)
    {
        fscanf(f,"%d",&a[i]);
        if(sumdiv(a[i])==a[i])
            nr++;
        if(palindrom(a[i]))
            v[++k]=a[i];
    }
    for(int i=n;i>=1;i--)
        if(a[i]>=10&&a[i]<=99)
        {
            printf("%d ",a[i]);
            pres=1;
        }
    if(!pres)
        printf("NU EXISTA");
    printf("\n%d",nr);
    bubblesort(v,k);
    for(int i=1;i<=k;i++)
        fprintf(g,"%d ",v[i]);
}
