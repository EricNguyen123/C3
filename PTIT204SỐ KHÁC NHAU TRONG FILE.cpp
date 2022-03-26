#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	int s[1001]{};
	ifstream a;
	a.open("DATA.in");
	while (a)
	{
		int y;
		a >> y;
		s[y]++;
	}
	for (int i = 1; i <= 1000; i++)
	{
		if (s[i] != 0)
		{
			cout << i << " " << s[i] << endl;
		}
	}
	a.close();
	return 0;
}