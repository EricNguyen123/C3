#include<iostream>
#include<stdbool.h>

using namespace std;
int x[40];
bool y[40];
void hoanvi(int i, int n, int m, int a[], int sum, int** s, int& d)
{
	for (int j = 1; j <= n; j++)
	{
		if (y[j] == true)
		{
			x[i] = j;
			y[j] = false;
			if (i == n)
			{
				int k = 0, h = 0;
				for (int l = 1; l <= n; l++)
				{
					 
					if (a[x[l]] == 0)
					{
						sum += s[h][k + 1];
						k++;
					}
					else
					{
						sum += s[h + 1][k];
						h++;
					}
				}
				cout << endl;
				if (sum == m)
				{
					d++;
				}
			}
			else
			{
				hoanvi(i + 1, n, m, a, sum, s, d);
			}
			y[j] = true;
		}
		
	}
}
int xuly(int** s, int n, int k)
{
	int sum = s[0][0];
	int m = 2 * n;
	int* a = new int[m];
	for (int i = 1; i < n; i++)
	{
		a[i] = 1;
	}
	for (int i = n; i < m - 1; i++)
	{
		a[i] = 0;
	}
	int d = 0;
	for (int i = 0; i < 40; i++)
	{
		y[i] = true;
	}
	hoanvi(1, m - 2, k, a, sum, s, d);
	return d;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		int k;
		cin >> n >> k;
		int** s;
		s = new int* [n];
		for (int i = 0; i < n; i++)
		{
			s[i] = new int[n];
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> s[i][j];
			}
		}
		cout << xuly(s, n, k) << endl;
	}
	return 0;
}