#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, m, s, l;
const int N = 2e5 + 10, INF = 2e9;
vector<vector<pair<int, int> > > g(N);
set<pair<int, pair<int, int> > > sett;
int cost[N];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> s;
	for (int i = 0; i < m; i++)
	{
		int u, v, c;
		cin >> u >> v >> c;
		g[u].push_back(make_pair(v, c));
		g[v].push_back(make_pair(u, c));
	}
	cin >> l;
	for (int i = 0; i < N; i++)
		cost[i] = INF;
	cost[s] = 0;
	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(0, s));
	while (pq.size())
	{
		int node = pq.top().second;
		pq.pop();
		for (int i = 0; i < g[node].size(); i++)
		{
			int v = g[node][i].first, c = g[node][i].second;
			if (cost[v] > cost[node] + c)
				cost[v] = cost[node] + c, pq.push(make_pair(-cost[v], v));
		}
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (cost[i] == l)
			ans++;
		if (cost[i] >= l)
			continue;
		int z = l - cost[i];
		for (int j = 0; j < g[i].size(); j++)
		{
			if (g[i][j].second > z)
			{
				int v = g[i][j].first, temp = l - cost[v];
				int temp2 = l - temp;
				if (cost[v] + (g[i][j].second - z) < cost[i] + z)
					continue;
				bool flag = 0;
				if (i < g[i][j].first)
					flag = 1;
				//	cout << i << " " << g[i][j].first << " " << z << endl;
				sett.insert(
						make_pair(min(i, g[i][j].first),
								make_pair(max(i, g[i][j].first),
										(flag) ? z : g[i][j].second - z)));
			}
		}
	}
	cout << ans + sett.size();
	return 0;
}
