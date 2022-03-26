#include<iostream>
#include<stdbool.h>
#include<algorithm>
using namespace std;
struct TapHop
{
	int so;
	int sophantu;
};
bool check(TapHop a, TapHop b)
{
	if (a.sophantu == b.sophantu)
	{
		return a.so < b.so;
	}
	return a.sophantu > b.sophantu;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		TapHop* a = new TapHop[n];
		int j = 0;
		while (n--)
		{
			int x;
			cin >> x;
			int d = 0;
			for (int i = 0; i < j; i++)
			{
				if (x == a[i].so)
				{
					a[i].sophantu++;
					d = 1;
					break;
				}
			}
			if (d == 0)
			{
				a[j].so = x;
				a[j].sophantu = 1;
				j++;
			}
		}
		sort(a, a + j, check);
		for (int i = 0; i < j; i++)
		{
			while (a[i].sophantu--)
			{
				cout << a[i].so << " ";
			}
		}
		cout << endl;
	}
	return 0;
}