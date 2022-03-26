#include<iostream>
#include<string>
#include<cstring>
using namespace std;
void chuanhoa(string& a)
{
	while (a[0] == ' ')
	{
		a = a.substr(1, a.size() - 1);
	}
	while (a[a.size() - 1] == ' ')
	{
		a = a.substr(0, a.size() - 1);
	}
	int i = a.find("  ");
	while (i > -1)
	{
		a = a.replace(i, 2, " ");
		i = a.find("  ");
	}
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] >= 65 && a[i] <= 90)
		{
			a[i] += 32;
		}
	}
	a[0] -= 32;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] == ' ')
		{
			a[i + 1] -= 32;
		}
	}
}
void xl1(string a)
{
	int r = a.rfind(" ");
	for (int i = r + 1; i < a.size(); i++)
	{
		cout << a[i];
	}
	cout << " ";
	for (int i = 0; i < r; i++)
	{
		cout << a[i];
	}
	cout << endl;
}
void xl2(string a)
{
	int l = a.find(" ");
	for (int i = l + 1; i < a.size(); i++)
	{
		cout << a[i];
	}
	cout << " ";
	for (int i = 0; i < l; i++)
	{
		cout << a[i];
	}
	cout << endl;
}
void xuly(int n)
{
	if (n == 1)
	{
		string a;
		getline(cin, a);
		chuanhoa(a);
		xl1(a);
	}
	else if(n == 2)
	{
		string a;
		getline(cin, a);
		chuanhoa(a);
		xl2(a);
	}
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		cin.ignore();
		xuly(n);
	}
	return 0;
}