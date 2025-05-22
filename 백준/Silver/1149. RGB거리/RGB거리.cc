#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>



using namespace std;



int n;

int dp[1004][5];
vector<int>v[1004];



int go(int here, int rgb)
{

	// 중단점 집이 끝까지 오면 종료
	if (here == n)
	{
		return 0;
	}


	// 메모이제이션
	int& ret = dp[here][rgb];
	if (ret != -1)
	{
		return ret;
	}

	// 최솟값 뽑아내는 문제라 max값 넣어줌
	ret = 1e9;


	// rgb 고르기
	for (int i = 0; i < 3; i++)
	{

		// rgb 전에 사용한건 넘기기
		if (rgb == i)
		{
			continue;
		}
		
		ret = min(ret, go(here + 1, i) + v[here][rgb]) ;

	}

	return ret;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b, c;
		cin >> a >> b>> c;
		v[i].push_back(a);
		v[i].push_back(b);
		v[i].push_back(c);
	}

	memset(dp, -1, sizeof(dp));
	//cout << go(0, 0);
	cout << min(go(0, 0), min(go(0, 1), go(0, 2)));

	return 0;
}