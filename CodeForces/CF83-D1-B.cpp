#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    vector<ll> vec;
    int n;
    ll k;
    cin>>n>>k;
    vec.resize(n);
    ll sum1=0;
    for (int i=0; i<n; i++)
        cin>>vec[i],sum1+=vec[i];
    if (sum1<k)
        return cout<<-1,0;
    if (sum1==k)
        return cout<<endl,0;
    ll s=0,e=1e10,mid,t=0;
    while(s<=e)
    {
        mid=(s+e)/2;
        ll sum=0;
        for (int i=0; i<n; i++)
            sum+=min(mid,vec[i]);
        if (sum<k)
            s=mid+1,t=max(t,mid);
        if (sum>=k)
            e=mid-1;
    }
    s=t;
    for (int i=0; i<n; i++)
    {
        k-=min(vec[i],s);
        vec[i]-=min(vec[i],s);
    }
    for (int i=0; i<n; i++)
    {
        if (k==0&&vec[i])
            cout<<i+1<<" ",vec[i]=0;
        if (k&&vec[i])
            vec[i]--,k--;
    }
    for(int i=0; i<n; i++)
        if (vec[i])cout<<i+1<< " ";
    return 0;
}
