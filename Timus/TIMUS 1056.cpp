#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<vector<int> > g(10005);
int ma = 0, far;
void dfs(int depth, int node, int par = -1)
{
	if (depth > ma)
		ma = depth, far = node;
	for (int i = 0; i < g[node].size(); i++)
	{
		if (g[node][i] != par)
			dfs(depth + 1, g[node][i], node);
	}
}
deque<int> temp, path;
void dfs2(int depth, int node, int par = -1)
{
	if (depth == ma)
		path = temp;
	for (int i = 0; i < g[node].size(); i++)
	{
		if (g[node][i] != par)
		{
			temp.push_back(g[node][i]);
			dfs2(depth + 1, g[node][i], node);
			temp.pop_back();
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, a;
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		cin >> a;
		g[i].push_back(a);
		g[a].push_back(i);
	}
	dfs(0, 1);
	int x = far;
	ma = 0;
	dfs(0, x, -1);
	dfs2(0, x, -1);
	path.push_front(x);
	if (path.size() % 2 == 0)
	{
		cout << path[path.size() / 2] << " " << path[path.size() / 2 - 1];
	}
	else
		cout << path[path.size() / 2];
	return 0;
}
