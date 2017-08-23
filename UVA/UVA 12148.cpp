#include <bits/stdc++.h>
#define ll long long
using namespace std;
int arr[13]= {0,31,28,31,30,31,30,31,31,30,31,30,31};
bool leapyear(int year)
{
    if (year%4==0&&year%100!=0)
        return 1;
    if (year%400==0)
        return 1;
    return 0;
}
void next(int &d,int &m,int &y)
{
    if (m!=2)
    {
        d++;
        if (d==arr[m]+1)
            d=1,m++;
        if (m==13)
            m=1,y++;
    }
    else
    {
        d++;
        if(d==29&&!leapyear(y))
            d=1,m++;
        if (d==30&&leapyear(y))
            d=1,m++;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    while(cin>>n&&n)
    {
        int d,m,y,c;
        cin>>d>>m>>y>>c;
        next(d,m,y);
        int day=0;
        ll allc=0;
        for (int i=0; i<n-1; i++)
        {
            int nd,nm,ny,nc;
            cin>>nd>>nm>>ny>>nc;
            if (nd==d&&nm==m&&ny==y)
                day++,allc+=(nc-c);
            d=nd,m=nm,y=ny,c=nc;
            next(d,m,y);
        }
        cout<<day<<" "<<allc<<'\n';
    }
    return 0;
}
