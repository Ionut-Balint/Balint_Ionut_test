#include <stdio.h>
#include <math.h>

int patrat_perfect(int n)
{
    if(sqrt(n)==(int)sqrt(n))
        return 1;
    return 0;
}

int cif_zero(int n)
{
    while(n)
    {
        if(n%10==0)
            return 1;
        n/=10;
    }
    return 0;
}

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
    int n, v[1001], pres=0, s=0, a[1001], k=0;
    fscanf(f,"%d",&n);
    for(int i=1;i<=n;i++)
        fscanf(f,"%d",&v[i]);
    for(int i=1;i<=n;i++)
    {
        if(patrat_perfect(v[i]))
        {
            pres=1;
            printf("%d ",v[i]);
        }
        s+=cif_zero(v[i]);
        if(sumdiv(v[i])%2==0)
            a[++k]=v[i];
    }
    if(!pres)
        printf("NU EXISTA");
    printf("\n%d",s);
    bubbleSort(a,k);
    for(int i=1;i<=k;i++)
        fprintf(g,"%d ",a[i]);
}
