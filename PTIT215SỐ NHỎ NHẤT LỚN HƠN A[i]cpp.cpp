#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		set<int>a;
		int* x = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> x[i];
			a.insert(x[i]);
		}
		for (int i = 0; i < n; i++)
		{
			set<int>::iterator j = a.upper_bound(x[i]);
			if (j != a.end())
			{
				cout << *j;
			}
			else
			{
				cout << "_";
			}
			cout << " ";
		}
		cout << endl;
	}
	return 0;
}