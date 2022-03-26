#include<iostream>
#include<set>
#include<string>
using namespace std;
int main()
{
	set<string>a;
	int n;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		string b;
		getline(cin, b);
		a.insert(b);
	}
	cout << a.size() << endl;
	return 0;
}