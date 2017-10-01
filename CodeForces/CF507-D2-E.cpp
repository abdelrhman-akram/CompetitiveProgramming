#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;
vector<vector<pair<int, int>>> g(N);
bool vis[N];
struct info
{
	int level, k, par;
	info()
	{
		level = 1e8, k = 1e8, par = 0;
	}
};
info parent[N];
vector<int> path;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m, u, v, z;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v >> z;
		g[u].push_back(make_pair(v, z));
		g[v].push_back(make_pair(u, z));
	}
	queue<int> qu;
	qu.push(1);
	parent[1].level = parent[1].k = 0;
	while (qu.size())
	{
		int node = qu.front();
		qu.pop();
		for (int i = 0; i < g[node].size(); i++)
		{
			v = g[node][i].first;
			if (parent[v].level >= parent[node].level + 1)
			{
				parent[v].level = parent[node].level + 1;
				if (parent[v].k > parent[node].k + (!g[node][i].second))
				{
					parent[v].k = parent[node].k + (!g[node][i].second);
					parent[v].par = node;
					qu.push(v);
				}
			}
		}
	}
	int temp = n;
	while (true)
	{
		path.push_back(temp);
		if (temp == 1)
			break;
		temp = parent[temp].par;
	}
	map<pair<int, int>, int> mapp;
	for (int i = 0; i < path.size() - 1; i++)
	{
		mapp[make_pair(min(path[i], path[i + 1]), max(path[i], path[i + 1]))] =
				1;
	}
	vector<pair<int, pair<int, int>>> out;
	map<pair<int, int>, int> mapp1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < g[i].size(); j++)
		{
			if (mapp1[make_pair(min(i, g[i][j].first), max(i, g[i][j].first))])
				continue;
			mapp1[make_pair(min(i, g[i][j].first), max(i, g[i][j].first))] = 1;
			if (mapp.find(
					make_pair(min(i, g[i][j].first), max(i, g[i][j].first)))
					!= mapp.end() && g[i][j].second == 0)
				out.push_back(make_pair(i, make_pair(g[i][j].first, 1)));
			if (mapp.find(
					make_pair(min(i, g[i][j].first), max(i, g[i][j].first)))
					== mapp.end() && g[i][j].second == 1)
				out.push_back(make_pair(i, make_pair(g[i][j].first, 0)));
		}
	}
	cout << out.size() << endl;
	for (int i = 0; i < out.size(); i++)
	{
		cout << out[i].first << " " << out[i].second.first << " "
				<< out[i].second.second << endl;
	}
	return 0;
}
