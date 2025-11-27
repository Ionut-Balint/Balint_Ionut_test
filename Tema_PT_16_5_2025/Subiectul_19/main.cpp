#include <stdio.h>
#include <string.h>

void dublare_voc(char v[201])
{
    int n=strlen(v);
    for(int i=0;i<n;i++)
    {
        if(v[i]=='a' || v[i]=='e' || v[i]=='i' || v[i]=='o' || v[i]=='u' || v[i]=='A' || v[i]=='E' || v[i]=='I' || v[i]=='O' || v[i]=='U')
        {
            char aux=v[i];
            for(int j=n-1;j>i;j--)
            {
                v[j+1]=v[j];
            }
            n++;
            v[i+1]=aux;
            i+=1;
        }
    }
    v[n]='\0';
}

void inverseaza(char *p)
{
    int n=strlen(p);
    for(int i=0;i<n/2;i++)
    {
        char aux=p[i];
        p[i]=p[n-i-1];
        p[n-i-1]=aux;
    }
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
    printf("%s\n",v);
    dublare_voc(v);
    printf("%s",v);
    v[0]='\0';
    p=strtok(a," ");
    while(p)
    {
        if(p[0]=='a' || p[0]=='e' || p[0]=='i' || p[0]=='o' || p[0]=='u' || p[0]=='A' || p[0]=='E' || p[0]=='I' || p[0]=='O' || p[0]=='U')
        {
            inverseaza(p);
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
