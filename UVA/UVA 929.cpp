#include <bits/stdc++.h>
#define ll long long
using namespace std;
int grid[1000][1000], cost[1000][1000], n, m;
bool valid(int r, int c)
{
	return r >= 0 && r < n && c >= 0 && c < m;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				cin >> grid[i][j];
				cost[i][j] = 1e9;
			}
		cost[0][0] = grid[0][0];
		priority_queue<pair<int, pair<int, int>>> pq;
		pq.push(make_pair(grid[0][0], make_pair(0, 0)));
		while (pq.size())
		{
			int r = pq.top().second.first, c = pq.top().second.second;
			pq.pop();
			if (valid(r, c + 1))
			{
				if (cost[r][c + 1] > cost[r][c] + grid[r][c + 1])
				{
					cost[r][c + 1] = cost[r][c] + grid[r][c + 1];
					pq.push(make_pair(-cost[r][c + 1], make_pair(r, c + 1)));
				}

			}
			if (valid(r, c - 1))
			{
				if (cost[r][c - 1] > cost[r][c] + grid[r][c - 1])
				{
					cost[r][c - 1] = cost[r][c] + grid[r][c - 1];
					pq.push(make_pair(-cost[r][c - 1], make_pair(r, c - 1)));
				}

			}
			if (valid(r + 1, c))
			{
				if (cost[r + 1][c] > cost[r][c] + grid[r + 1][c])
				{
					cost[r + 1][c] = cost[r][c] + grid[r + 1][c];
					pq.push(make_pair(-cost[r + 1][c], make_pair(r + 1, c)));
				}
			}
			if (valid(r - 1, c))
			{
				if (cost[r - 1][c] > cost[r][c] + grid[r - 1][c])
				{
					cost[r - 1][c] = cost[r][c] + grid[r - 1][c];
					pq.push(make_pair(-cost[r - 1][c], make_pair(r - 1, c)));
				}
			}

		}
		cout << cost[n - 1][m - 1] << '\n';
	}
	return 0;

}
