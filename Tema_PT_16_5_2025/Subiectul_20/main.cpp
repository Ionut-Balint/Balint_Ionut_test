#include <stdio.h>
#include <string.h>

void prim_mare(char v[201])
{
    int n=strlen(v);
    for(int i=0;i<n;i++)
    {
        if(i==0 && v[i]>='a' && v[i]<='z')
            v[i]+='A'-'a';
        if(v[i-1]==' ' && v[i]>='a' && v[i]<='z')
            v[i]+='A'-'a';
    }
}

void eliminare_spatii(char v[201])
{
    int n=strlen(v);
    for(int i=0;i<n-1;i++)
    {
        if(v[i]==' ' && v[i+1]==' ')
        {
            for(int j=i+1;j<n;j++)
                v[j]=v[j+1];
            n--;
            i--;
        }
    }
    v[n]='\0';
}

void stele(char *p)
{
    int n=strlen(p);
    for(int i=0;i<=n-1;i++)
        p[i]='*';
}

int main()
{
    char a[201], v[201], *p;
    int pres=0;
    FILE *f=fopen("atestat.in","r");
    FILE *g=fopen("atestat.out","w");
    fgets(a,200,f);
    strcpy(v,a);
    strlwr(v);
    prim_mare(v);
    printf("%s\n",v);
    strcpy(v,a);
    eliminare_spatii(v);
    printf("%s",v);
    v[0]='\0';
    p=strtok(a," ");
    while(p)
    {
        if(strlen(p)%2==0)
        {
            stele(p);
            pres=1;
        }
        strcat(v,p);
        strcat(v," ");
        p=strtok(NULL," ");
    }
    v[strlen(v)-1]='\0';
    if(pres)
        fprintf(g,"%s",v);
    else
        fprintf(g,"NU EXISTA");

}
