#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

vector<vector<int>>v;
int n, m;
int ret;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	v.resize(n, vector<int>(m));
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			v[i][j] = s[j] - '0';
		}
	}

	for (int i = 0; i < (1 << (n * m)); i++)
	{
		int sum = 0;
		for (int y = 0; y < n; y++)
		{
			string s;
			for (int x = 0; x < m; x++)
			{
				if (i & (1<<(m*y+x)))
				{
					s.push_back(v[y][x] + '0');
				}
				else
				{
					if (!s.empty())
					{
						sum += stoi(s);
					}
					s = "";
				}

			}
			if (!s.empty())
			{
				sum += stoi(s);
			}
		}

		for (int x = 0; x < m; x++)
		{
			string s;
			for (int y = 0; y < n; y++)
			{
				if (i & (1 << (m * y + x)))
				{
					if (!s.empty())
					{
						sum += stoi(s);
					}
					s = "";

				}
				else
				{
					s.push_back(v[y][x] + '0');
				}

			}
			if (!s.empty())
			{
				sum += stoi(s);
			}
		}
		ret = max(sum, ret);
	}
	cout << ret;
	return 0;
}