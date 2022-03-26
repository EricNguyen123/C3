#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string a;
		cin >> a;
		int sum = 0;
		for (int i = 0; i < a.size(); i++)
		{
			sum += int(a[i] - '0');
		}
			while (sum > 9)
			{
				int d = 0;
				while (sum > 0)
				{
					d += sum % 10;
					sum /= 10;
				}
				sum = d;
			}
			if (sum == 9)
			{
				cout << 1 << endl;
			}
			else
			{
				cout << 0 << endl;
			}
	}
	return 0;
}