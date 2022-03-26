#include<iostream>
#include<string>
using namespace std;
string tong(string a, string b)
{
	int m = a.size();
	int n = b.size();
	while (m < n)
	{
		a = "0" + a;
		m++;
	}
	while (n < m)
	{
		b = "0" + b;
		n++;
	}
	int nho = 0;
	string s = "";
	for (int i = m - 1; i >= 0; i--)
	{
		int k = int(a[i] - '0') + int(b[i] - '0') + nho;
		if (k < 10)
		{
			s = char(k + '0') + s;
			nho = 0;
		}
		else
		{
			s = char(k + '0' - 10) + s;
			nho = 1;
		}
	}
	if (nho == 1)
	{
		s = "1" + s;
	}
	return s;
}
string tich(string a, int b)
{
	int nho = 0;
	string s = "";
	for (int i = a.size() - 1; i >= 0; i--)
	{
		int k = int(a[i] - '0') * b + nho;
		if (k < 10)
		{
			s = char(k + '0') + s;
			nho = 0;
		}
		else
		{
			s = char(k % 10 + '0') + s;
			nho = k / 10;
		}
	}
	if (nho > 0)
	{
		s = char(nho + '0') + s;
	}
	return s;
}
void xuly(string a, string b)
{
	string s = "";
	int m = 0;
	for (int i = b.size() - 1; i >= 0; i--)
	{
		string x;
		x = tich(a, int(b[i] - '0'));
		for (int j = 0; j < m; j++)
		{
			x = x + "0";
		}
		m++;
		s = tong(s, x);
	}
	cout << s << endl;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string a;
		string b;
		cin >> a >> b;
		xuly(a, b);
	}
	return 0;
}
