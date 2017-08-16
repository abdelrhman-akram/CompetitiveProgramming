#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    ll c,hr,hb,wr,wb;
    cin>>c>>hr>>hb>>wr>>wb;
    ll ans=0;
    if (wr<wb){
        swap(wr,wb);
        swap(hr,hb);
    }
    for (int i=0;i<=1e7; i++)
    {
        if (i*wr>c)
            break;
        ll t=(i*hr)+((c-(i*wr))/wb)*hb;
        ll z=(i*hb)+((c-(i*wb))/wr)*hr;
        ans=max(ans,t);
        ans=max(ans,z);
    }
    cout<<ans;
    return 0;
}
