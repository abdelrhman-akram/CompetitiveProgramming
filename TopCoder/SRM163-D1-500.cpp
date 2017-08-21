#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Pool
{
public:
    int rackMoves(vector <int> triangle)
    {
        vector<int>vec1,vec2;
        for (int i=1; i<=5; i++)
        {
            for (int j=0; j<i; j++)
            {
                if (i==5&&j==4)
                {
                    vec1.push_back(1),vec2.push_back(0);
                    break;
                }
                if (i%2==1)
                {
                    if (j%2==0)
                        vec1.push_back(0),vec2.push_back(1);
                    if (i==3&&j%2==1)
                        vec1.push_back(8),vec2.push_back(8);
                    else if (j%2==1)
                        vec1.push_back(1),vec2.push_back(0);
                }
                else
                {
                    if (i==2)
                        vec1.push_back(1),vec2.push_back(0);
                    else if (j%2==1)
                        vec1.push_back(0),vec2.push_back(1);
                    else if (j%2==0)
                        vec1.push_back(1),vec2.push_back(0);
                }
            }
        }
        for (int i=0; i<triangle.size(); i++)
        {
            if (triangle[i]<8)
                triangle[i]=0;
            else if (triangle[i]>8)
                triangle[i]=1;
        }
        int mi=1e9;
        vector<int> vec3=triangle;
        int c=0;
        for (int i=0; i<triangle.size(); i++)
        {
            if (triangle[i]!=vec2[i])
            {
                for (int j=0; j<triangle.size(); j++)
                {
                    if (i==j)
                        continue;
                    if (triangle[j]!=vec2[j]&&triangle[j]==vec2[i]&&triangle[i]==vec2[j])
                    {
                        swap(triangle[j],triangle[i]);
                        c++;
                        break;
                    }
                }
            }
        }
        if(triangle[4]!=8)
            c+=2;
        mi=min(mi,c);
        triangle=vec3;
        c=0;
        for (int i=0; i<triangle.size(); i++)
        {
            if (triangle[i]!=vec1[i])
            {
                for (int j=0; j<triangle.size(); j++)
                {
                    if (i==j)
                        continue;
                    if (triangle[j]!=vec1[j]&&triangle[j]==vec1[i]&&triangle[i]==vec1[j])
                    {
                        swap(triangle[j],triangle[i]);
                        c++;
                        break;
                    }
                }
            }
        }
        if (triangle[4]!=8)
            c+=2;
        mi=min(mi,c);
        return mi;
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    return 0;
}
