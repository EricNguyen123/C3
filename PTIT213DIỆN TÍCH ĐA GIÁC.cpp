#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;
struct ToaDo {
	double x;
	double y;
};
double Canh(ToaDo A, ToaDo B)
{
	double a;
	a = sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
	return a;
}
double xuly(ToaDo A, ToaDo B, ToaDo C)
{
	double a, b, c;
	a = Canh(A, B);
	b = Canh(B, C);
	c = Canh(C, A);	
	double s;
	s = sqrt((a + b + c) * (b + c - a) * (a + c - b) * (a + b - c)) / 4;
	return s;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		ToaDo* a = new ToaDo[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i].x >> a[i].y;
		}
		double s = 0;
		n--;
		for (int i = 1; i < n; i++)
		{
			s += xuly(a[0], a[i], a[i + 1]); 
		}
		cout << fixed << setprecision(3) << s << endl;
	}
	return 0;
}