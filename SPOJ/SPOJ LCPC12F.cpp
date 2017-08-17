#include <bits/stdc++.h>
#define ll long long
using namespace std;
int arr[100005];
vector<vector<int> >vec;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    int test=1;
    while(t--)
    {
        int x,n;
        cin>>x>>n;
        vec.clear();
        vec.resize(2005);
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
            vec[arr[i]].push_back(i);
        }
        ll s=0;
        for(int i=0; i<n; i++)
        {
            if (arr[i]<=x)
            {
                vector<int>::iterator it=lower_bound(vec[x-arr[i]].begin(),vec[x-arr[i]].end(),i);
                if (it==vec[x-arr[i]].begin()||vec[x-arr[i]].size()==0)
                    continue;
                ll z=it-vec[x-arr[i]].begin()-1;
                z++;
                s+=z;
            }
        }
        cout<<test++<<". "<<s<<endl;
    }
    return 0;
}
