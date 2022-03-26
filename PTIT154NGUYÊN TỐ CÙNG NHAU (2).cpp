#include<iostream>
#include<math.h>
#include<stdbool.h>
using namespace std;
bool a[100001];
void nt()
{
	for (int i = 0; i < 100001; i++)
	{
		a[i] = true;
	}
	a[0] = false;
	a[1] = false;
	for (int i = 2; i < 100001; i++)
	{
		for (int j = 2 * i; j < 100001; j += i)
		{
			a[j] = false;
		}
	}
}
bool ucln(int x, int y)
{
	while (x != 0)
	{
		int tg = y % x;
		y = x;
		x = tg;
	}
	if (y == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	int t;
	cin >> t;
	nt();
	while (t--)
	{
		int x;
		cin >> x;
		int dem = 0;
		for (int i = 1; i <= x; i++)
		{
			if (ucln(i, x) == true)
			{
				dem++;
			}
		}
		if (a[dem] == true)
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