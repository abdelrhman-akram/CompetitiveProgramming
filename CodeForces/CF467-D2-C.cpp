#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll>vec;
int n,m,k;
ll dp[5005][5005];
ll solve(int ind,int t)
{
    if (ind==n)
    {
        if (t==k)
            return 0;
        return -1e18;
    }
    if (dp[ind][t]!=-1)
        return dp[ind][t];
    ll c=solve(ind+1,t);
    if (ind+m<=n)
    {
        if (ind)
            c=max(c,solve(ind+m,t+1)+vec[ind+m-1]-vec[ind-1]);
        else
            c=max(c,solve(ind+m,t+1)+vec[ind+m-1]);
    }
    return dp[ind][t]=c;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    memset(dp,-1,sizeof dp);
    cin>>n>>m>>k;
    vec.resize(n);
    for (int i=0; i<n; i++)
    {
        cin>>vec[i];
        if (i)
            vec[i]+=vec[i-1];
    }
    cout<< solve(0,0);
    return 0;
}
