#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
		int n;
		cin >> n;
		int** a;
		int m = n * n;
		int* b;
		b = new int[m];
		a = new int* [n];
		for (int i = 0; i < n; i++)
		{
			a[i] = new int[n];
		}
		for (int i = 0; i < m; i++)
		{
			cin >> b[i];
		}
		sort(b, b + m);
		int d = 0;
		int cot = n - 1;
		int hang = cot;
		int j = 0;
		while (d <= n / 2)
		{
			for (int i = d; i <= cot; i++)
			{
				a[d][i] = b[j];
				j++;
			}
			for (int i = d + 1; i <= hang; i++)
			{
				a[i][cot] = b[j];
				j++;
			}
			for (int i = cot - 1; i >= d; i--)
			{
				a[hang][i] = b[j];
				j++;
			}
			for (int i = hang - 1; i >= d + 1; i--)
			{
				a[i][d] = b[j];
				j++;
			}
			d++;
			cot--;
			hang--;
		}
		for (int i = 0; i < n; i++)
		{
			for (int l = 0; l < n; l++)
			{
				cout << a[i][l] << " ";
			}
			cout << endl;
		}
	return 0;
}