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
    for(int i=1;i<k;i++)
        if(st[i]==st[k])
            ev=0;
    if(ev)
        ev=a[st[k]][st[k-1]];
}

void tipar(int st[100] , int k)
{
    printf("O solutie este : ");
    for(int i=1;i<=k;i++)
        printf("%d ",st[i]);
    printf("%d\n", st[1]);
}

int solutie(int st[100] , int k , int a[100][100])
{
    return(k>=3 && a[st[k]][st[1]] && st[2]<st[k]);
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
            if(solutie(st,k,a))
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
