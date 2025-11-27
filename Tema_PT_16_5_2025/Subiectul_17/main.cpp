#include <stdio.h>

int sum_pe_diagonala(int v[20][20] , int n)
{
    int s=0;
    for(int i=1;i<=n-1;i++)
        for(int j=1;j<=n-i;j++)
            s+=v[i][j];
    return s;
}

int sum_sub_diagonala(int v[20][20] , int n)
{
    int s=0;
    for(int i=2;i<=n;i++)
        for(int j=n-i+2;j<=n;j++)
            s+=v[i][j];
    return s;
}

int verifica(int n)
{
    while(n>=10)
    {
        if((n/10)%10<n%10)
            return 0;
        n/=10;
    }
    return 1;
}

int main()
{
    int n, v[20][20], pres=0;
    FILE *f=fopen("atestat.in","r");
    FILE *g=fopen("atestat.out","w");
    fscanf(f,"%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            fscanf(f,"%d",&v[i][j]);
        }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            printf("%d ",v[i][j]);
            if(verifica(v[i][j]))
            {
                fprintf(g,"%d ",v[i][j]);
                pres=1;
            }
        }
        printf("\n");
    }
    if(!pres)
        fprintf(g,"NU EXISTA");
    printf("\n%d %d",sum_pe_diagonala(v,n), sum_sub_diagonala(v,n));
}
