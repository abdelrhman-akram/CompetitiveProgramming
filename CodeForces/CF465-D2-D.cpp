#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<vector<int> > vec(8,vector<int>(3));
ll two(ll a)
{
    return a*a;
}
ll dis(int ind1,int ind2)
{
    return two(vec[ind1][0]-vec[ind2][0])+two(vec[ind1][1]-vec[ind2][1])+two(vec[ind1][2]-vec[ind2][2]);
}
bool flag=0;
void solve(int ind,set<ll>sett)
{
    if (flag||sett.size()>3)
        return;
    if (ind==8)
    {
        if (sett.size()==3)
        {
            cout<<"YES"<<endl;
            for (int i=0; i<8; cout<<endl,i++)
                for (int j=0; j<3; j++)
                    cout<<vec[i][j]<<" ";
            flag=1;
        }
        return ;
    }
    do
    {
        set<ll> temp=sett;
        for (int i=ind-1; i>=0; i--)
            temp.insert(dis(ind,i));
        solve(ind+1,temp);
    }
    while(next_permutation(vec[ind].begin(),vec[ind].end()));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    for (int i=0; i<8; sort(vec[i].begin(),vec[i].end()),i++)
        for (int j=0; j<3; j++)
            cin>>vec[i][j];
    set<ll>sett;
    solve(0,sett);
    if (!flag)
        cout<<"NO";
    return 0;
}
