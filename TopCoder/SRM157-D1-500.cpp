#include <bits/stdc++.h>
#define ll long long
using namespace std;
class Table
{
public:
    vector <string> layout(vector <string> tbl)
    {
        vector<string> mat;
        mat.resize(500);
        for (int i=0;i<mat.size();i++)
            mat[i].resize(500);
            int row;
        for (int i=0; i<(int)tbl.size(); i++)
        {
            if (tbl[i].size()==0)
                continue;
            for (int j=1; j<(int)tbl[i].size(); j++)
            {
                int col;
                for(int k=0;k<500;k++)
                {
                    if (mat[i][k]=='\0'){
                        col=k;
                        break;
                    }
                }
                int r,c;
                char o;
                c=tbl[i][j]-'0';
                j+=2;
                r=tbl[i][j]-'0';
                j+=2;
                o=tbl[i][j];
                j+=2;
                for (int k=i; k<i+r; k++)
                {
                    for (int f=0; f<c; f++)
                    {
                        mat[k][col+f]=o;
                    }
                }
            }
        }
        vector<string>ret;
        for (int i=0;i<mat.size();i++){
                string a="";
            for(int j=0;j<mat[i].size();j++){
                if (mat[i][j]!='\0')
                    a+=mat[i][j];
            }
            if (a.size())
                ret.push_back(a);
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
