#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
using namespace std;
int main()
{
	ifstream a;
	ofstream b;
	a.open("PTIT.in");
	b.open("PTIT.out");
	while (!a.eof())
	{
		string line;
		a >> line;
		b << line << endl;
	}
	b.close();
	a.close();
	return 0;
}