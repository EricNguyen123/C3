#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		vector<unsigned long long>a;
		vector<unsigned long long>b;
		vector<unsigned long long>c;
		int m, n, p;
		cin >> m >> n >> p;
		for (int i = 0; i < m; i++)
		{
			unsigned long long x;
			cin >> x;
			a.push_back(x);
		}
		for (int i = 0; i < n; i++)
		{
			unsigned long long x;
			cin >> x;
			for (int ii = 0; ii < a.size(); ii++)
			{
				if (a[ii] == x)
				{
					b.push_back(x);
					a.erase(a.begin()+ii);
					break;
				}
			}
		}
		for (int i = 0; i < p; i++)
		{
			unsigned long long x;
			cin >> x;
			for (int ii = 0; ii < b.size(); ii++)
			{
				if (b[ii] == x)
				{
					c.push_back(x);
					b.erase(b.begin() + ii);
					break;
				}
			}
		}
		if (c.empty() == 1)
		{
			cout << -1 << endl;
		}
		else
		{
			sort(c.begin(),c.end());
			for (int i = 0; i < c.size(); i++)
			{
				cout << c[i] << " ";
			}
			cout << endl;
		}
		a.clear();
		b.clear();
		c.clear();
	}
	return 0;
}