#include <bits/stdc++.h>
#define ll long long
using namespace std;
class TournamentPlan
{
public:
    int getTravelDistance(vector <int> street, vector <int> avenue)
    {
        int ans=1e9;
        int n=street.size();
        for (int i=0; i<n; i++)
        {
            for(int k=0; k<n; k++)
            {
            int dist=0;
                for (int j=0; j<n; j++)
                {
                    dist+=(abs(street[j]-street[i])+abs(avenue[j]-avenue[k]));
                }
            ans=min(ans,dist);
            }
        }
        return ans;
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    return 0;
}
