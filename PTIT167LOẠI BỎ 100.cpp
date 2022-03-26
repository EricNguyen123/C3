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
		int i = a.find("100");
		int d = 0;
		while (i > -1)
		{
			a = a.erase(i, 3);
			d++;
			i = a.find("100");
		}
		if (d != 0)
		{
			cout << d * 3 << endl;
		}
		
	}
	return 0;
}