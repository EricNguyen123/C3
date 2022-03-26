#include<iostream>
#include<string>
#include<stdbool.h>
#include<algorithm>
using namespace std;
void chuanhoa(string& a)
{
	if (a[1] == '/')
	{
		a = a.insert(0, "0");
	}
	if (a[4] == '/')
	{
		a = a.insert(3, "0");
	}
}
void chuanhoaten(string& a)
{
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] >= 65 && a[i] <= 90)
		{
			a[i] += 32;
		}
	}
	a[0] -= 32;
}
struct person
{
	string name;
	string date;
	int b;
};
int chuyendoi(string a)
{
	int b = 0;
	int x = a.rfind("/");
	for (int i = x + 1; i < a.size(); i++)
	{
		if (a[i] >= 48 && a[i] <= 57)
		{
			b = b * 10 + int(a[i] - '0');
		}
	}
	int y = a.find("/");
	for (int i = y + 1; i < x; i++)
	{
		if (a[i] >= 48 && a[i] <= 57)
		{
			b = b * 10 + int(a[i] - '0');
		}
	}
	for (int i = 0; i < y; i++)
	{
		if (a[i] >= 48 && a[i] <= 57)
		{
			b = b * 10 + int(a[i] - '0');
		}
	}
	return b;
}
bool check(person a, person b)
{
	return a.b > b.b;
}
int main()
{
	int n;
	cin >> n;
	person* a = new person[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].name >> a[i].date;
		chuanhoaten(a[i].name);
		chuanhoa(a[i].date);
		a[i].b = chuyendoi(a[i].date);
	}
	sort(a, a + n, check);
	cout << a[0].name << endl << a[n - 1].name;
	return 0;
}