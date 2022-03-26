#include<iostream>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int** a;
		a = new int* [n];
		for (int i = 0; i < n; i++)
		{
			a[i] = new int[n];
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> a[i][j];
			}
		}
		int* b1;
		b1 = new int[n];
		int* b2;
		b2 = new int[n];
		for (int i = 0; i < n; i++)
		{
			b1[i] = 0;
			for (int j = 0; j < n; j++)
			{
				b1[i] += a[i][j];
			}
		}
		for (int i = 0; i < n; i++)
		{
			b2[i] = 0;
			for (int j = 0; j < n; j++)
			{
				b2[i] += a[j][i];
			}
		}
		int max1 = 0, max2 = 0;
		for (int i = 0; i < n; i++)
		{
			if (max1 < b1[i])
			{
				max1 = b1[i];
			}
			if (max2 < b2[i])
			{
				max2 = b2[i];
			}
		}
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			sum += b1[i];
		}
		if (max1 > max2)
		{
			max1 = max1 * n - sum;
			cout << max1 << endl;
		}
		else
		{
			max2 = max2 * n - sum;
			cout << max2 << endl;
		}

	}
	return 0;
}