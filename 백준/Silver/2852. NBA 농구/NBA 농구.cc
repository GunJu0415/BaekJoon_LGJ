#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int n, aWinmm = 0, aWinss = 0, bWinmm = 0, bWinss = 0, nowWin = 0;
int ascore = 0, bscore = 0;

struct NBA {
	int t;
	int m;
	int s;
};
vector<NBA>v;

void go()
{
	int mm = -1, ss = -1;
	int i = 0;
	while (mm <= 47)
	{
		if (mm == 47 && ss == 59)
		{
			return;
		}
		ss++;
		if (ss == 60)
		{
			ss = 0;
			mm++;
		}
		
		if (v[i].m == mm && v[i].s == ss)
		{
			if (v[i].t == 1)
			{
				ascore++;
			}
			else
			{
				bscore++;
			}

			if (ascore > bscore)
			{
				nowWin = 1;
			}
			else if (bscore > ascore)
			{
				nowWin = 2;
			}
			else
			{
				nowWin = 0;
			}
			if (i < n - 1)
			{
				i++;
			}

		}
		if (nowWin == 1)
		{
			aWinss++;
			if (aWinss == 60)
			{
				aWinss = 0;
				aWinmm++;
			}
			
		}
		else if (nowWin == 2)
		{
			bWinss++;
			if (bWinss == 60)
			{
				bWinss = 0;
				bWinmm++;
			}
			
		}
		else
		{

		}


	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		string s;
		cin >> s;


		string s1;
		string s2;
		s2.resize(2);


		s1 = to_string(s[0] - '0') + to_string(s[1] - '0');
		s2[0] = s[3];
		s2[1] = s[4];
		v.push_back({ a, stoi(s1), stoi(s2) });
	}
	go();
	string ams, bms;
	ams.push_back(aWinmm / 10 + '0');
	ams.push_back(aWinmm % 10 + '0');
	ams.push_back(':');
	ams.push_back(aWinss / 10 + '0');
	ams.push_back(aWinss % 10 + '0');

	bms.push_back(bWinmm / 10 + '0');
	bms.push_back(bWinmm % 10 + '0');
	bms.push_back(':');
	bms.push_back(bWinss / 10 + '0');
	bms.push_back(bWinss % 10 + '0');
	//cout << aWinmm / 10<< aWinmm % 10 << ":" << aWinss / 10 << aWinss % 10 << "\n";
	//cout << bWinmm / 10 << bWinmm % 10 << ":" << bWinss / 10 << aWinss % 10 << "\n";
	cout << ams << "\n" << bms;
	return 0;
}