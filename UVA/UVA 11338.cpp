#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<pair<double, double>> vec(10005);
double two(double a)
{
	return a * a;
}
double dist(int ind1, int ind2)
{
	return sqrt(
			two(vec[ind1].first - vec[ind2].first)
					+ two(vec[ind1].second - vec[ind2].second));
}
double cost[10005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	double w, h;
	while (cin >> w >> h)
	{
		vec.clear();
		int n;
		cin >> n;
		vec.resize(10005);
		for (int i = 0; i <= n + 2; i++)
			cost[i] = 2e18;
		for (int i = 1; i <= n; i++)
			cin >> vec[i].first >> vec[i].second;
		vec[0].first = vec[0].second = 0;
		vec[n + 1].first = w, vec[n + 1].second = h;
		double d;
		cin >> d;
		priority_queue<pair<double, int> > pq;
		pq.push(make_pair(0.0, 0));
		cost[0] = 0;
		while (pq.size())
		{
			int node = pq.top().second;
			pq.pop();
			for (int i = 0; i <= n + 1; i++)
			{
				if (i == node)
					continue;
				double dis = dist(node, i);
				if (1.5 >= dis)
				{
					if (cost[i] > (cost[node] + dis))
						cost[i] = cost[node] + dis, pq.push(
								make_pair(-cost[i], i));
				}
			}
		}
		if (d >= cost[n + 1])
			cout << "I am lucky!" << '\n';
		else
			cout << "Boom!" << '\n';
	}
	return 0;
}
