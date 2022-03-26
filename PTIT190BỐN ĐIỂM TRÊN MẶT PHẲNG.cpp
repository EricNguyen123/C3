#include<iostream>
#include<stdbool.h>
using namespace std;
struct diem
{
	double x, y, z;
};
struct toa_do
{
	diem A, B, C, D;
};
void nhaptoado(diem& A)
{
	cin >> A.x >> A.y >> A.z;
}
void nhap(toa_do& td)
{
	nhaptoado(td.A);
	nhaptoado(td.B);
	nhaptoado(td.C);
	nhaptoado(td.D);
}
diem chiphuong(diem a, diem b)
{
	diem c;
	c.x = a.x - b.x;
	c.y = a.y - b.y;
	c.z = a.z - b.z;
	return c;
}
diem phaptuyen(diem u1, diem u2)
{
	diem n;
	n.x = u1.y * u2.z - u2.y * u1.z;
	n.y = u2.x * u1.z - u1.x * u2.z;
	n.z = u1.x * u2.y - u1.y * u2.x;
	return n;
}
bool check(toa_do td)
{
	diem u1 = chiphuong(td.A, td.B);
	diem u2 = chiphuong(td.C, td.B);
	diem n = phaptuyen(u1, u2);
	if (n.x * (td.D.x - td.A.x) + n.y * (td.D.y - td.A.y) + n.z * (td.D.z - td.A.z) == 0)
	{
		return true;
	}
	return false;
}
int main()
{
	int n;
	cin >> n;
	toa_do* td = new toa_do[n];
	for (int i = 0; i < n; i++)
	{
		nhap(td[i]);
		if (check(td[i]) == true)
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