#include <bits/stdc++.h>
#define ll long long
using namespace std;
int far, ma = 0;
vector<vector<int> > g;
void dfs(int node, int depth, int par = -1)
{
	if (depth > ma)
		ma = depth, far = node;
	for (int i = 0; i < g[node].size(); i++)
		if (g[node][i] != par)
			dfs(g[node][i], depth + 1, node);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		g.clear();
		g.resize(n + 5);
		for (int i = 0; i < n; i++)
		{
			int m;
			cin >> m;
			while (m--)
			{
				int v;
				cin >> v;
				g[i].push_back(v - 1);
			}
		}
		ma = 0;
		dfs(0, 0);
		ma = 0;
		dfs(far, 0);
		cout << 2 * (n - 1) - ma << '\n';
	}
	return 0;
}
