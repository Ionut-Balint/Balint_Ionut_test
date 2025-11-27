#include <stdio.h>
#include <math.h>

int sumdiv(int n)
{
    int s=0;
    for(int i=1;i<sqrt(n);i++)
    {
        if(n%i==0)
        {
            s+=i;
            s+=n/i;
        }
    }
    if(sqrt(n)==(int)sqrt(n))
        s+=(int)sqrt(n);
    return s;
}

int verifica_paritate(int n)
{
    int par=0, imp=0;
    while(n)
    {
    if((n%10)%2==0)
        par=1;
    else
        imp=1;
    n/=10;
    }
    if(par==imp)
        return 0;
    else
        return 1;
}

void bubbleSort(int a[1001], int n)
{
    int pres;
    for (int i=1;i<=n-1;i++)
    {
        pres=0;
        for (int j=1;j<=n-i;j++)
        {
            if (a[j]<a[j+1])
            {
                int aux=a[j];
                a[j]=a[j+1];
                a[j+1]=aux;
                pres=1;
            }
        }
        if (!pres)
            break;
    }
}

int main()
{

    FILE *f=fopen("atestat.in","r");
    FILE *g=fopen("atestat.out","w");
    int n, v[1001], pres=0, s=0, k=0, a[1001];
    fscanf(f,"%d",&n);
    for(int i=1;i<=n;i++)
    {
        fscanf(f,"%d",&v[i]);
        if(v[i]>=10&&v[i]<=99)
        {
            pres=1;
            printf("%d ",v[i]);
        }
    }
    if(!pres)
        printf("NU EXISTA");
    for(int i=1;i<=n;i++)
    {
        if(sumdiv(v[i])%2==0)
            s++;
    }
    printf("\n%d",s);
    for(int i=1;i<=n;i++)
    {
        if(verifica_paritate(v[i]))
            a[++k]=v[i];
    }
    bubbleSort(a,k);
    for(int i=1;i<=k;i++)
        fprintf(g,"%d ",a[i]);
}
