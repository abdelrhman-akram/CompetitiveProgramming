#include <bits/stdc++.h>
#define ll long long
using namespace std;
int g[505][505];
const int INF = 1e8, N = 1e5 + 5;
vector<vector<int> > adj(N);
int vis[N], id = 1;
void dfs(int node)
{
	if (vis[node] == id)
		return;
	vis[node] = id;
	for (int i = 0; i < adj[node].size(); i++)
		dfs(adj[node][i]);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> vec(k), indx(n + 5);
	memset(vis, false, sizeof vis);
	for (int i = 0; i < k; i++)
		cin >> vec[i];
	int ind = 1;

	for (int i = 0; i <= k; i++)
		for (int j = 0; j <= k; j++)
			g[i][j] = INF;
	for (int i = 0; i < k; i++)
		for (int j = 0; j < vec[i]; j++)
		{
			indx[ind] = i + 1, ind++;
			if (vec[i] == 1)
				g[i + 1][i + 1] = 0;
		}
	for (int i = 0; i < m; i++)
	{
		int u, v, x;
		cin >> u >> v >> x;
		if (!x)
		{
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		g[indx[u]][indx[v]] = min(g[indx[u]][indx[v]], x);
		g[indx[v]][indx[u]] = min(g[indx[v]][indx[u]], x);
	}
	ind = 1;
	for (int i = 0; i < k; i++)
	{
		id++;
		dfs(ind);
		for (int j = ind; ind < j + vec[i]; ind++)
			if (vis[ind] != id)
				return cout << "No", 0;
	}
	for (int w = 1; w <= k; w++)
		for (int i = 1; i <= k; i++)
			for (int j = 1; j <= k; j++)
				g[i][j] = min(g[i][j], g[i][w] + g[w][j]);
	for (int i = 1; i <= k; i++)
		if (g[i][i] != 0)
			return cout << "No", 0;
	cout << "Yes" << endl;
	for (int i = 1; i <= k; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			if (g[i][j] == INF)
				g[i][j] = -1;
			cout << g[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
