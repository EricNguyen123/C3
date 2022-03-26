#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		int* a = new int[n];
		int* aa = new int[n];
		int* b = new int[m];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			aa[i] = a[i];
		}
		sort(aa, aa + n);
		for (int i = 0; i < m; i++)
		{
			cin >> b[i];
		}
		int* c = new int[n];
		int j = 0;
		for (int i = 0; i < m; i++)
		{
			int d = 0;
			for (int l = 0; l < i; l++)
			{
				if (b[i] == b[l])
				{
					d = 1;
					break;
				}
			}
			if (d == 0)
			{
				for (int jj = 0; jj < n; jj++)
				{
					if (a[jj] == b[i])
					{
						cout << a[jj] << " ";
					}
				}
			}
		}
		sort(b, b + m);
		for (int i = 0; i < n; i++)
		{
			if (binary_search(b, b + m, a[i]) == false)
			{
				c[j] = a[i];
				j++;
			}
		}
		sort(c, c + j);
		for (int i = 0; i < j; i++)
		{
			cout << c[i] << " ";
		}
		cout << endl;
	}
	return 0;
}
