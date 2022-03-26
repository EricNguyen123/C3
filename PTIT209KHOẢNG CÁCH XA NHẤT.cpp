#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int* a = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		int m = n - 1;
		int* b = new int[n];
		for (int i = 0; i < m; i++)
		{
			int p = i + 1;
			for (int j = m; j >= p; j--)
			{
				if (a[i] <= a[j])
				{
						b[i] = j - i;
						break;
				}
			}
		}
		sort(b, b + n);
		cout << b[m] << endl;
	}
	return 0;
}