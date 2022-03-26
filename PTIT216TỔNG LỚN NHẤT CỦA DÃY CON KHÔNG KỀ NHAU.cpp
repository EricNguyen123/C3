#include<iostream>
#include<stdbool.h>
using namespace std;
int n;
long fopt;
int x[100000];
int a[100000];
bool check(int x, int y)
{
	if (x == y && x == 1)
	{
		return false;
	}
	return true;
}
long tinh()
{
	long sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += a[i] * x[i];
	}
	return sum;
}
void xuly(int i)
{
	for (int j = 0; j <= 1; j++)
	{
		x[i] = j;
		if (check(x[i - 1], x[i]) == true)
		{
			if (i == n - 1)
			{
				long sum = tinh();
				if (sum > fopt)
				{
					fopt = sum;
				}
			}
			else
			{
				xuly(i + 1);
			}
		}
	}
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		xuly(0);
		cout << fopt << endl;
	}
	return 0;
}