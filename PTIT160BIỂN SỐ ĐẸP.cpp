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
		int s = a.find("-");
		s++;
		a = a.substr(s, a.size() - 1);
		
		if (a[0] == a[1] && a[1] == a[2] && a[2] == a[4] && a[4] == a[5])
		{
			cout << "YES\n";
		}
		else if (a[0] == a[1] && a[1] == a[2] && a[4] == a[5])
		{
			cout << "YES\n";
		}
		else if (a[0] + 1 == a[1] && a[1] + 1 == a[2] && a[2] + 1 == a[4] && a[4] + 1 == a[5])
		{
			cout << "YES\n";
		}
		else if ((a[0] == '6' || a[0] == '8') && (a[1] == '6' || a[1] == '8') && (a[2] == '6' || a[2] == '8' )&& (a[4] == '6' || a[4] == '8' )&&( a[5] == '6' || a[5] == '8'))
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
	return 0;
}