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
string tong(string a, string b)
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
			c = char(s + '0') + c;
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
	return c;
}
int main()
{
	int t;
	cin >> t;
	cin.ignore();
	while (t--)
	{
		string a;
		getline(cin, a);
		string sum = "0";
		string tg = "";
		for (int i = 0; i < a.size(); i++)
		{
			while (a[i] >= 48 && a[i] <= 57)
			{
				tg = tg + char(a[i]);
				i++;
			}
			chuanhoa(tg);
			sum = tong(sum, tg);
		}
		cout << sum << endl;
	}
	return 0;
}