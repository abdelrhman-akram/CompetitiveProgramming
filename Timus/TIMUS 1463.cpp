#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> vec;
vector<vector<pair<int, ll > > > g;
ll ma = -1, far, ans = 0;
vector<int> temp, path;
bool vis[50005];
void dfs(int node, ll val, int par)
{
	if (ma < val)
		ma = val, far = node;
	vis[node] = 1;
	for (int i = 0; i < g[node].size(); i++)
	{
		if (g[node][i].first != par)
			dfs(g[node][i].first,
					val + g[node][i].second + vec[g[node][i].first], node);
	}
}
void dfs2(int node, ll val, int par)
{
	if (ans < val)
		ans = val, path = temp;
	vis[node] = 1;
	for (int i = 0; i < g[node].size(); i++)
		if (g[node][i].first != par)
			temp.push_back(g[node][i].first), dfs2(g[node][i].first,
					val + g[node][i].second + vec[g[node][i].first], node), temp.pop_back();
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, k;
	cin >> n >> k;
	vec.resize(n + 1);
	g.resize(n + 1);
	memset(vis, false, sizeof vis);
	for (int i = 1; i <= n; i++)
		cin >> vec[i];
	for (int i = 0; i < k; i++)
	{
		int a, b;
		ll c;
		cin >> a >> b >> c;
		g[a].push_back(make_pair(b, c));
		g[b].push_back(make_pair(a, c));
	}

	for (int i = 1; i <= n; i++)
	{
		if (vis[i])
			continue;
		ma = -1;
		dfs(i, vec[i], -1);
		temp.push_back(far);
		dfs2(far, vec[far], -1);
		temp.clear();
	}
	cout << ans << endl;
	cout << path.size() << endl;
	for (int i = 0; i < path.size(); i++)
	{
		if (i)
			cout << " ";
		cout << path[i];
	}
	return 0;
}
