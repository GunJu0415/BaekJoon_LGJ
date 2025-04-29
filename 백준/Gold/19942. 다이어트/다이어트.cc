#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

int n, k;
int mp, mf, ms, mv;
int mpsum, mfsum, mssum, mvsum;
int cnt = 0;
int ans = 1e9;
vector<vector<int>>v;
vector<int> temp;
vector<int> sel;
int items = 1e9;

int comp[24];



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	cin >> mp>> mf>> ms>> mv;

	v.resize(n+1, vector<int>(5));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> v[i][j];
		}
	}

	for (int i = 1; i < (1 << n); i++)
	{
		temp.clear();
		mpsum = 0, mfsum = 0, mssum = 0, mvsum = 0;
		cnt = 0;


		memset(comp, 0, size(comp));
		for (int j = 0; j < n; j++)
		{
			if (i & (1 << j))
			{
				temp.push_back(j+1);
				mpsum += v[j+1][0];
				mfsum += v[j+1][1];
				mssum += v[j+1][2];
				mvsum += v[j+1][3];
				cnt += v[j+1][4];
			}
		}
		//for (int j = 1; j <= n; j++)
		//{
		//	if (comp[j] == 0)
		//	{
		//		continue;
		//	}

		//}

		
		if (mp <= mpsum && mf <= mfsum && ms <= mssum && mv <= mvsum)
		{
			if (ans > cnt)
			{
				sel.clear();
				sel = temp;
				ans = cnt;
			}
			else if (ans == cnt)
			{
				if (temp < sel) // 방향 반대
				{
					sel = temp; // clear() 안 해도 됨 (어차피 대입하면 덮어써짐)
				}
			}
		}
	}

	if (ans == 1e9)
	{
		cout << -1;
		return 0;
	}

	cout << ans << "\n";
	//sort(sel.begin(), sel.end());
	for (int i  = 0;i< sel.size();i++)
	{
		cout << sel[i] << " ";
	}
	return 0;
}