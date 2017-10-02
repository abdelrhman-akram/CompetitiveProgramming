#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<vector<int>> g, cleared(1e6 + 4, vector<int>(2));
set<string> sett;
void dfs(int node, int ins)
{
	if (ins > node)
	{
		if (!g[node][1])
			g[node][1] = ins;
		else
			dfs(g[node][1], ins);
	}
	if (ins < node)
	{
		if (!g[node][0])
			g[node][0] = ins;
		else
			dfs(g[node][0], ins);
	}
}
string dfs2(int node)
{
	string temp = "";
	if (g[node][0])
	{
		temp += "l";
		temp += dfs2(g[node][0]);
	}
	temp += "o";
	if (g[node][1])
	{
		temp += "r";
		temp += dfs2(g[node][1]);
	}
	return temp;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, k;
	while (cin >> n >> k)
	{
		sett.clear();
		while (n--)
		{
			g = cleared;
			int root;
			cin >> root;
			int tempk = k;
			while (--tempk)
			{
				int u;
				cin >> u;
				dfs(root, u);
			}
			sett.insert(dfs2(root));
		}
		cout << sett.size() << endl;
	}

	return 0;
}
