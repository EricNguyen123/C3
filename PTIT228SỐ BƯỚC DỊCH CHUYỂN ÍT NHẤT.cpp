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
		int* a = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		int i = 0;
		int d = 0;
		int max = 0;
		int tg = 0;
		while (i < n)
		{
			if (i + a[i] >= n - 1)
			{
				d++;
				break;
			}
			for (int j = i + 1; j <= i + a[i]; j++)
			{
				if (max < j + a[j])
				{
					max = j + a[j];
					tg = j;
				}
			}
			i = tg;
			max = 0;
			d++;
		}
		cout << d << endl;
	}
	return 0;
}