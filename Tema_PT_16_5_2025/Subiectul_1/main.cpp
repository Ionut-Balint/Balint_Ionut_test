#include <stdio.h>
int descompunere(int n)
{
    int d=2, nr=0;
    while(n!=1)
    {
        if(n%d==0)
        {
            nr++;
            while(n%d==0)
                n/=d;
        }
        else
            d++;
    }
    return nr;
}

int invers(int n)
{
    int nn=0;
    while(n)
    {
        nn=nn*10+n%10;
        n/=10;
    }
    return nn;
}

int palindrom(int n)
{
    if(n==invers(n))
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
    int n, v[1001], pres=0, s=0, a[1001], d=0;
    fscanf(f,"%d",&n);
    for(int i=1;i<=n;i++)
    {
        fscanf(f,"%d",&v[i]);
        if(v[i]%2==0)
        {
            pres=1;
            printf("%d ",v[i]);
        }
    }
    if(pres==0)
        printf("NU EXISTA");
    for(int i=1;i<=n;i++)
        if(descompunere(v[i])>=2)
            s++;
    printf("\n%d",s);
    for(int i=1;i<=n;i++)
    {
        if(palindrom(v[i]))
            a[++d]=v[i];
    }
    bubbleSort(a,d);
    for(int i=d;i>=1;i--)
        fprintf(g,"%d ",a[i]);
}
