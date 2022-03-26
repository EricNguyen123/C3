#include<iostream>
#include<string>
using namespace std;
int tong(string a)
{
	int s = 0;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] >= 48 && a[i] <= 57)
		{
			s += int(a[i] - '0');
		}
	}
	return s;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		cin.ignore();
		string a;
		cin >> a;
		int s = tong(a);
		for (char i = 'A'; i <= 'Z'; i++)
		{
			for (int j = 0; j < a.size(); j++)
			{
				if (a[j] == i)
				{
					cout << a[j];
				}
			}
		}
		cout << s << endl;
	}
	return 0;
}