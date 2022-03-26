#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int b, p;
		cin >> b >> p;
		int d = 0;
		long long k = 0;
		double x = 1;
		while (x <= b)
		{
			x = sqrt(p * k + 1);
			if (int(x) == x)
			{
				d++;
			}
			k++;
		}
		cout << d << endl;
	}
	return 0;
}