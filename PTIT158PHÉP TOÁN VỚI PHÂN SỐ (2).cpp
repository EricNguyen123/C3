#include<iostream>
#include<algorithm>
using namespace std;
struct PhanSo
{
	long tu;
	long mau;
};
long ucln(PhanSo a)
{
	long min, max;
	if (a.tu > a.mau)
	{
		min = a.mau;
		max = a.tu;
	}
	else
	{
		min = a.tu;
		max = a.mau;
	}
	while (min > 0)
	{
		long tg = max % min;
		max = min;
		min = tg;
	}
	return max;
}
void rutgon(PhanSo& a)
{
	long gcd=ucln(a);
	a.tu /= gcd;
	a.mau /= gcd;
}
PhanSo tong(PhanSo a, PhanSo b)
{
	PhanSo c;
	c.tu = a.tu * b.mau + a.mau * b.tu;
	c.mau = a.mau * b.mau;
	rutgon(c);
	return c;
}
PhanSo tich(PhanSo a, PhanSo b)
{
	PhanSo c;
	c.tu = a.tu * b.tu;
	c.mau = a.mau * b.mau;
	rutgon(c);
	return c;
}
void process(PhanSo a, PhanSo b)
{
	PhanSo c;
	c = tong(a, b);
	c = tich(c, c);
	cout << c.tu << "/" << c.mau << " ";
	PhanSo d;
	d = tich(a, tich(b, c));
	cout << d.tu << "/" << d.mau << endl;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		PhanSo A;
		PhanSo B;
		cin >> A.tu >> A.mau >> B.tu >> B.mau;
		process(A, B);
	}
}