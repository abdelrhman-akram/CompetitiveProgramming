#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m;
	while (cin >> n >> m)
	{
		if (n == 0 && m == 0)
			break;
		int x, y, k, u, v, l;
		cin >> x >> y >> k;
		vector<vector<pair<int, ll>>> g(n+2);
		for (int i = 0; i < m; i++)
		{
			cin >> u >> v >> l;
			g[u].push_back(make_pair(v, l * 1ll));
		}
		priority_queue<pair<ll, int> > pq;
		pq.push(make_pair(0ll, x));
		vector<ll> res;
		int cont[101];
		memset(cont, 0, sizeof cont);
		ll ans = -1;
		while (pq.size())
		{
			int node = pq.top().second;
			ll t = -pq.top().first;
			pq.pop();
			if (cont[node] > k)
				continue;
			cont[node]++;
			if (node == y && cont[y] == k)
			{
				ans = t;
				break;
			}
			for (int i = 0; i < g[node].size(); i++)
			{
				v = g[node][i].first;
				ll temp = g[node][i].second;
				pq.push(make_pair(-(temp + t), v));
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
