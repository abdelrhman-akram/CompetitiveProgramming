#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    string line;
    map<char,ll> mapp;
    int y=1;
    for (char c='a'; c<='z'; c++,y++)
        mapp[c]=y;
    while(getline(cin,line))
    {
        vector<ll> vec;
        ll w=0;
        for (int i=0; i<line.size(); i++)
        {
            if (line[i]==' ')
            {
                if (w!=0)
                    vec.push_back(w);
                w=0;
                continue;
            }
            w*=32ll;
            w+=(mapp[line[i]]);
            if (i==line.size()-1)
            {
                if (w!=0)
                    vec.push_back(w);
            }
        }
        int n=vec.size();
        for (ll i=1; i<=4e9; i++)
        {
            ll ma=0;
            bool flag=1;
            for (int j=0; j<vec.size(); j++)
            {
                int t=(i/vec[j])%n;
                for (int k=0; k<vec.size(); k++)
                {
                    if (i%vec[k]==0)
                        flag&=1;
                    if (k==j)continue;
                    int z=(i/vec[k])%n;
                    if (t==z)
                    {
                        ll tem=min(((i/vec[j])+1)*vec[j],((i/vec[k])+1)*vec[k]);
                        ma=max(ma,tem);
                        flag=0;
                    }
                }
            }
            if (flag)
            {
                cout<<line<<endl;
                cout<<i<<endl<<endl;
                break;
            }
            i=max(ma,i)-1;
        }
    }
    return 0;
}
