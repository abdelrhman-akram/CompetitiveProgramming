#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Table
{
public:
    vector <string> layout(vector <string> tbl)
    {
        vector<string> mat;
        int mc=0,mr=0;
        for (int i=0;i<tbl.size();i++){
                if (tbl[i].size()==0)
                continue;
                int c=0,r=0;
            for (int j=1;j<tbl.size();j++){
                c+=(tbl[i][j]-'0');
                j+=2;
                r=max(r,tbl[i][j]-'0');
                j+=2;
                j+=2;
            }
            mc=max(c,mc);
            mr=max(mr,i+r);
        }
        mat.resize(60);
        for (int i=0;i<mat.size();i++)
            mat[i].resize(60);
        for (int i=0; i<(int)tbl.size(); i++)
        {

            if (tbl[i].size()==0)
                continue;
            for (int j=1; j<(int)tbl[i].size(); j++)
            {
                int col;
                for(int k=0;k<tbl[i].size();k++)
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

                col+=c;
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
