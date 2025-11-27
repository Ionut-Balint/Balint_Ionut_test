#include <stdio.h>
#include <string.h>

void elimina_cif(char v[201] , int n)
{
    for(int i=0;i<n;i++)
    {
        if(v[i]>='0'&&v[i]<='9')
        {
            for(int j=i+1;j<n;j++)
                v[j-1]=v[j];
            n--;
            i--;
        }
    }
    v[n]='\0';
    for(int i=0;i<n-1;i++)
    {
        if(v[i]==' ' && v[i+1]==' ')
        {
            for(int j=i+1;j<n;j++)
                v[j-1]=v[j];
            n--;
            i--;
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
    strupr(v);
    printf("%s",v);
    strcpy(v,a);
    elimina_cif(v,strlen(v));
    printf("\n%s",v);
    v[0]='\0';
    p=strtok(a," ");
    while(p)
    {
        if(strlen(p)%2==1)
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
