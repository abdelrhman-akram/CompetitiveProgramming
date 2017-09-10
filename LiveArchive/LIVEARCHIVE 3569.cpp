#include <bits/stdc++.h>
#define ll long long
using namespace std;
map<string, int> indx;
vector<pair<string, string> > vec;
int g[55][55];
const int INF = 1e8;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int p, r, test = 1;
	while (cin >> p >> r && p)
	{
		indx.clear();
		vec.clear();
		vec.resize(r);
		for (int i = 0; i < p; i++)
			for (int j = 0; j < p; j++)
				g[i][j] = INF;
		for (int i = 0; i < r; i++)
		{
			cin >> vec[i].first >> vec[i].second;
			indx[vec[i].first] = 0;
			indx[vec[i].second] = 0;
		}
		int ind = 0;
		for (map<string, int>::iterator it = indx.begin(); it != indx.end();it++)
			it->second = ind++;
		for (int i = 0; i < p; i++)
			g[i][i] = 1;
		for (int i = 0; i < vec.size(); i++)
		{
			int u = indx[vec[i].first], v = indx[vec[i].second];
			g[u][v] = 1;
			g[v][u] = 1;
		}
		for (int k = 0; k < p; k++)
			for (int i = 0; i < p; i++)
				for (int j = 0; j < p; j++)
					g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
		int ma = 0;
		for (int i = 0; i < p; i++)
			for (int j = 0; j < p; j++)
				ma = max(ma, g[i][j]);
		if (ma == INF)
			cout << "Network " << test++ << ": DISCONNECTED" << endl;
		else
			cout << "Network " << test++ << ": " << ma << endl;
		cout<<endl;
	}
	return 0;
}
