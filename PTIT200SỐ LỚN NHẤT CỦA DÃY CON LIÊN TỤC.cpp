#include<iostream>
#include<set>
using namespace std;
void xuly(int k,int a[],int n)
{
	multiset<int>s;
	for (int i = 0; i < k; i++)
	{
		s.insert(a[i]);
	}
	for (int i = k; i < n; i++)
	{
		cout << *s.rbegin() << " ";
		s.erase(s.find(a[i - k]));
		s.insert(a[i]);
	}
	cout << *s.rbegin() << endl;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		int k;
		cin >> n >> k;
		int* a = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		xuly(k, a, n);
		cout << endl;
	}
	return 0;
}