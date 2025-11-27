#include <stdio.h>

FILE *f=fopen("graf.in","r");

void init(int st[100] , int k)
{
    st[k]=-1;
}

void succesor(int st[100] , int k , int n , int & as)
{
    if(st[k]<1)
    {
        st[k]++;
        as=1;
    }
    else
        as=0;
}

void valid(int st[100] , int k , int & ev)
{
    ev=1;
}

int solutie(int k , int n)
{
    return (k==n);
}

void afis_vector(int a[100] , int na)
{
    for(int i=1;i<=na;i++)
        printf("%d ",a[i]);
}

void tiparire(int st[100] , int n ,  int k , int a[100] , int b[100] , int & na , int & nb , int & x)
{
    x=1;
    int s=0;
    for(int i=1;i<=n;i++)
        s+=st[i];
    if(s==0 || s==n)
        x=0;
    if(x)
    {
        printf("\n\n");
        for(int i=1;i<=k;i++)
        {
            printf("%d ",st[i]);
            if(st[i]==0)
                b[++nb]=i;
            else
                a[++na]=i;
        }
        printf("\n\n");
        afis_vector(a,na);
        printf("\t");
        afis_vector(b,nb);
        printf("\n\n");
    }
}

void contstruieste_matrice(int n, int a[100] , int b[100] , int na, int nb, int x)
{
    if(x)
    {
        int matr[100][100]={0};
        for(int i=1;i<=na;i++)
            for(int j=1;j<=nb;j++)
                matr[a[i]][b[j]]=matr[b[j]][a[i]]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                printf("%d ",matr[i][j]);
            printf("\n");
        }
    }
}

void back_tracking(int n , int m[100][100])
{
    int k=1, as, ev, st[100];
    init(st,k);
    while(k!=0)
    {
        int a[100]={0}, b[100]={0}, na=0, nb=0, x;
        do
        {
            succesor(st,k,n,as);
            if(as)
                valid(st,k,ev);
        }
        while(!((!as)||(as&&ev)));
        if(as)
            if(solutie(k,n))
            {
                tiparire(st,n,k,a,b,na,nb,x);
                contstruieste_matrice(n,a,b,na,nb,x);
            }
            else
            {
                k++;
                init(st,k);
            }
        else
            k--;
    }
}

int main()
{
    int n, m[100][100];
    scanf("%d",&n);
    back_tracking(n,m);
}
