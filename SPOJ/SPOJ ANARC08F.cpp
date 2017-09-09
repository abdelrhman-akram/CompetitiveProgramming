#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll g[101][101];
map<string, int> indx;
struct info
{
	string from, to;ll cost;
};
vector<info> vec;
const ll INF = 1e15;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int test = 1, n, c, r;
	while (cin >> n >> c >> r)
	{
		if (!n)
			break;
		memset(g, 0, sizeof g);
		vector<string> cars(c + 1);
		indx.clear();
		vec.clear();
		for (int i = 0; i <= c; i++)
			cin >> cars[i], indx[cars[i]] = 0;
		for (int i = 0; i < r; i++)
		{
			string u, v, arrow;
			int costt = 0;
			cin >> u >> arrow >> v;
			indx[u] = 0;
			indx[v] = 0;
			bool go = 0, back = 0;
			for (int j = 0; j < arrow.size(); j++)
			{
				if (arrow[j] >= '0' && arrow[j] <= '9')
					costt *= 10, costt += arrow[j] - '0';
				if (arrow[j] == '>')
					go = 1;
				if (arrow[j] == '<')
					back = 1;
			}
			if (go)
			{
				info temp;
				temp.from = u;
				temp.to = v;
				temp.cost = costt;
				vec.push_back(temp);
			}
			if (back)
			{
				info temp;
				temp.from = v;
				temp.to = u;
				temp.cost = costt;
				vec.push_back(temp);
			}
		}
		int ind = 0;
		for (map<string, int>::iterator it = indx.begin(); it != indx.end();it++)
			it->second = ind++;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				g[i][j] = INF;
		for (int i = 0; i < n; i++)
			g[i][i] = 0;
		for (int i = 0; i < vec.size(); i++)
		{
			ll u = indx[vec[i].from], v = indx[vec[i].to], costt = vec[i].cost;
			g[u][v] = min(g[u][v], costt);
		}
		for (int k = 0; k < n; k++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
		ll u = indx[cars[0]], ans = 0;
		for (int i = 1; i < cars.size(); i++)
		{
			int v = indx[cars[i]];
			ans += g[u][v];
			ans += g[v][u];
		}
		cout << test++ << ". " << ans << endl;
	}
	return 0;
}
