#include<iostream>
#include<math.h>
#include<stdbool.h>
using namespace std;
bool check(long long n)
{
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}
void xuly(long long l, long long r)
{
	long long m = sqrt(r);
	int d = 0;
	if (l <= 4)
	{
		d++;
		l = 3;
	}
	else
	{
		l = sqrt(l);
		if (l % 2 == 0)
		{
			l++;
		}
	}
	for (int i = l; i <= m; i += 2)
	{
		if (check(i) == true)
		{
			d++;
		}
	}
	cout << d << endl;
}
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		long long l, r;
		cin >> l >> r;
		xuly(l, r);
	}
	return 0;
}