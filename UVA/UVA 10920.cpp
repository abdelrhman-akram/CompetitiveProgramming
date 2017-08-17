#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll s,p;
bool flag=0;
void solve(ll n,int r,int c,int ld,int ru)
{
    if (flag)
        return ;
    if (n==p)
    {
        flag=1;
        cout<<"Line = "<<r<<", column = "<<c<<"."<<endl;
    }
    if (flag)
        return ;
    if (r==c)
        solve(n+1,r+1,c,ld-1,ru+1);
    ll x=p-n;
    if (r==ru)
    {
        if (c-ld<x)
            solve(n+(c-ld)+1,r-1,ld,ld,ru);
        else
            solve(p,r,c-x,ld,ru);
    }
    if (c==ld)
    {
        if (r-ld<x)
            solve(n+(r-ld)+1,ld,ld+1,ld,ru);
        else
            solve(n+x,r-x,c,ld,ru);
    }
    if (r==ld)
    {
        if (ru-c<x)
            solve(n+(ru-c)+1,r+1,ru,ld,ru);
        else
            solve(n+x,r,c+x,ld,ru);
    }
    if (c==ru)
    {
        solve(p,r+x,c,ld,ru);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    while(cin>>s>>p)
    {
        if (s==0&&p==0)
            return 0;
        flag=0;
        ll num,pos=(s/2)+1,tem=(s/2)+1;
        for (ll i=1;; i+=2)
        {
            if (i*i>p)
                break;
            if (i>1)
            {
                tem--;
                pos++;
            }
            num=i*i;
        }
        solve(num,pos,pos,tem,pos);
    }
    return 0;
}
