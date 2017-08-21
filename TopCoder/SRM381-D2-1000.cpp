#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool cmp(int x,int y)
{
    string a,b;
    stringstream ss;
    ss<<x;
    ss>>a;
    stringstream ss1;
    ss1<<y;
    ss1>>b;
    for (int i=0; i<max(b.size(),a.size()); i++)
    {
        if (a[i%a.size()]>b[i%b.size()])
            return 1;
        if (a[i%a.size()]<b[i%b.size()])
            return 0;
    }
    return 1;
}
class TheNumbersLord
{
public:
    string create(vector <int> numbers, int n)
    {
        sort(numbers.begin(),numbers.end());
        vector<int> vec;
        for (int i=0; i<numbers.size(); i++)
            vec.push_back(numbers[i]);
        while(vec.size()<n)
            vec.push_back(numbers[numbers.size()-1]);
        sort(vec.begin(),vec.end(),cmp);
        string out="";
        for (int i=0; i<vec.size(); i++)
        {
            string t;
            stringstream ss;
            ss<<vec[i];
            ss>>t;
            out+=t;
        }
        return out;
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    return 0;
}
