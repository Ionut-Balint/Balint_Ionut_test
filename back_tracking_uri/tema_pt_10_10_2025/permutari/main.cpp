#include <stdio.h>

void init(int st[100] , int k)
{
    st[k]=0;
}

void succesor(int st[100] , int k , int n , int & as)
{
    if(st[k]<n)
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
    for(int i=1;i<k;i++)
        if(st[k]==st[i])
            ev=0;
}

int solutie(int k , int n)
{
    return(k==n);
}
void tiparire(int st[100] , int k)
{
    printf("O permutare este : ");
    for(int i=1;i<=k;i++)
        printf("%d ",st[i]);
    printf("\n");
}

void back_tracking(int n)
{
    int k=1, as, ev, st[100];
    init(st,k);
    while(k!=0)
    {
        do
        {
            succesor(st,k,n,as);
            if(as)
                valid(st,k,ev);
        }
        while(!((!as)||(as&&ev)));
        if(as)
            if(solutie(k,n))
                tiparire(st,k);
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
    int n;
    scanf("%d",&n);
    back_tracking(n);
}
