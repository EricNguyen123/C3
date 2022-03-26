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
		cin >> a;
		
		char b[11];
		int j = 0;
		int e = 0;
		for (int i = 0; i < a.size(); i++)
		{
			if (a[i] < 48 || a[i]>57 || a[0] == '0')
			{
				cout << "INVALID" << endl;
				e = 1;
				break;
			}
			else
			{
				int d = 0;
				for (int l = 0; l < j; l++)
				{
					if (a[i] == b[l])
					{
						d = 1;
						break;
					}
				}
				if (d == 0)
				{
					b[j] = a[i];
					j++;
				}
				if (j == 10)
				{
					cout << "YES" << endl;
					e = 1;
					break;
				}
			}
		}
		if (e == 0)
		{
			cout << "NO" << endl;
		}
	}
	return 0;
}