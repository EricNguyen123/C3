#include<iostream>
#include<string>
#include<cstring>
using namespace std;
void xuly (string a)
{
	string b[10];
	b[2] = "ABCabc";
	b[3] = "DEFdef";
	b[4] = "GHIghi";
	b[5] = "JKLjkl";
	b[6] = "MNOmno";
	b[7] = "PQRSpqrs";
	b[8] = "TUVtuv";
	b[9] = "WXYZwxyz";
	string c = "";
	for (int i = 0; i < a.size(); i++)
	{
		int d = 0;
		for (int j = 2; j < 10; j++)
		{
			for (int l = 0; l < b[j].size(); l++)
			{
				if (a[i] == b[j][l])
				{
					c = c + char(j + 48);
					d = 1;
					break;
				}
			}
			if (d == 1)
			{
				break;
			}
		}
	}
	int m = c.size();
	int n = m / 2;
	int p = 0;
	int f = 0;
	while (p < n)
	{
		if (c[p] == c[m - 1])
		{
			p++;
			m--;
		}
		else
		{
			f = 1;
			break;
		}
	}
	if (f == 0)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string a;
		cin >> a;
		xuly(a);
	}

	return 0;
}