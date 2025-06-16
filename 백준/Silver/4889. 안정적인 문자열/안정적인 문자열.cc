#include<iostream>
#include<vector>
#include<algorithm>
#include<deque>


using namespace std;


int t = 1;
//string s;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while (1)
	{
		string s;
		int ret = 0;
		cin >> s;
		if (s[0] == '-')
		{
			break;
		}

		//int flag = 0;
		// 
		//while (s.size())
		//{
		//	int flag = 0;
		//	int temp = 0;
		//	for (int i = 0; i < s.size(); i++)
		//	{
		//		if (s[i] == '{')
		//		{
		//			temp = i;
		//		}

		//		if (s[i] == '}')
		//		{
		//			if (temp)
		//			{
		//				//temp = 0;
		//				flag = 1;
		//				s.erase(s.begin() + temp);
		//				s.erase(s.begin() + i);
		//				temp = 0;
		//			}
		//		}
		//	}

		//	if (!flag)
		//	{
		//		break;
		//	}
		//}
		string temp = s;
		while (1)
		{
			s = temp;
			int flag = 0;
			for (int i = 1; i < s.size(); i++)
			{
				if (s[i - 1] == '{' && s[i] == '}')
				{
					flag = 1;
					s[i] = '0';
					s[i - 1] = '0';
				}
			}
			temp.clear();
			for (int i = 0; i < s.size(); i++)
			{
				if (s[i] == '0')
				{
					continue;
				}
				temp.push_back(s[i]);
			}

			//cout <<"\n" << temp << " ";
			if (!flag)
			{
				break;
			}
		}
		
		for (int i = 1; i < temp.size(); i+=2)
		{
			if (temp[i - 1] == '{' && temp[i] == '}')
			{
				continue;
			}
			else if (temp[i - 1] == '{' && temp[i] == '{')
			{
				ret++;
			}
			else if(temp[i-1] == '}' && temp[i] == '{')
			{
				ret += 2;
			}
			else if (temp[i - 1] == '}' && temp[i] == '}')
			{
				ret++;
			}
		}


		//int temp = s.size()-1;
	
		cout << t++ << ". " << ret<<"\n";

	}
}