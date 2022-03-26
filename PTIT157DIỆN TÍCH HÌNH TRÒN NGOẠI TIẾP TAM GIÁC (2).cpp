#include<iostream>
#include<math.h>
#include<stdbool.h>
#include<iomanip>
#define PI 3.141592653589793238
using namespace std;
struct toado
{
	double x;
	double y;
};
struct diem
{
	toado A;
	toado B;
	toado C;
};
struct canh
{
	double AB;
	double BC;
	double CA;
};
void nhap(diem& a)
{
	cin >> a.A.x >> a.A.y >> a.B.x >> a.B.y >> a.C.x >> a.C.y;
}
double tinhcanh(toado a, toado b)
{
	double c = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
	return c;
}
canh tcanh(diem a)
{
	canh ofa;
	ofa.AB = tinhcanh(a.A, a.B);
	ofa.BC = tinhcanh(a.B, a.C);
	ofa.CA = tinhcanh(a.C, a.A);
	return ofa;
}
bool xuly(canh ofa)
{
	if (ofa.AB + ofa.BC <= ofa.CA || ofa.AB + ofa.CA <= ofa.BC || ofa.BC + ofa.CA <= ofa.AB)
	{
		return false;
	}
	return true;
}
void tinhS(canh ofa)
{
	double s1;
	s1 = sqrt((ofa.AB + ofa.BC + ofa.CA) * (ofa.AB + ofa.BC - ofa.CA) * (ofa.AB - ofa.BC + ofa.CA) * (ofa.BC + ofa.CA - ofa.AB)) / 4;
	double R;
	R = ofa.AB / s1 * ofa.BC / 4 * ofa.CA;
	double s2;
	s2 = PI * R * R;
	cout << fixed << setprecision(3) << s2 << endl;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		diem a;
		nhap(a);
		canh ofa;
		ofa = tcanh(a);
		if (xuly(ofa) == false)
		{
			cout << "INVALID" << endl;
		}
		else
		{
			tinhS(ofa);
		}
	}
	return 0;
}