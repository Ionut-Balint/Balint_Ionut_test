#include <stdio.h>
#include <math.h>

struct arc
{
    int x,y;
};

int m=0;
arc a[100];

void arce(int n)
{
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++)
        {
            a[++m].x=i;
            a[m].y=j;
        }
}

void afiseaza_arce()
{
    for(int i=1;i<=m;i++)
        printf("[%d , %d] ",a[i].x, a[i].y);
}

void combinatii_bud()
{
    int c[1000];
    for(int i=0;i<pow(4,m);i++)
    {
        for(int j=1;j<=m;j++)
            c[j]=0;
        int aux=i, k=0;
        while(aux)
        {
            c[++k]=aux%4;
            aux/=4;
        }
        printf("\n");
        for(k=1;k<=m;k++)
            printf("%d",c[k]);
        printf("\n");
        for(k=1;k<=m;k++)
        {
            if(c[k]==1)
                printf("[%d , %d] ",a[k].x, a[k].y);
            if(c[k]==2)
                printf("[%d , %d] ",a[k].y, a[k].x);
            if(c[k]==3)
            {
                printf("[%d , %d] ",a[k].x, a[k].y);
                printf("[%d , %d] ",a[k].y, a[k].x);
            }
        }
    }

}
int main()
{
    int n;
    scanf("%d",&n);
    arce(n);
    //afiseaza_arce();
    combinatii_bud();
}
