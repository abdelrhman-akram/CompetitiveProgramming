#include <bits/stdc++.h>
#define ll long long
using namespace std;
double eps=1e-7;
bool cmp(pair<double,pair<double,string> >f,pair<double,pair<double,string> >s)
{
    if (f.first<s.first)
        return 1;
    if (f.first==s.first)
    {
        if (f.second.first-s.second.first>eps)
            return 1;
        if (s.second.first-f.second.first>eps)
            return 0;
        return (f.second.second<s.second.second);
    }
    return 0;
}
class ContestScore
{
public:
    vector <string> sortResults(vector <string> data)
    {
        if (data.size()==0)
            return data;
        map<string,double> total,rankk;
        vector<string> names;
        vector<vector<double> > judges;
        judges.resize(data.size());
        for (int i=0; i<data.size(); i++)
        {
            string tem="";
            int j;
            for ( j=0;; j++)
            {
                if (data[i][j]==' ')
                    break;
                tem+=data[i][j];
            }
            names.push_back(tem);
            double n=0,ten=10;
            bool flag=0;
            j++;
            for (; j<data[i].size(); j++)
            {
                if (data[i][j]==' ')
                {
                    judges[i].push_back(n),total[tem]+=n,n=0,flag=0,ten=10;
                    continue;
                }
                if (data[i][j]=='.')
                {
                    flag=1;
                    continue;
                }
                if (!flag)
                {
                    n*=10,n+=(data[i][j]-'0');
                }
                if (flag)
                {
                    double t=data[i][j]-'0';
                    n+=((1.0/ten)*t);
                    ten*=10;
                }
                if (j==data[i].size()-1)
                    judges[i].push_back(n),total[tem]+=n;
            }
        }
        for (int i=0; i<judges[0].size(); i++)
        {
            vector<pair<double,string> > sor;
            for (int j=0; j<judges.size(); j++)
            {
                sor.push_back(make_pair(judges[j][i],names[j]));
            }
            sort(sor.rbegin(),sor.rend());
            int last=0;
            for (int j=0; j<sor.size(); j++)
            {
                if (!j)
                    rankk[sor[j].second]+=j+1,last=j+1;
                else
                {
                    if (sor[j].first==sor[j-1].first)
                        rankk[sor[j].second]+=last;
                    else
                        rankk[sor[j].second]+=j+1,last=j+1;
                }
            }
        }
        vector<pair<double,pair<double,string> > > sorted;
        for(map<string,double>::iterator it=rankk.begin(); it!=rankk.end(); it++)
        {
            sorted.push_back(make_pair(it->second,make_pair(total[it->first],it->first)));
        }
        sort(sorted.begin(),sorted.end(),cmp);
        vector<string> ret;
        for (int i=0; i<sorted.size(); i++)
        {
            string line="";
            line+=sorted[i].second.second;
            line+=" ";
            stringstream ss;
            ss<<sorted[i].first;
            string tem;
            ss>>tem;
            line+=tem;
            line+=" ";
            stringstream ss1;
            tem="";
            ss1<<sorted[i].second.first;
            ss1>>tem;
            bool flag=0;
            for(int j=0; j<tem.size(); j++)
            {
                if (tem[j]=='.')
                {
                    flag=1;
                    break;
                }
            }
            if (!flag)
                tem+=".0";
            line+=tem;
            ret.push_back(line);
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
