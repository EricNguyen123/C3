#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main()
{
	int t;
	cin >> t;
	cin.ignore();
	while (t--)
	{
		string a;
		cin >> a;
		string max = "0";
		for (int i = 0; i < a.size(); i++)
		{
			string tg = "";
			while (a[i] >= 48 && a[i] <= 57)
			{
				tg = tg + a[i];
				i++;
			}
			if (tg.size() > 1)
			{
				while (tg[0] == '0')
				{
					tg = tg.substr(1, tg.size() - 1);
				}
			}
			
			if (tg.size() > max.size())
			{
				max = tg;
			}
			else if (tg.size() == max.size())
			{
				if (tg > max)
				{
					max = tg;
				}
			}
		}
		cout << max << endl;
	}
	return 0;
}