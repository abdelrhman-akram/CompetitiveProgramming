#include <bits/stdc++.h>
#define ll long long
using namespace std;
int g[55][55], INF = 1e8;
class ComboBoxKeystrokes
{
public:
	int minimumKeystrokes(vector<string> elements)
	{
		for (int i = 0; i < elements.size(); i++)
			elements[i][0] = tolower(elements[i][0]);
		for (int i = 0; i < 55; i++)
			for (int j = 0; j < 55; j++)
				g[i][j] = INF;
		for (int i = 0; i < 55; i++)
			g[i][i] = 0;
		int n = elements.size();
		for (int i = 0; i < elements.size(); i++)
		{
			int arr[27];
			memset(arr, 0, sizeof arr);
			int z = 1;
			for (int j = i + 1; z < n; j++)
			{
				j %= n;
				arr[elements[j][0] - 'a']++;
				g[i][j] = arr[elements[j][0] - 'a'];
				z++;
			}
		}
		for (int k = 0; k < n; k++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
		int ans = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				ans = max(ans, g[i][j]);
		return ans;
	}
};
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	return 0;
}
