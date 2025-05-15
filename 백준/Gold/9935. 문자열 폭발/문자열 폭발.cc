#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

string s, ex;
string temp;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> s >> ex;
	//int i = 0;


	for (int i = 0; i < s.size(); i++)
	{
		temp.push_back(s[i]);
		//int idx = temp.find(ex);

		//for(int j =0)
		//if (idx != string::npos)
		
		//for(int k = tenop;k<)

		if(temp.size() >=  ex.size())
		{
			bool flag = 1;
			int l = 0;
			for (int k = temp.size() - ex.size(); k <temp.size(); k++)
			{
				if (temp[k] != ex[l])
				{
					flag = false;
				}
				l++;
			}

			//cout << "adf";
			if (flag)
			{
				for (int j = 0; j < ex.size(); j++)
				{
					//cout << "asdf";
					temp.pop_back();
				}
			}


			//s.erase(idx, ex.size());
		}
	}
	if (temp.empty())
	{
		cout << "FRULA";
		return 0;
	}
	cout << temp;
	return 0;
}