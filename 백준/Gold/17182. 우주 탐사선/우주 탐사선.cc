#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int ret = 1e9;
int n;
int st;
int dist[14][14];

vector<int>temp;



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> st;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> dist[i][j];
		}
	}


	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i == j)
				{
					continue;
				}
				if (dist[i][k] != 1e9 && dist[k][j] != 1e9)
				{ 
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (i == st)
		{
			continue;
		}
		temp.push_back(i);
	}

	do
	{
		int sum = 0;
		int left = st, right;
		for (int i : temp)
		{
			right = i;
			sum += dist[left][right];
			left = i;
		}
		ret = min(sum, ret);

	} while (next_permutation(temp.begin(),temp.end()));

	cout << ret;
	return 0;
}