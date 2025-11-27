#include <stdio.h>
#include <math.h>

int trans_10_2(int n)
{
    int nq=0, p10=1;
    while(n)
    {
        nq+=(n%2)*p10;
        n/=2;
        p10*=10;
    }
    return nq;
}


void trans_10_2sp(int n , int b[100])
{
    int i=1;
    while(n)
    {
        b[i]=(n%2);
        n/=2;
        i++;
    }
}


/*
void scrie(int b[100] , int n , int nr)
{
    while(n)
    {
        b[nr]=n%10;
        n/=10;
        nr--;
    }
    if(nr>0)
        for(int i=nr;i>0;i--)
            b[i]=0;
}
*/

void scrie2(int b[100] , int n , int x)
{
    int i=1;
    while(n)
    {
        b[i]=n%10;
        n/=10;
        i++;
    }
    if(i<=x)
        while(i<=x)
        {
            b[i]=0;
            i++;

        }
}

int main()
{
    FILE *g=fopen("ex.out","w");
    int n, a=1;
    scanf("%d",&n);
    int nr=(n*(n-1))/2;

    int xi[100]={0};
    //scrie2(xi,trans_10_2(32767),nr);
    trans_10_2sp(32767,xi);

    struct nod
    {
        int x , y;
    };
    nod v[nr+1];
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++)
        {
            v[a].x=i;
            v[a].y=j;
            a++;
        }
    a=(int)pow(2,nr);
    for(int i=0;i<a;i++)
    {
        fprintf(g,"Graful %d : ",i+1);
        printf("Graful %d : ",i+1);
        int b[100]={0};
        //scrie2(b,trans_10_2(i),nr);
        trans_10_2sp(i,b);
        for(int j=1;j<=nr;j++)
        {
            printf("%d ",b[j]);
            if(j==nr)
                printf("\n");
        }
            for(int j=1;j<=nr;j++)
                if(b[j])
                {
                    printf("(%d , %d)  ", v[j].x, v[j].y);
                    fprintf(g,"(%d , %d)  ", v[j].x, v[j].y);
                }
        printf("\n");
        fprintf(g,"\n");
    }
}
