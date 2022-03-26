#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main()
{
	int n;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		stack<string>a;
		char c{};
		while (c != '\n')
		{
			string b;
			cin >> b;
			a.push(b);
			c = getchar();
		}
		int n = a.size();
		for (int i = 0; i < n; i++)
		{
			cout << a.top() << " ";
			a.pop();
		}
		cout << endl;
	}
	return 0;
}