#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int n, m, j;
int ret = 0;
int cntmin = 1;
int cntmax = 1;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> j;
	cntmax = m;
	for (int i = 0; i < j; i++)
	{
		//cout << "\n";
		int a;
		cin >> a;
		
		if (a<=cntmax&&a >= cntmin)
		{
		}
		else if (a < cntmin)
		{
			int temp = abs(a - cntmin);
			cntmin -= temp;
			cntmax -= temp;
			ret += temp;
		}
		else if (a > cntmax)
		{
			//cout << abs(a - cntmax) << " ";
			//cout << "asdasfd";
			int temp = abs(a - cntmax);
			cntmin += temp;
			cntmax += temp;
			ret += temp;
			//cout << " " << abs(a - cntmax) << "\n";
		}

		//cout << a << " " << cntmin << " " << cntmax << "\n";
		//ret += abs(a - cntmin);
		//cout <<" "<< ret<<"\n";
	}
	cout << ret;
	
	return 0;
}