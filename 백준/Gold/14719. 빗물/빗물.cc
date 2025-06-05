#include<iostream>
#include<vector>
#include<algorithm>



using namespace std;


int h, w;
int ret = 0;

vector<vector<int>>v;
vector<int>block;

void print()
{
	cout << "\n";
	for (int i = 1; i <= w; i++)
	{
		cout << block[i]<<" ";
	}
	cout << "\n";
	cout << "\n";
	for (int i = 1; i <=h;i++)
	{
		for (int j = 1; j <= w; j++)
		{
			cout << v[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> h >> w;
	
	v.resize(h+1, vector<int>(w+1));

	block.push_back(0);

	for (int i = 0; i < w; i++)
	{
		int a;
		cin >> a;
		block.push_back(a);
	}
	int tmp = 0;

	for (int i = h; i > 0; i--)
	{
		int temp = 0;
		int cnt = 0;
		for (int j = 1; j <= w; j++)
		{
			//v[i][j] = tmp++;
			if (block[j] >= h-i+1)
			{
				v[i][j] = 1;
				if (cnt == 1)
				{
					if (temp > 0)
					{
						//cout << "\n" << i << " " << j << " \n";
						ret += temp;
						temp = 0;
						cnt = 1;
					}
				}
				else
				{
					temp = 0;
					cnt++;
				}
			}
			else
			{
				if (cnt == 1)
				{
					//cout << "\n" << i << " " << j << " \n";
					temp++;
				}
			}
		}
	}
	//print();
	cout << ret;
	return 0;
}