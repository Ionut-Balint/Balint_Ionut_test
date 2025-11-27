#include <stdio.h>

const int INF=1000000000;

void citire_matrice(int a[100][100] , int & n)
{
    FILE*f=fopen("graf.in","r");
    fscanf(f,"%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            fscanf(f,"%d",&a[i][j]);
            if(a[i][j]==0 && i!=j)
                a[i][j]=INF;
        }
}

void dijkstra(int c[100][100] , int n , int start , int s[100])
{
    for(int i=1;i<=n;i++)
        s[i]=c[start][i];
    int viz[100]={0}, k=1;
    viz[start]=1;
    while(k<=n)
    {
        int min=INF, vfmin;
        for(int i=1;i<=n;i++)
            if(!viz[i] && s[i]<min)
            {
                min=s[i];
                vfmin=i;
            }
        viz[vfmin]=1;
        for(int i=1;i<=n;i++)
            if(!viz[i] && s[i]>s[vfmin]+c[vfmin][i])
                    s[i]=s[vfmin]+c[vfmin][i];
        k++;
    }

}

void drum(int start , int stop , int s[100] , int n , int ad[100][100])
{
    if(start==stop)
        printf("%d",start);
    else
        for(int i=1;i<=n;i++)
            if(i!=stop && s[stop]-ad[stop][i]==s[i])
            {
                drum(start,i,s,n,ad);
                printf("->%d",stop);
                return;
            }
}

int main()
{
    int a[100][100], n, start=1, stop=7,  s[100];
    citire_matrice(a,n);
    dijkstra(a,n,start,s);
    for(int i=1;i<=n;i++)
        printf("%d ",s[i]);
    drum(start,stop,s,n,a);
}
