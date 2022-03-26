#include<iostream>
#include<stdbool.h>
using namespace std;
string a[1001];
int i = 0;
int b[1001];
bool check(string a)
{
	string b = a;
	int l = 0;
	int r = a.size() - 1;
	while (l<=r)
	{
		char tg = a[l];
		a[l] = a[r];
		a[r] = tg;
		l++;
		r--;
	}
	if (a == b)
	{
		return true;
	}
	return false;
}
void nhap()
{
	while (cin)
	{
		string s;
		cin >> s;
		if (s.size() > 1)
		{
			if (check(s) == true)
			{
				int d = 0;
				for (int j = 0; j < i; j++)
				{
					if (a[j] == s)
					{
						d = 1;
						b[j]++;
						break;
					}
				}
				if (d == 0)
				{
					a[i] = s;
					b[i] = 1;
					i++;
				}
			}
		}
	}
	for (int j = 0; j < i; j++)
	{
		for (int l = j + 1; l < i; l++)
		{
			if (a[j].size() < a[l].size())
			{
				string tg = a[j];
				a[j] = a[l];
				a[l] = tg;
				int t = b[j];
				b[j] = b[l];
				b[l] = t;
			}
		}
	}
	for (int j = 0; j < i - 1; j++)
	{
		for (int l = j + 1; l < i; l++)
		{
			if (a[j].size() == a[l].size())
			{
				if (a[j] < a[l])
				{
					string tg = a[j];
					a[j] = a[l];
					a[l] = tg;
					int t = b[j];
					b[j] = b[l];
					b[l] = t;
				}
			}
		}
	}
}
int main()
{
	nhap();
	
	for (int j = 0; j < i; j++)
	{
		cout << a[j] << " " << b[j] << endl;
	}
	return 0;
}