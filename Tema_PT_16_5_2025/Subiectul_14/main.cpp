#include <stdio.h>
#include <math.h>

void maxim(int v[20][20] , int n)
{
    int max=v[1][1];
    for(int i=2;i<=n;i++)
        if(v[i][i]>max)
            max=v[i][i];
    printf("%d ",max);
}

void minim(int v[20][20] , int n)
{
    int min=v[1][n];
    for(int i=2;i<=n;i++)
        if(v[i][n-i+1]<min)
            min=v[i][n-i+1];
    printf("%d ",min);
}

int patrat_perfect(int n)
{
    if(sqrt(n)==(int)sqrt(n))
        return 1;
    return 0;
}

int main()
{
    int n, v[20][20], pres;
    FILE *f=fopen("atestat.in","r");
    FILE *g=fopen("atestat.out","w");
    fscanf(f,"%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            fscanf(f,"%d",&v[i][j]);
            if(patrat_perfect(v[i][j]))
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
        {
            printf("%d ",v[i][j]);
        }
        printf("\n");
    }
    maxim(v,n);
    minim(v,n);
}
