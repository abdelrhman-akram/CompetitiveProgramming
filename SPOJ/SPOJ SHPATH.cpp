#include <bits/stdc++.h>
#define ll long long
using namespace std;
int cost[12345];
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
		map<string, int> indx;
		vector<vector<pair<int, int>> > g(n + 5);
		for (int i = 0; i < n; i++)
		{
			string name;
			int s;
			cin >> name >> s;
			indx[name] = i + 1;
			while (s--)
			{
				int v, l;
				cin >> v >> l;
				g[i + 1].push_back(make_pair(v, l));
			}
		}
		int r;
		cin >> r;
		while (r--)
		{
			string s, d;
			cin >> s >> d;
			int u = indx[s], v = indx[d];
			priority_queue<pair<int, int> > pq;
			for (int i = 0; i <= n; i++)
				cost[i] = 1e9;
			pq.push(make_pair(0, u));
			cost[u] = 0;
			while (pq.size())
			{
				int node = pq.top().second;
				if (node == v)
					break;
				pq.pop();
				for (int i = 0; i < g[node].size(); i++)
				{
					if (cost[g[node][i].first] > cost[node] + g[node][i].second)
					{
						cost[g[node][i].first] = cost[node] + g[node][i].second;
						pq.push(
								make_pair(-cost[g[node][i].first],
										g[node][i].first));
					}
				}
			}
			cout << cost[v] << '\n';
		}
		cin.ignore();
	}
	return 0;
}
