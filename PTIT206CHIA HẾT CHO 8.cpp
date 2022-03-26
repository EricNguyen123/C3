#include<iostream>
#include<string>
using namespace std;
int xuly(string s,int k)
{
	int dem = 0;
	for (int i = 0; i < s.size(); i++)
	{
		int n = 0;
		for (int j = i; j < s.size(); j++)
		{
			n = n * 10 + int(s[j] - '0');
			n = n % k;
			if (n == 0)
			{
				dem++;
			}
		}
	}
	return dem;
}
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		string s;
		cin >> s;
		cout << xuly(s, 8) - xuly(s, 24) << endl;
	}
	return 0;
}