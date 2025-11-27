#include <stdio.h>
#include <math.h>

int sum_d1(int v[20][20] , int n)
{
    int s=0;
    for(int i=1;i<=n;i++)
        s+=v[i][i];
    return s;
}

int sum_d2(int v[20][20] , int n)
{
    int s=0;
    for(int i=1;i<=n;i++)
        s+=v[i][n-i+1];
    return s;
}

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
            if(v[i][j]==sumdiv(v[i][j]))
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
    printf("%d %d", sum_d1(v,n), sum_d2(v,n));

}
