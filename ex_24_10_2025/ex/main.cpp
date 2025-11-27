#include <stdio.h>

int grad(int a[101][101] , int n, int x)
{
    int s=0;
    for(int i=1;i<=n;i++)
        s+=a[x][i];
    return s;
}

int main()
{
    FILE *f=fopen("graf.in","r");
    FILE *g=fopen("graf.out","w");
    int a[101][101]={0}, n, x, y;
    fscanf(f,"%d",&n);
    while(!feof(f))
    {
        fscanf(f,"%d%d",&x,&y);
        a[x][y]=a[y][x]=1;
    }
    for(int i=1;i<=n;i++)
        fprintf(g,"%d ",grad(a,n,i));

}