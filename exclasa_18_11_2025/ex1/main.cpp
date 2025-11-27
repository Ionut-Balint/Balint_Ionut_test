#include <stdio.h>

void citire(int a[100][100] , int & n)
{
    FILE *f=fopen("graf.in","r");
    fscanf(f,"%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            fscanf(f,"%d",&a[i][j]);

}

int daca_turneu(int a[100][100] , int n)
{
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++)
            if(!((a[i][j] && !a[j][i])||(!a[i][j] && a[j][i])))
            return 0;
    return 1;
}


void insereaza(int d[100] , int & dn , int p , int x)
{
    for(int i=dn;i>=p;i--)
        d[i+1]=d[i];
    d[p]=x;
    dn++;
}

void turneu(int a[100][100] , int n)
{
    int d[100], dn=2, pres;
    d[1]=a[1][2]?1:2;
    d[2]=a[2][1]?1:2;
    for(int i=3;i<=n;i++)
    {
        if(a[i][d[1]])
            insereaza(d,dn,1,i);
        else
        {
            pres=0;//
            for(int j=2;j<=dn;j++)
            {
                if(a[d[j-1]][i] && a[i][d[j]])
                {
                    insereaza(d,dn,j,i);
                    pres=1;
                    break;
                }
            }
        }
        if(!pres)
            insereaza(d,dn,dn+1,i);
    }
    printf("Drumul elementar este : %d",d[1]);
    for(int i=2;i<=dn;i++)
        printf("->%d",d[i]);

}

int main()
{
    int a[100][100], n;
    citire(a,n);
    if(daca_turneu(a,n))
        turneu(a,n);
}
