#include<iostream>
using namespace std;
int phan_tich(int n, int p)
{
	int d = 0;
	for (int i = 2; i <= n; i++)
	{
		int m = i;
		while (m % p == 0)
		{
			d++;
			m /= p;
		}
	}
	return d;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int N;
		int p;
		cin >> N >> p;
		int x = phan_tich(N, p);
		cout << x << endl;
	}
	return 0;
}