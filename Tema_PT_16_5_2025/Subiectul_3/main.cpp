#include <stdio.h>
#include <math.h>

int verifica(int n)
{
    while(n)
    {
        if((n/10)%10>n%10)
            return 0;
        n/=10;
    }
    return 1;
}

int sumdiv(int n)
{
    int s=0;
    for(int i=2;i<sqrt(n);i++)
    {
        if(n%i==0)
        {
            s+=i;
            s+=n/i;
        }
    }
    if((int)sqrt(n)==sqrt(n))
        s+=(int)sqrt(n);
     if(s>n)
        return 1;
     else
        return 0;
}

void bubbleSort(int a[1001], int n)
{
    int pres;
    for (int i=1;i<=n-1;i++)
    {
        pres=0;
        for (int j=1;j<=n-i;j++)
        {
            if (a[j]>a[j+1])
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
    for(int i=n;i>=1;i--)
        if(v[i]%2==1)
        {
            pres=1;
            printf("%d ",v[i]);
        }
    if(!pres)
        printf("NU EXISTA");
    for(int i=1;i<=n;i++)
        s+=verifica(v[i]);
    printf("\n%d",s);
    for(int i=1;i<=n;i++)
    {
        if(sumdiv(v[i]))
            a[++k]=v[i];
    }
    bubbleSort(a,k);
    for(int i=1;i<=k;i++)
        fprintf(g,"%d ",a[i]);

}
