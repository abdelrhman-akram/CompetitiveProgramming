#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool arr[55],arr2[55];
class QuipuReader
{
public:
    vector <int> readKnots(vector <string> knots)
    {

        for (int i=0; i<knots.size(); i++)
        {
            for (int  j=0; j<knots[i].size(); j++)
            {

                if (j&&knots[i][j]=='X'&&knots[i][j-1]=='X')
                    arr[j]=1;
                if (knots[i][j]=='X')
                    arr2[j]=1;
            }
        }
        for (int i=0; i<knots[0].size(); i++)
            if (!arr2[i])
                arr[i]=1;

        vector<int>ret;
        ret.resize(knots.size());
        for (int i=0; i<knots.size(); i++)
        {
            int n=0;
            for(int j=0; j<knots[i].size(); j++)
            {
                if (!arr[j])
                    n*=10;
                if (knots[i][j]=='X')
                    n++;
            }
            ret[i]=n;
        }
        return ret;
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    return 0;
}
