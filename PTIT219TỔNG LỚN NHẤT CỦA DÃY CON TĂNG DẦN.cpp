#include<iostream>
#include<stdbool.h>
#include<algorithm>
using namespace std;

void xuly(int n, int a[], long x[])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] < a[j])
			{
				if (x[i] + a[j] > x[j])
				{
					x[j] = x[i] + a[j];
				}
			}
		}
	}
	sort(x, x + n);
	cout << x[n - 1] << endl;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int* a = new int[n];
		long* x = new long[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			x[i] = a[i];
		}
		xuly(n, a, x);
	}
	return 0;
}