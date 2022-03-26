#include<iostream>
#include<string>
#include<cstring>
using namespace std;
void chuanhoa(string& a)
{
	while (a[0] == '0')
	{
		a = a.substr(1, a.size() - 1);
	}
}
void tong(string a, string b)
{
	chuanhoa(a);
	chuanhoa(b);
	int m, n;
	m = a.size();
	n = b.size();
	while (m > n)
	{
		b = '0' + b;
		n++;
	}
	while (n > m)
	{
		a = '0' + a;
		m++;
	}
	string c;
	int nho = 0;
	for (int i = m - 1; i >= 0; i--)
	{
		int s = int(a[i] - '0') + int(b[i] - '0') + nho;
		if (s < 10)
		{
			c = c + char(s + '0');
			//c = char(s + '0') + c;
			nho = 0;
		}
		else
		{
			c = char(s + '0' - 10) + c;
			nho = 1;
		}
	}
	if (nho == 1)
	{
		c = '1' + c;
	}
	cout << c;
}
void chuyendoi1(string& a)
{
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] == '5')
		{
			a[i] = '6';
		}
	}
}
void chuyendoi2(string& a)
{
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] == '6')
		{
			a[i] = '5';
		}
	}
}
void max(string a, string b)
{
	chuyendoi1(a);
	chuyendoi1(b);
	tong(a, b);
	cout << endl;
}
void min(string a, string b)
{
	chuyendoi2(a);
	chuyendoi2(b);
	tong(a, b);
	cout << " ";
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string a, b;
		cin >> a >> b;
		min(a, b);
		max(a, b);
	}
	return 0;
}