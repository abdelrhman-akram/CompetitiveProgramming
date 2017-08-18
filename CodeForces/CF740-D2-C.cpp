#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    int ans=1e9;
    while(m--)
    {
        int l,r;
        cin>>l>>r;
        ans=min(ans,(r-l)+1);
    }
    cout<<ans<<endl;
    int c=0;
    for (int i=0; i<n; i++)
    {
        cout<<c<<" ";
        c++;
        c%=ans;
    }
    return 0;
}
