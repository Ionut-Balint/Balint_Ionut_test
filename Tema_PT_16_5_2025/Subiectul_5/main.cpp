#include <stdio.h>
#include <math.h>

int sumdiv(int n)
{
    int s=0;
    for(int i=1;i<sqrt(n);i++)
        if(n%i==0)
        {
            s+=i;
            s+=n/i;
        }
    if(sqrt(n)==(int)sqrt(n))
        s+=(int)sqrt(n);
    return s;
}

int verifica_desc(int n)
{
    if(n<=9)
        return 0;
    while(n)
    {
        if(n%10>(n/10)%10 && n>=10)
            return 0;
        n/=10;
    }
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
    int n, v[1001], pres=0, nd=0, k=0, a[1001];
    FILE *f=fopen("atestat.in","r");
    FILE *g=fopen("atestat.out","w");
    fscanf(f,"%d",&n);
    for(int i=1;i<=n;i++)
    {
        fscanf(f,"%d",&v[i]);
        if(v[i]%10==(v[i]/10)%10)
        {
            printf("%d ",v[i]);
            pres=1;
        }
        if(sumdiv(v[i])%2==1)
            nd+=1;
        if(verifica_desc(v[i]))
            a[++k]=v[i];

    }
    printf("\n");
    if(pres==0)
        printf("NU EXISTA\n");
    printf("%d\n",nd);
    bubbleSort(a,k);
    for(int i=1;i<=k;i++)
        fprintf(g,"%d ",a[i]);


}
