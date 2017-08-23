#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=15e6+5;
unsigned short arr[N];
class Over9000Rocks
{
public:
    int countPossibilities(vector <int> lowerBound, vector <int> upperBound)
    {
        int n=lowerBound.size();
        for (int i=0; i<(1<<n); i++)
        {
            int s=0,s2=0;
            for (int j=0; j<n; j++)
                if (i&(1<<j))
                    s+=lowerBound[j],s2+=upperBound[j];
        arr[s]++;
        arr[s2+1]--;
        }
       for (int i=1;i<N;i++)arr[i]+=arr[i-1];
        int ret=0;
        for (int i=9001;i<N;i++)if (arr[i]>0)ret++;
        return ret;
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    return 0;
}
