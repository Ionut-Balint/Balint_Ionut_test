#include <stdio.h>

void pro_ultim(int v[20][20] , int n , int i)
{
    int pr=1;
    for(int j=1;j<=n;j++)
    {
        pr*=(v[j][i]%10);
        if(pr>=10)
            pr=pr%10;
    }
    printf("%d ",pr);
}

int palindrom(int n)
{
    int inv=0, cn=n;
    while(n)
    {
        inv=inv*10+n%10;
        n/=10;
    }
    if(cn==inv)
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
            if(palindrom(v[i][j]))
            {
                fprintf(g,"%d ",v[i][j]);
                pres=1;
            }
        }
    if(!pres)
        fprintf(g,"NU EXISTA");
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            printf("%d ",v[i][j]);
        printf("\n");
    }
    for(int i=1;i<=n;i+=2)
        pro_ultim(v,n,i);
}
