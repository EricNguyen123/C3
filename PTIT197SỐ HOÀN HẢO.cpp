#include<iostream>
#include<math.h>
#include<stdbool.h>
using namespace std;
bool check(long long n)
{
	if (n < 2)
	{
		return false;
	}
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}
void xuly(long long N)
{
	int d = 0;
	for (int i = 2; i < 20; i++)
	{
		if (check(i) == true && check(pow(2, i) - 1) == true)
		{
			if (pow(2, i - 1) * (pow(2, i) - 1) == N)
			{
				d = 1;
				break;
			}
		}
	}
	if (d == 1)
	{
		cout << 1 << endl;
	}
	else
	{
		cout << 0 << endl;
	}
}
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		long long N;
		cin >> N;
		xuly(N);
	}
	return 0;
}