#include <bits/stdc++.h>
#define ll long long
using namespace std;
double dis[1005], eps = 1e-9;
int vis[1005];
vector<pair<double, pair<double, double>> > vec(1005);
double two(double one)
{
	return one * one;
}
double get_dist(int ind1, int ind2)
{
	return max(0.0,
			sqrt(
					two((vec[ind1].first - vec[ind2].first))
							+ two(
									vec[ind1].second.first
											- vec[ind2].second.first))
					- (vec[ind1].second.second + vec[ind2].second.second));
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	memset(vis, false, sizeof vis);
	for (int i = 0; i <= 1002; i++)
		dis[i] = 1e18;
	int n, x1, x2, x3, x4;
	cin >> x1 >> x2 >> x3 >> x4 >> n;
	for (int i = 1; i <= n; i++)
		cin >> vec[i].first >> vec[i].second.first >> vec[i].second.second;
	vec[0].first = x1;
	vec[0].second.first = x2;
	vec[n + 1].first = x3;
	vec[n + 1].second.first = x4;
	vec[0].second.second = vec[n + 1].second.second = 0;
	priority_queue<pair<double, int> > pq;
	dis[0] = 0;
	pq.push(make_pair(0.0, 0));
	while (pq.size())
	{
		int ind = pq.top().second;
		pq.pop();
		if (vis[ind])
			continue;
		vis[ind] = 1;
		for (int i = 0; i <= n + 1; i++)
		{
			if (i == ind)
				continue;
			double temp = get_dist(ind, i);
			if (dis[i] - (temp + dis[ind]) > eps)
			{
				dis[i] = temp + dis[ind];
				pq.push(make_pair(-dis[i], i));
			}
		}
	}
	cout << fixed << setprecision(9) << dis[n + 1];
	return 0;
}
