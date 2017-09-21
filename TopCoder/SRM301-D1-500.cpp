#include <bits/stdc++.h>
#define ll long long
using namespace std;
int cost[55][55], INF = 1e9;
class EscapingJail
{
public:
	int getMaxDistance(vector<string> chain)
	{

		for (int i = 0; i < chain.size(); i++)
			for (int j = 0; j < chain[i].size(); j++)
			{
				if (chain[i][j] == ' ')
				{
					cost[i][j] = INF;
					continue;
				}
				if (isdigit(chain[i][j]))
				{
					cost[i][j] = chain[i][j] - '0';
					continue;
				}
				if (chain[i][j] >= 'a' && chain[i][j] <= 'z')
				{
					cost[i][j] = chain[i][j] - 'a' + 10;
					continue;
				}
				cost[i][j] = chain[i][j] - 'A' + 36;
			}
		int n = chain.size();
		for (int k = 0; k < n; k++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);

		int ma = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				ma = max(ma, cost[i][j]);
		return (ma == INF) ? -1 : ma;
	}
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	return 0;
}
