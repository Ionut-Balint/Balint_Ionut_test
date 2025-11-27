#include <stdio.h>
int main()
{
    int n, k, a[101][101];
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        int s=i*k+i-1;
        for(int j=1;j<=n;j++)
        {
            a[i][j]=s;
            s--;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
}
