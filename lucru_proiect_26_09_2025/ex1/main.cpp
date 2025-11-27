#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <cstdlib>

int n, m, a[100][100], intmin, extmin, intmax, extmax;

struct persoana
{
    int nr;
    char nume[20], prenume[20], meserie[20];
};

persoana pers[30];

void citire_matrice()
{
    FILE *f=fopen("graf.in","r");
    fscanf(f,"%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            fscanf(f,"%d",&a[i][j]);
}

void citire_persoane()
{
    FILE *ff=fopen("nume.in","r");
    for(int i=1;i<=n;i++)
    {
        fscanf(ff,"%d",&pers[i].nr);
        fscanf(ff,"%s%s%s", &pers[i].nume, &pers[i].prenume, &pers[i].meserie);
    }
}

int grad_intern(int x)
{
    int s=0;
    for(int i=1;i<=m;i++)
        if(a[x][i]==1)
            s++;
    return s;
}

int grad_extern(int x)
{
    int s=0;
    for(int i=1;i<=m;i++)
        if(a[x][i]==-1)
            s++;
    return s;
}

void cerinta_a()
{
    int pres=0;
    for(int i=1;i<=n;i++)
        if(grad_intern(i)==n-1 && grad_extern(i)==0)
        {
            if(!pres)
                printf("Celebritatiile sunt : ");
            pres=1;
            printf("%s %s, cu meseria de %s;   ",pers[i].nume, pers[i].prenume, pers[i].meserie);
        }
    if(pres)
        printf("\nCelebritatea este acea persoana care este cunoscuta de toate celelalte persoane dar care nu cunoaste pe nimeni.");
    printf("\n");
    if(!pres)
    {
        printf("Nu avem celebritati, dar :\n");
        int pozextmin=1, pozintmax=1;
        extmin = grad_extern(1);
        intmax = grad_intern(1);
        for(int i=2;i<=n;i++)
        {

            if(grad_extern(i)<extmin)
            {
                extmin=grad_extern(i);
                pozextmin=i;
            }
            if(grad_intern(i)>intmax)
            {
                intmax=grad_intern(i);
                pozintmax=i;
            }
        }
        printf("\tPersoana care cunoaste cele mai putine persoane este %s %s;\n",pers[pozextmin].nume, pers[pozextmin].prenume);
        printf("\tPersoana care este cunoscuta de cele mai multe persoane este %s %s;\n",pers[pozintmax].nume, pers[pozintmax].prenume);
        printf("\nCelebritatea este acea persoana care este cunoscuta de toate celelalte persoane dar care nu cunoaste pe nimeni.");
    }
}

void cerinta_b()
{
    int pres=0;
    for(int i=1;i<=n;i++)
        if(grad_extern(i)==n-1 && grad_intern(i)==0)
        {
            if(!pres)
                printf("Necunoscutii sunt : ");
            pres=1;
            printf("%s %s, cu meseria de %s;   ",pers[i].nume, pers[i].prenume, pers[i].meserie);
        }
    if(pres)
        printf("\nNecunoscutul este acea persoana care cunoaste toate celelalte persoane dar care nu este cunoasta de nimeni.");
    if(!pres)
    {
        printf("Nu avem necunoscuti, dar :\n");
        int pozextmax=1, pozintmin=1;
        extmax = grad_extern(1);
        intmin = grad_intern(1);
        for(int i=2;i<=n;i++)
        {

            if(grad_extern(i)>extmax)
            {
                extmax=grad_extern(i);
                pozextmax=i;
            }
            if(grad_intern(i)<intmin)
            {
                intmin=grad_intern(i);
                pozintmin=i;
            }
        }
        printf("\tPersoana care cunoaste cele mai multe persoane este %s %s;\n",pers[pozextmax].nume, pers[pozextmax].prenume);
        printf("\tPersoana care este cunoscuta de cele mai putine persoane este %s %s;\n",pers[pozintmin].nume, pers[pozintmin].prenume);
        printf("Necunoscutul este acea persoana care cunoaste toate celelalte persoane dar care nu este cunoasta de nimeni.");
    }
}

void cerinta_c()
{
    int pres=0;
    for(int i=1;i<=n;i++)
        if(grad_extern(i)+grad_intern(i)==1)
        {
            if(!pres)
                printf("Singuraticii sunt : ");
            printf("%s %s, cu meseria de %s;   ",pers[i].nume, pers[i].prenume, pers[i].meserie);
            pres=1;
        }
    if(pres)
        printf("\nSinguraticul este persoana care cunoaste o singura persoana sau este cunoscuta doar de o singura persoana");
}

void cerinta_d()
{
    int pres=0;
    for(int i=1;i<=n;i++)
        if(grad_extern(i)+grad_intern(i)==0)
        {
            if(!pres)
                printf("Strainii de grup sunt : ");
            printf("%s %s, cu meseria de %s;   ",pers[i].nume, pers[i].prenume, pers[i].meserie);
            pres=1;
        }
    if(!pres)
        printf("Nu avem straini de grup.");
    printf("\nStrainul de grup este acea persoana care nu cunoaste pe nimeni si nu este cunoscuta de nimeni.");
}

void cerinta_e(int x , int y)
{
    int s=0;
    for(int i=1;i<=n;i++)
        if(grad_extern(i)==x && grad_intern(i)==y)
            s++;
    if(s)
        printf("Sunt %d persoane care cunosc %d persoane si sunt cunoscute de %d persoane\n",s,x,y);
    else
        printf("Nu sunt persoane care sa indeplineasca aceste criterii\n");
}

void cerinta_f()
{
    int s=0, x=0;
    for(int i=1;i<=n;i++)
        if(grad_extern(i)==grad_intern(i) && grad_extern(i))
            s++;
    for(int i=1;i<=n;i++)
        if(grad_extern(i)==grad_intern(i) && grad_extern(i))
        {
            if(x==0)
                printf("Sunt %d persoane care cunosc si sunt cunoscute de acelasi numar de persoane\nAcestea sunt : ",s);
            printf("%s %s;  ", pers[i].nume, pers[i].prenume);
            x=1;
        }
    if(!s)
        printf("Nu exista persoane care cunosc si sunt cunoscute de acelasi numar de persoane\n");
}

void cerinta_g()
{
    int j, x=0, y=0, pres=0, nr=0;
    for(int i=1;i<m;i++)
    {
        j=1;
        x=y=pres=0;
        while(j<=n)
        {
            if(a[j][i] && !x)
                x=j;
            if(a[j][i] && !y && x!=j && x!=-1*j)
                y=j;
            if(x&&y)
            {
                j=n;
                for(int k=i+1;k<=m;k++)
                    if(a[x][k] && a[y][k])
                    {
                        pres=1;
                        nr++;
                    }
            if(nr==1&&pres)
                printf("Persoanele care se cunosc reciproc sunt : ");
            if(pres)
                printf("%s %s si %s %s;  ", pers[(int)abs(x)].nume, pers[(int)abs(x)].prenume, pers[(int)abs(y)].nume, pers[(int)abs(y)].prenume);
            }
            j++;
        }
    }
    if(nr)
        printf("\n");
    else
        printf("Nu sunt persoane care sa se cunoasca reciproc\n");
}

void cerinta_h()
{
    for(int i=1;i<=n;i++)
        printf("%d : %s %s cu meseria de %s;\n",pers[i].nr, pers[i].nume, pers[i].prenume, pers[i].meserie);
}


void cerinta_i(int  x)
{
    int v1=0, v2=0;
    for(int i=1;i<=m;i++)
    {
        if(a[x][i]==1)
        {
            for(int j=1;j<=n;j++)
                if(a[j][i]==-1 && j!=x)
                {
                    if(!v1)
                    {
                        v1=1;
                        printf("\nPersoanele care il cunosc pe %s %s sunt : ", pers[x].nume, pers[x].prenume);
                    }
                    printf("%s %s; ", pers[j].nume, pers[j].prenume);
                }
        }

        if(a[x][i]==-1)
        {
            for(int j=1;j<=n;j++)
                if(a[j][i]==1 && j!=x)
                {
                    if(!v2)
                    {
                        v2=1;
                        printf("\nPersoanele pe care le cunoaste %s %s sunt : ", pers[x].nume, pers[x].prenume);
                    }
                    printf("%s %s; ", pers[j].nume, pers[j].prenume);
                }
        }
    }
    if(!v1)
        printf("\nPersoana %s %s nu este cunoscuta de nimeni", pers[x].nume, pers[x].prenume);
    if(!v2)
        printf("\nPersoana %s %s nu cunoaste pe nimeni", pers[x].nume, pers[x].prenume);
}

void afisare_variante()
{
    printf("Dati 1 pentru a afla cine este celebritatea\n");
    printf("Dati 2 pentru a afla cine este necunoscutul\n");
    printf("Dati 3 pentru a afla cine este singuraticul\n");
    printf("Dati 4 pentru a afla cine este strainul de grup\n");
    printf("Dati 5 pentru a afla cate persoane cunosc doar x persoane si sunt cunoscute de y persoane\n");
    printf("Dati 6 pentru a afla cate persoane cunosc acelasi numar de persoane de care sunt cunoscute si ele\n");
    printf("Dati 7 pentru a afla care sunt persoanele care se cunosc reciproc\n");
    printf("Dati 8 pentru a vedea lista cu persoane\n");
    printf("Dati 9 pentru a investiga relatiile de cunostita ale unei persoane\n");
    printf("Dati 0 pentru a iesi din program\n");
    printf("Alegeti o varianta : ");
}

void meniu()
{
    citire_matrice();
    citire_persoane();
    int a=10;
    while(a)
    {
        afisare_variante();
        scanf("%d",&a);
        if(a==1)
        {
            system("cls");
            cerinta_a();
            printf("Apasati orice tasta pentru a va intoarce la meniul principal ");
            int c = _getch();
            system("cls");
        }
        if(a==2)
        {
            system("cls");
            cerinta_b();
            printf("\nApasati orice tasta pentru a va intoarce la meniul principal ");
            int c = _getch();
            system("cls");
        }
        if(a==3)
        {
            system("cls");
            cerinta_c();
            printf("\nApasati orice tasta pentru a va intoarce la meniul principal ");
            int c = _getch();
            system("cls");
        }
        if(a==4)
        {
            system("cls");
            cerinta_d();
            printf("\nApasati orice tasta pentru a va intoarce la meniul principal ");
            int c = _getch();
            system("cls");
        }
        if(a==5)
        {
            system("cls");
            int x,y;
            printf("Dati numarul de persoane pe care sa le cunoasca persoana cautata : ");
            scanf("%d",&x);
            printf("Dati numarul de persoane de care sa fie cunoascuta persoana cautata : ");
            scanf("%d",&y);
            cerinta_e(x,y);
            printf("Apasati orice tasta pentru a va intoarce la meniul principal ");
            int c = _getch();
            system("cls");
        }
        if(a==6)
        {
            system("cls");
            cerinta_f();
            printf("\nApasati orice tasta pentru a va intoarce la meniul principal ");
            int c = _getch();
            system("cls");
        }
        if(a==7)
        {
            system("cls");
            cerinta_g();
            printf("Apasati orice tasta pentru a va intoarce la meniul principal ");
            int c = _getch();
            system("cls");
        }
        if(a==8)
        {
            system("cls");
            cerinta_h();
            printf("\nApasati orice tasta pentru a va intoarce la meniul principal ");
            int c = _getch();
            system("cls");
        }
        if(a==9)
        {
            int x;
            system("cls");
            cerinta_h();
            printf("\nDati indicele persoanei pe care doriti sa o investigati : ");
            scanf("%d",&x);
            cerinta_i(x);
            printf("\nApasati orice tasta pentru a va intoarce la meniul principal ");
            int c = _getch();
            system("cls");
        }
        if(a==0)
            break;
        else
        {
            system("cls");
            continue;
        }
    }
}

int main()
{
    meniu();
}
