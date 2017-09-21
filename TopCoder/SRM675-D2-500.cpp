#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;
vector<string> g;
double dp[51][11][51], mi = 2e9;
double solve(int node, int cost, int k, int flag)
{
	if (cost > 10 || cost > mi || cost > g[0][1] - '0')
		return 2e9;
	if (flag == 2)
		cost++;
	flag %= 2;
	if (node == 1)
		return 0;
	double &c = dp[node][cost][k];
	if (c == c)
		return c;
	c = 2e9;
	for (int i = 0; i < n; i++)
	{
		if (i == node)
			continue;
		if (g[node][1] - '0' < g[node][i] - '0')
			continue;
		c = min(c,
				solve(i, cost + g[node][i] - '0', k, flag)
						+ (g[node][i] - '0') * 1.0);
		if (k)
			c = min(c,
					solve(i, cost + (g[node][i] - '0') / 2, k - 1,
							((g[node][i] - '0') % 2 == 0) ? flag : flag + 1)
							+ (g[node][i] - '0') / 2.0);
	}
	return c;
}
class ShortestPathWithMagic
{
public:
	double getTime(vector<string> dist, int k)
	{
		memset(dp, -1, sizeof dp);
		n = dist.size();
		g = dist;
		double ret = solve(0, 0, k, 0);
		return ret;
	}
};
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	return 0;

}
