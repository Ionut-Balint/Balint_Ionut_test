#include <stdio.h>

int produs(int v[20][20] , int n)
{
    int p=1;
    for(int i=1;i<=n;i++)
    {
        if(v[1][i]!=0)
            p*=(v[1][i]%10);
        if(p>=10)
            p=p%10;
    }
    for(int i=2;i<=n;i++)
    {
        if(v[i][n]!=0)
            p*=(v[i][n]%10);
        if(p>=10)
            p=p%10;
    }
    for(int i=n-1;i>=1;i--)
    {
        if(v[n][i]!=0)
            p*=(v[n][i]%10);
        if(p>=10)
            p=p%10;
    }
    for(int i=n-1;i>=2;i--)
    {
        if(v[i][1]!=0)
            p*=(v[i][1]%10);
        if(p>=10)
            p=p%10;
    }
    return p;
}

int prim_ultim(int n)
{
    int u=n%10;
    while(n>9)
        n/=10;
    if(n==u)
        return 1;
    return 0;
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
            if(prim_ultim(v[i][j]))
            {
                fprintf(g,"%d ",v[i][j]);
                pres=1;
            }
        }
        printf("\n");
    }
    if(!pres)
        fprintf(g,"NU EXISTA");
    printf("%d ", produs(v,n));

}
