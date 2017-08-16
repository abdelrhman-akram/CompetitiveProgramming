#include <bits/stdc++.h>
#define ll long long
using namespace std;
class OneArmedBandit
{
public:
    double progressiveJackpot(vector <string> wheels, string jackpotLine, vector <string> payoffTable)
    {
        vector<map<char,double> >vec;
        vec.resize(wheels.size());
        for (int i=0; i<wheels.size(); i++)
        {
            map<char,double> temp;
            for (int j=0; j<wheels[i].size(); j++)
            {
                temp[wheels[i][j]]++;
            }
            vec[i]=temp;
        }
        double prop=1;
        for (int i=0; i<jackpotLine.size(); i++)
        {
            char x=jackpotLine[i];
            if (x=='-')
                continue;
            if (vec[i][x]==0)
                return -1;
            prop*=vec[i][x]/(double)wheels[i].size();
        }
        double total=0;
        for (int i=0; i<payoffTable.size(); i++)
        {
            double t=1.0,pay;
            stringstream ss(payoffTable[i]);
            string tem;
            ss>>tem;
            ss>>pay;
            for (int j=0; j<tem.size(); j++)
            {
                char x=tem[j];
                if (x=='-')
                    continue;
                t*=(vec[j][x]/(double)wheels[j].size());
                if (t>=1)
                    return 0;
            }
            t*=pay;
            total+=t;
        }
        if (total>=1)
            return 0;
        total=1-total;
        total=(double)total/prop;
        return total;
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    return 0;
}
