#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 4e6 + 5;
int tree[N], k, n;
void build(int i, int l, int r)
{
	if (l == r)
	{
		tree[i] = k;
		return;
	}
	int mid = (l + r) >> 1;
	build(i * 2, l, mid);
	build(i * 2 + 1, mid + 1, r);
	tree[i] = max(tree[i * 2], tree[i * 2 + 1]);
}
bool flag;
void update(int i, int l, int r, int c)
{
	if (tree[i] < c || flag)
		return;
	if (l == r)
	{
		tree[i] -= c;
		flag = 1;
		return;
	}
	int mid = (l + r) >> 1;
	update(i * 2, l, mid, c);
	update(i * 2 + 1, mid + 1, r, c);
	tree[i] = max(tree[i * 2], tree[i * 2 + 1]);
}
int used, waste;
void sol(int i, int l, int r)
{
	if (l == r)
	{
		if (tree[i] < k)
			used++, waste += tree[i];
		return;
	}
	int mid = (l + r) >> 1;
	sol(i * 2, l, mid);
	sol(i * 2 + 1, mid + 1, r);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		cin >> k >> n;
		build(1, 0, n - 1);
		int temp = n;
		while (temp)
		{
			string v;
			cin >> v;
			flag = 0;
			if (isdigit(v[0]))
			{
				stringstream ss(v);
				int t;
				ss >> t;
				update(1, 0, n - 1, t);
				temp--;
			}
			else
			{
				int ne, c;
				cin >> ne >> c;
				while (ne--)
				{
					flag = 0;
					update(1, 0, n - 1, c);
					temp--;
				}
			}
		}
		used = waste = 0;
		sol(1, 0, n - 1);
		cout << used << " " << waste << endl;
	}
	return 0;
}
