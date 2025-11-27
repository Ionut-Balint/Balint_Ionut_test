#include <stdio.h>

void pao(int x , int y , int & rez)
{
    int xn=0, yn=0, c, p10=1;
    while(x)
    {
        c=x%10;
        if(c && c%2==0)
        xn=xn*10+c;
        x/=10;
    }
    while(y)
    {
        c=y%10;
        if(c && c%2==0)
        {
            yn=yn+c*p10;
            p10*=10;
        }
        y/=10;
    }
    if(xn && xn==yn)
        rez=1;
    else
        rez=0;
}

int main()
{
    int x, y, rez;
    scanf("%d%d",&x,&y);
    pao(x,y,rez);
    printf("%d",rez);
}
