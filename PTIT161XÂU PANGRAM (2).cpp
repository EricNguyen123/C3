#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string a;
		int k;
		cin >> a;
		cin >> k;
		int sum = a.size();
		if (sum < 26)
		{
			cout << 0 << endl;
			continue;
		}
		int l = 0;
		char b[26];
		for (int i = 0; i < sum; i++)
		{
			int d = 0;
			for (int j = 0; j < l; j++)
			{
				if (b[j] == a[i])
				{
					d = 1;
					break;
				}
			}
			if (d == 0)
			{
				b[l] = a[i];
				l++;
			}
		}
		if (26 - l <= k)
		{
			cout << 1 << endl;
		}
		else
		{
			cout << 0 << endl;
		}
	}
	return 0;
}