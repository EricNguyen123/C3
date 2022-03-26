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
		int* a;
		a = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		int m = n - 1;
		int p = n - 2;
		for (int i = p; i >= 0; i--)
		{
			if (a[i] > a[i + 1])
			{
				for (int j = m; j >= 0; j--)
				{
					if (a[j] < a[i])
					{
						int tg = a[i];
						a[i] = a[j];
						a[j] = tg;
						int r = i + 1;
						int s = m;
						while (s >= r)
						{
							int g = a[s];
							a[s] = a[r];
							a[r] = g;
							s--;
							r++;
						}
						for (int o = 0; o < n; o++)
						{
							cout << a[o] << " ";
						}
						cout << endl;
						break;
					}
				}
				break;
			}
		}
	}
	return 0;
}