#include<iostream>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int m, n, k;
		cin >> m >> n >> k;
		int** a;
		a = new int* [m];
		for (int i = 0; i < m; i++)
		{
			a[i] = new int[n];
		}
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> a[i][j];
			}
		}
		int p = m * n;
		int* b = new int[p];
		int d = 0;
		int cot = n - 1;
		int hang = m - 1;
		int j = 0;
		while (d < m)
		{
			for (int i = d; i <= cot; i++)
			{
				b[j] = a[d][i];
				j++;
			}
			if (j == p)
				break;
			for (int i = d + 1; i <= hang; i++)
			{
				b[j] = a[i][cot];
				j++;
			}
			if (j == p)
				break;
			for (int i = cot - 1; i >= d; i--)
			{
				b[j] = a[hang][i];
				j++;
			}
			if (j == p)
				break;
			for (int i = hang - 1; i > d; i--)
			{
				b[j] = a[i][d];
				j++;
			}
			if (j == p)
				break;
			d++;
			cot--;
			hang--;
		}
		cout << b[k - 1];
		cout << endl;
	}
	return 0;
}