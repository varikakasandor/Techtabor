#include <bits/stdc++.h>
using namespace std;

int hegyekszama,volgyekszama;
vector<int> harmasszamrendszerbelialak;

void atalakit(int x)
{
    harmasszamrendszerbelialak.clear();
    int haromhatvany=1;
    while(haromhatvany<=x) haromhatvany*=3;
    haromhatvany/=3;
    while(haromhatvany>=1)
    {
        harmasszamrendszerbelialak.push_back(x/haromhatvany);
        x-=(x/haromhatvany)*haromhatvany;
        haromhatvany/=3;
    }
}

void hegyvolgy()
{
    for(int i=1;i<harmasszamrendszerbelialak.size()-1;i++)
    {
        if(harmasszamrendszerbelialak[i]>=harmasszamrendszerbelialak[i-1] && harmasszamrendszerbelialak[i]>=harmasszamrendszerbelialak[i+1]) hegyekszama+=1;
        else if(harmasszamrendszerbelialak[i]<=harmasszamrendszerbelialak[i-1] && harmasszamrendszerbelialak[i]<=harmasszamrendszerbelialak[i+1]) volgyekszama+=1;
    }
}

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        atalakit(i);
        hegyvolgy();
    }
    cout<<double((hegyekszama-volgyekszama))/n;
    return 0;
}
