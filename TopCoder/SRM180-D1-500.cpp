#include <bits/stdc++.h>
#define ll long long
using namespace std;
int vis[55][55];
vector<vector<pair<int, int> > > vec,nextvec;
void inti(int n)
{
    vec.resize(n);
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            vec[i].push_back(make_pair(i,j));
    for (int j=0; j<n; j++)
    {
        vector<pair<int,int > > temp;
        for (int i=n-1; i>=0; i--)
            temp.push_back(make_pair(vec[i][j].first,vec[i][j].second));
        nextvec.push_back(temp);
    }
}
class SquareCode
{
public:
    vector <string> completeIt(vector <string> grille)
    {
        vector<string> ret;
        inti(grille.size());
        for (int i=0; i<grille.size(); i++)
        {
            for (int j=0; j<grille[i].size(); j++)
            {
                if (grille[i][j]=='.')
                {
                    vis[i][j]++;
                    if (vis[i][j]>1)
                        return ret;
                    int r=i,c=j;
                    for (int k=0; k<3; k++)
                    {
                        int nr,nc;
                        for (int f=0; f<nextvec.size(); f++)
                            for (int ff=0; ff<nextvec.size(); ff++)
                            {
                                if (nextvec[f][ff].first==r&&nextvec[f][ff].second==c)
                                {
                                    nr=f;
                                    nc=ff;
                                    break;
                                }
                            }
                        vis[nr][nc]++;
                        if (vis[nr][nc]>1)return ret;
                        r=nr,c=nc;
                    }
                }
            }
        }
        for (int i=0; i<grille.size()/2; i++)
        {
            for (int j=0; j<grille.size()/2; j++)
            {
                if (vis[i][j])
                    continue;
                grille[i][j]='.';
                vis[i][j]++;
                if (vis[i][j]>1)
                    return ret;
                int r=i,c=j;
                for (int k=0; k<3; k++)
                {
                    int nr,nc;
                    for (int f=0; f<nextvec.size(); f++)
                        for (int ff=0; ff<nextvec.size(); ff++)
                        {
                            if (nextvec[f][ff].first==r&&nextvec[f][ff].second==c)
                            {
                                nr=f;
                                nc=ff;
                                break;
                            }
                        }
                    vis[nr][nc]++;
                    if (vis[nr][nc]>1)return ret;
                    r=nr,c=nc;
                }
            }
        }
        return grille;
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    return 0;
}
