#include<iostream>
#include<set>
#include<string>
using namespace std;
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		set<string>a;
		char c{};
		while (c != '\n')
		{
			string s;
			cin >> s;
			a.insert(s);
			c = getchar();
		}
		set<string>b;
		char d{};
		while (d != '\n')
		{
			string s;
			cin >> s;
			b.insert(s);
			d = getchar();
		}
		for (set<string>::iterator i = a.begin(); i != a.end(); i++)
		{
			if (b.find(*i) == b.end())
			{
				cout << *i << " ";
			}
		}
		cout << endl;
	}
	return 0;
}