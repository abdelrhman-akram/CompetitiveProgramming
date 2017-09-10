#include <bits/stdc++.h>
#define ll long long
using namespace std;
map<string, int> indx;
string routes[101][101];
int g[101][101], path[101][101];
const int INF = 1e8;
vector<pair<string, string> > reports;
vector<string> cities(110);
struct info
{
	string from, to, route;
	int cost;
};
vector<info> ret;
void solve(int i, int j)
{
	if (i != j)
		solve(i, path[i][j]);
	info temp;
	temp.from = cities[path[i][j]], temp.to = cities[j], temp.route =
			routes[path[i][j]][j], temp.cost = g[path[i][j]][j];
	ret.push_back(temp);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	string line;
	int ind = 0;
	for (int i = 0; i < 101; i++)
		for (int j = 0; j < 101; j++)
			g[i][j] = INF;

	while (getline(cin, line) && line.size())
	{
		string u = "", v = "", route = "";
		int cost = 0;
		int j = 0;
		while (line[j] != ',')
			u += line[j], j++;
		j++;
		while (line[j] != ',')
			v += line[j], j++;
		j++;
		while (line[j] != ',')
			route += line[j], j++;
		j++;
		while (j < (int) line.size() && isdigit(line[j]))
			cost *= 10, cost += line[j] - '0', j++;
		if (indx.find(u) == indx.end())
			cities[ind] = u, indx[u] = ind++;
		if (indx.find(v) == indx.end())
			cities[ind] = v, indx[v] = ind++;
		int indu = indx[u], indv = indx[v];
		if (g[indu][indv] > cost)
		{
			g[indu][indv] = cost;
			routes[indu][indv] = route;
		}
		if (g[indv][indu] > cost)
		{
			g[indv][indu] = cost;
			routes[indv][indu] = route;
		}
	}

	for (int i = 0; i < 101; i++)
		for (int j = 0; j < 101; j++)
			path[i][j] = i;
	for (int i = 0; i < 101; i++)
		g[i][i] = 0;
	for (int k = 0; k < ind; k++)
		for (int i = 0; i < ind; i++)
			for (int j = 0; j < ind; j++)
			{
				if (g[i][j] > g[i][k] + g[k][j])
				{
					g[i][j] = g[i][k] + g[k][j];
					path[i][j] = path[k][j];
				}
			}
	while (getline(cin, line) && line.size())
	{
		string u = "", v = "";
		int j = 0;
		while (line[j] != ',')
			u += line[j], j++;
		j++;
		while (line[j] != ',' && j < line.size())
			v += line[j], j++;
		reports.push_back(make_pair(u, v));
	}
	for (int i = 0; i < reports.size(); i++)
	{
		ret.clear();
		cout << endl;
		cout << endl;
		string temp =
				"From                 To                   Route      Miles";
		string endd =
				"                                                     -----";
		cout << temp << endl;
		cout << "-------------------- -------------------- ---------- -----"
				<< endl;
		solve(indx[reports[i].first], indx[reports[i].second]);
		int t_cost = 0;
		for (int i = 1; i < ret.size(); i++)
		{
			for (int j = 0; j < temp.size() - 5; j++)
			{
				if (temp[j] == 'F')
				{
					cout << ret[i].from;
					int z = 0;
					while (z < ret[i].from.size() - 1)
						z++, j++;
				}
				else if (temp[j] == 'T')
				{
					cout << ret[i].to;
					int z = 0;
					while (z < ret[i].to.size() - 1)
						z++, j++;
				}
				else if (temp[j] == 'R')
				{
					cout << ret[i].route;
					int z = 0;
					while (z < ret[i].route.size() - 1)
						z++, j++;
				}
				else
					cout << ' ';
			}
			int cost = ret[i].cost;
			t_cost += cost;
			if (cost < 10)
				cout << "    " << cost;
			else if (cost < 100)
				cout << "   " << cost;
			else if (cost < 1000)
				cout << "  " << cost;
			else
				cout << ' ' << cost;
			cout << endl;
		}
		cout << endd << endl;
		cout << "                                          Total      ";
		int cost = t_cost;
		if (cost < 10)
			cout << "    " << cost;
		else if (cost < 100)
			cout << "   " << cost;
		else if (cost < 1000)
			cout << "  " << cost;
		else
			cout << ' ' << cost;
		cout<<endl;
	}
	return 0;
}
