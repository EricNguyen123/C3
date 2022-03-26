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
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			sum += a[i];
		}
		sum -= a[0];
		int sumr = sum;
		int suml = 0;
		int d = 0;
		for (int i = 0; i < n;i++)
		{
			if (suml == sumr)
			{
				d = 1;
				cout << i + 1 << endl;
				break;
			}
			else
			{
				sumr -= a[i + 1];
				suml += a[i];
			}
		}
		if (d == 0)
		{
			cout << -1 << endl;
		}
	}
	return 0;
}