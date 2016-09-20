#include <bits/stdc++.h>
#include <iostream>
#include <windows.h>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;
struct jatekos
{
    int s1=0;
    int s2=0;
    int s3=0;
    int penz=-15;
    string nev;
};
typedef jatekos jatek;
jatek jat[4];
jatek jat2[4];
jatek jat3[4];
int jdb;
int arfolyam[3];
int t[3][22];
char b;
int eredmeny[4];
int db=0;
int q=1;
int s=0;
int r;
int a[4][3];
int c[4][3];
int iii;
string szint;

void csere(int& a, int& b)
{
    int c=a;
    a=b;
    b=c;
}
void csere2(jatek& a,jatek& b)
{
    jatek c=a;
    a=b;
    b=c;
}
int main()
{
    for(int i=0;i<=14;i++)
        {
            t[0][i]=i+1;
            t[1][i]=i+1;
            t[2][i]=i+1;
        }
    for(int i=15;i<=21;i++)
    {
        t[0][i]=i-10;
        t[1][i]=i-10;
        t[2][i]=i-10;
    }

    cout<<"A nev pontosan 8 betubol alljon (ha rovidebb, a maradek helyen 0-k legyenek)"<<endl;
    cout<<"Jatekosok szama (max 4): ";
    cin>>jdb;
    cout<<"Szint(kezdo, kozephalado, halado): ";
    cin>>szint;
    if(szint=="kezdo")
    {
        for(int i=0;i<jdb;i++)
            jat[i].penz=15;
        cout<<"Ebben a modban minden jatekos 15 penzzel es 0 reszvennyel indul"<<endl;
    }
    else
        cout<<"Eleinte mindenkinek -15 penze van. Addig nem lehet vasarolni amig ez az ertek negativ"<<endl;

    cout<<"Gombok: S1 vetele-a; S1 eladasa-d";
    if(szint!="kezdo")
    {
        cout<<"; S2 vetele-j; S2 eladasa-l";
        if(szint!="kozephalado")
        {
            cout<<"; S3 vetele-r; S3 eladasa-z";
        }
    }
    cout<<"; passz-b"<<endl;
    cout<<"A szabalytalan muvelet passznak minosul"<<endl<<endl;

    int jdb2=jdb;
    int ii=0;
    srand (time(0));

    while (jdb2>0)
    {
        cout<<ii+1<<". jatekos neve: ";
        cin>>jat[ii].nev;
        if(szint=="kozephalado")
        {
            a[ii][0]=(rand()%6);
            a[ii][1]=5-a[ii][0];
            c[ii][0]=rand()%2;
            jat[ii].s1=a[ii][c[ii][0]];
            csere(a[ii][c[ii][0]],a[ii][1]);
            jat[ii].s2=a[ii][0];
            cout<<jat[ii].nev<<" S1-einek a szama: "<<jat[ii].s1<<endl;
            cout<<jat[ii].nev<<" S2-einek a szama: "<<jat[ii].s2<<endl<<endl;
        }
        if(szint=="halado")
        {
            a[ii][0]=(rand()%6);
            a[ii][1]=(rand()%(6-a[ii][0]));
            a[ii][2]=5-a[ii][0]-a[ii][1];
            c[ii][0]=rand()%3;
            jat[ii].s1=a[ii][c[ii][0]];
            csere(a[ii][c[ii][0]],a[ii][2]);
            c[ii][1]=rand()%2;
            jat[ii].s2=a[ii][c[ii][1]];
            csere(a[ii][c[ii][1]],a[ii][1]);
            jat[ii].s3=a[ii][0];
            cout<<jat[ii].nev<<" S1-einek a szama: "<<jat[ii].s1<<endl;
            cout<<jat[ii].nev<<" S2-einek a szama: "<<jat[ii].s2<<endl;
            cout<<jat[ii].nev<<" S3-ainek a szama: "<<jat[ii].s3<<endl<<endl;
        }
        jdb2-=1;
        ii+=1;
    }
    jdb2=jdb;

    for(int i=21;i>=0;i--)
    {
        for(int j=0;j<4;j++)
        {
            jat2[j]=jat[j];
        }
        arfolyam[0]=(rand()%(i+1));
        cout<<endl<<22-i<<". S1= "<<t[0][arfolyam[0]]<<" ";
        if(szint!="kezdo")
        {
            arfolyam[1]=(rand()%(i+1));
            cout<<"S2= "<<t[1][arfolyam[1]]<<" ";
            if(szint!="kozephalado")
            {
                arfolyam[2]=(rand()%(i+1));
                cout<<"S3= "<<t[2][arfolyam[2]];
            }
        }
        cout<<endl<<endl;

        while(jdb2>0)
        {
            r=(rand()%jdb2);
            cout<<jat2[r].nev<<" altal vegrehajtani kivant muvelet: ";
            cin>>b;

            if(b=='a')
            {
                if(jat2[r].penz-t[0][arfolyam[0]]>=0)
                {
                    jat2[r].s1+=1;
                    jat2[r].penz-=t[0][arfolyam[0]];
                }
                else
                {
                    cout<<"Szabalytalan muvelet, passz"<<endl;
                }
            }
            if(b=='d')
            {
                jat2[r].penz+=t[0][arfolyam[0]]*jat2[r].s1;
                jat2[r].s1=0;
            }

            if(szint!="kezdo")
            {
                if(b=='j')
                {
                    if(jat2[r].penz-t[1][arfolyam[1]]>=0)
                    {
                        jat2[r].s2+=1;
                        jat2[r].penz-=t[1][arfolyam[1]];
                    }
                    else
                    {
                        cout<<"Szabalytalan muvelet, passz"<<endl;
                    }
                }
                if(b=='l')
                {
                    jat2[r].penz+=t[1][arfolyam[1]]*jat2[r].s2;
                    jat2[r].s2=0;
                }
                if(szint!="kozephalado")
                {
                    if(b=='r')
                    {
                        if(jat2[r].penz-t[2][arfolyam[2]]>=0)
                        {
                            jat2[r].s3+=1;
                            jat2[r].penz-=t[2][arfolyam[2]];
                        }
                        else
                        {
                            cout<<"Szabalytalan muvelet, passz"<<endl;
                        }
                    }
                    if(b=='z')
                    {
                        jat2[r].penz+=t[2][arfolyam[2]]*jat2[r].s3;
                        jat2[r].s3=0;
                    }
                }
            }
            while(q!=0 && s<=(jdb-1))
            {
                if(jat[s].nev==jat2[r].nev)
                {
                    jat[s]=jat2[r];
                    q=0;
                }
                s+=1;
            }
            s=0;
            q=1;
            csere2(jat2[r],jat2[jdb2-1]);
            jdb2-=1;
        }
        cout<<endl;
        jdb2=jdb;

        if(i!=0)
            cout<<"                  Allas"<<endl;
        else
            cout<<"                Vegeredmeny"<<endl;
        cout<<"              S1     ";
        if(szint!="kezdo")
        {
            cout<<"S2     ";
            if(szint!="kozephalado")
            {
                cout<<"S3     ";
            }
        }
        cout<<"Penz"<<endl;
        for(int l=0;l<4;l++)
        {
            jat3[l]=jat[l];
        }
        for(int m=0;m<3;m++)
        {
            for(int n=m+1;n<4;n++)
            {
                if(jat3[n].penz>jat3[m].penz)
                    csere2(jat3[n],jat3[m]);
            }
        }
        iii=0;
        while(jdb2!=0)
        {
            cout<<jat3[iii].nev<<":     "<<jat3[iii].s1<<"      ";
            if(szint!="kezdo")
            {
                cout<<jat3[iii].s2<<"      ";
                if(szint!="kozephalado")
                {
                    cout<<jat3[iii].s3<<"      ";
                }
            }
            cout<<jat3[iii].penz<<endl;
            jdb2-=1;
            iii+=1;
        }
        jdb2=jdb;

        csere(t[0][arfolyam[0]],t[0][i]);
        csere(t[1][arfolyam[1]],t[1][i]);
        csere(t[2][arfolyam[2]],t[2][i]);
        b='x';
    }
    eredmeny[1]=-500;
    eredmeny[2]=-600;
    eredmeny[3]=-700;

    eredmeny[0]=jat[0].penz;
    if(jat[1].penz>-499 && jdb>1)
        eredmeny[1]=jat[1].penz;
    if(jat[2].penz>-499 && jdb>2)
        eredmeny[2]=jat[2].penz;
    if(jat[3].penz>-499 && jdb>3)
        eredmeny[3]=jat[3].penz;
    for(int k=1;k<=3;k++)
    {
        if(eredmeny[k]>eredmeny[0])
            csere(eredmeny[k],eredmeny[0]);
    }
    if(eredmeny[0]==jat[0].penz)
        db+=1;
    if(eredmeny[0]==jat[1].penz && jdb>1)
        db+=1;
    if(eredmeny[0]==jat[2].penz && jdb>2)
        db+=1;
    if(eredmeny[0]==jat[3].penz && jdb>3)
        db+=1;
    if (db==1)
    {
        cout<<endl<<"A gyoztes: ";
    }
    else
    {
        cout<<"A gyoztesek holtversenyben: ";
    }
    if(eredmeny[0]==jat[0].penz)
        cout<<jat[0].nev<<" ";
    if(eredmeny[0]==jat[1].penz && jdb>1)
        cout<<jat[1].nev<<" ";
    if(eredmeny[0]==jat[2].penz && jdb>2)
        cout<<jat[2].nev<<" ";
    if(eredmeny[0]==jat[3].penz && jdb>3)
        cout<<jat[3].nev<<" ";
    return 0;
}
