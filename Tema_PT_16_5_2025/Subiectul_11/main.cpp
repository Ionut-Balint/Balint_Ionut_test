#include <stdio.h>
#include <math.h>

int prim(int n)
{
    if(n<2)
        return 0;
    if(n<4)
        return 1;
    if(n%2==0)
        return 0;
    for(int i=3;i<=sqrt(n);i+=2)
        if(n%i==0)
            return 0;
    return 1;
}

int main()
{
    int n, v[20][20], s, pres=0;
    FILE *f=fopen("atestat.in","r");
    FILE *g=fopen("atestat.out","w");
    fscanf(f,"%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            fscanf(f,"%d",&v[i][j]);
            if(prim(v[i][j]))
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
    for(int i=2;i<=n;i+=2)
    {
        s=0;
        for(int j=1;j<=n;j++)
            s+=v[i][j];
        printf("%d ",s);
    }
}
