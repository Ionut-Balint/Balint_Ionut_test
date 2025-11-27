#include <stdio.h>

void citire_matrice(int a[100][100] , int & n)
{
    FILE *f=fopen("graf.in","r");
    fscanf(f,"%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            fscanf(f,"%d",&a[i][j]);
}

void init(int st[100] , int k)
{
    st[k]=0;
}

void succesor(int st[100] , int k , int n , int & as)
{
    if(st[k]<n)
    {
        as=1;
        st[k]++;
    }
    else
        as=0;
}

void valid(int st[100] , int k , int a[100][100] , int n , int &ev)
{
    ev=1;
    ev=a[st[k-1]][st[k]];
    if(ev)
        for(int i=1;i<=k-2;i++)
            if(st[k]==st[i+1] && st[k-1]==st[i])
                ev=0;
    ///*
    if(ev)
        for(int i=2;i<k;i++)
            if(st[i]==st[k])    /// circuite elementare
                ev=0;
    //*/
}

void tipar(int st[100] , int k)
{
    printf("O solutie este : ");
    for(int i=1;i<=k;i++)
        printf("%d ",st[i]);
    printf("\n");
}

int solutie(int a[100][100] , int st[100] , int k , int s)
{
    return(st[k]==s);
}

void back_tracking(int a[100][100] , int n , int p)
{
    int st[100], k=2, as, ev;
    st[1]=p;
    init(st,k);
    while(k!=1)
    {
        do
        {
            succesor(st,k,n,as);
            if(as)
                valid(st,k,a,n,ev);
        }
        while(!((!as)||(as&&ev)));
        if(as)
            if(solutie(a,st,k,p))
            {
                tipar(st,k);
                k++;
                init(st,k);
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
    int a[100][100], n;
    citire_matrice(a,n);
    back_tracking(a,n,1);
}