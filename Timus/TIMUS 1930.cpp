#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e4 + 5;
int cost[N];
vector<vector<pair<int, int> >> g(N);
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(make_pair(v, 1));
		g[v].push_back(make_pair(u, 0));
	}
	int s, di;
	cin >> s >> di;
	for (int i = 0; i < N; i++)
		cost[i] = 2e9;
	cost[s] = 0;
	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push(make_pair(0, make_pair(s, -1)));
	while (pq.size())
	{
		int node = pq.top().second.first, d = pq.top().second.second;
		pq.pop();
		for (int i = 0; i < g[node].size(); i++)
		{
			int v = g[node][i].first, c =
					(g[node][i].second == d || d == -1) ? 0 : 1;
			if (cost[v] > cost[node] + c)
			{
				cost[v] = cost[node] + c;
				pq.push(make_pair(-cost[v], make_pair(v, g[node][i].second)));
			}
		}
	}
	cout << cost[di];
	return 0;
}
