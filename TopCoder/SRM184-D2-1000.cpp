#include <bits/stdc++.h>
#define ll long long
using namespace std;
int g[60][60], INF = 1e8;
class TeamBuilder
{
public:
	vector<int> specialLocations(vector<string> paths)
	{
		for (int i = 0; i < paths.size(); i++)
			for (int j = 0; j < paths.size(); j++)
				g[i][j] = (paths[i][j] == '1' ? 0 : INF);
		for (int i = 0; i < paths.size(); i++)
			g[i][i] = 0;
		int n = paths.size();
		for (int k = 0; k < n; k++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
		vector<int> ret(2);
		for (int i = 0; i < n; i++)
		{
			int c = 0, c2 = 0;
			for (int j = 0; j < n; j++)
			{
				if (g[i][j] != INF)
					c++;
				if (g[j][i] != INF)
					c2++;
			}

			if (c == n)
				ret[0]++;
			if (c2 == n)
				ret[1]++;
		}
		return ret;
	}
};
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	return 0;
}
