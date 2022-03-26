#include<iostream>
using namespace std;
int main()
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
	int m;
	cin >> m;
	int** b;
	b = new int* [m];
	for (int i = 0; i < m; i++)
	{
		b[i] = new int[m];
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> b[i][j];
		}
	}
	int p = 0;
	for (int i = 0; i < n; i++)
	{
		int l = 0;
		for (int j = 0; j < n; j++)
		{
			a[i][j] = a[i][j] * b[p][l];
			l++;
			if (l == m)
			{
				l = 0;
			}
		}
		p++;
		if (p == m)
		{
			p = 0;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}