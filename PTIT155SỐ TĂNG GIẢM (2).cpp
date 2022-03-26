#include<iostream>
#include<math.h>
#include<stdbool.h>
using namespace std;
bool tang(long x)
{
	int tg = x % 10;
	x /= 10;
	while (x > 0)
	{
		if (tg > x % 10)
		{
			tg = x % 10;
			x /= 10;
		}
		else
		{
			return false;
		}
	}
	return true;
}
bool giam(long x)
{
	int tg = x % 10;
	x /= 10;
	while (x > 0)
	{
		if (tg < x % 10)
		{
			tg = x % 10;
			x /= 10;
		}
		else
		{
			return false;
		}
	}
	return true;
}
bool nt(int x)
{
	if (x == 0 || x == 1)
	{
		return false;
	}
	for (int i = 2; i <= sqrt(x); i++)
	{
		if (x % i == 0)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		long x;
		cin >> x;
		long bd = pow(10, x - 1);
		long kt = pow(10, x);
		int dem = 0;
		for (long i = bd; i < kt; i++)
		{
			if (tang(i) == true || giam(i) == true)
			{
				if (nt(i) == true)
				{
					//cout << i << " ";
					dem++;
				}
			}
		}
		cout << dem << endl;
	}
	return 0;
}