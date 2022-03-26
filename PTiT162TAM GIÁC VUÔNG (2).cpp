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
		long long* a;
		a = new long long[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			a[i] = a[i] * a[i];
		}
		sort(a, a + n);
		int d = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				long long b = a[i] + a[j];
				int l = 0;
				int r = n - 1;
				
				while (l <= r)
				{
					int mid = (l + r) / 2;
					if (a[mid] < b)
					{
						l = mid + 1;
						
					}
					else if (a[mid] > b)
					{
						r = mid - 1;
						
					}
					else
					{
						d = 1;
						break;
					}
				}
				if (d == 1)
				{
					break;
				}
			}
			if (d == 1)
			{
				break;
			}
		}
		if (d == 1)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	return 0;
}