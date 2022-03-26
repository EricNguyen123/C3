#include<iostream>
#include<string>
#include<algorithm>
#include<stdbool.h>
using namespace std;
class DoanhNghiep
{
private:
	string ma_dn;
	string ten_dn;
	int so_luong_sv;
public:
	friend istream& operator>>(istream& is, DoanhNghiep& dn)
	{
		is.ignore();
		getline(is, dn.ma_dn);
		getline(is, dn.ten_dn);
		is >> dn.so_luong_sv;
		return is;
	}
	friend ostream& operator<<(ostream& os, DoanhNghiep& dn)
	{
		os << dn.ma_dn << " " << dn.ten_dn << " " << dn.so_luong_sv << endl;
		return os;
	}
	friend bool check(DoanhNghiep a, DoanhNghiep b);
	friend void xuly(DoanhNghiep dn[], int n);
};
bool check(DoanhNghiep a, DoanhNghiep b)
{
	return a.so_luong_sv > b.so_luong_sv;
}
void in(DoanhNghiep dn[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << dn[i];
	}
}
void xuly(DoanhNghiep dn[], int n)
{
	sort(dn, dn + n, check);
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (dn[i].so_luong_sv == dn[j].so_luong_sv)
			{
				if (dn[i].ma_dn > dn[j].ma_dn)
				{
					DoanhNghiep tg = dn[i];
					dn[i] = dn[j];
					dn[j] = tg;
				}
			}
		}
	}
	in(dn, n);
}
int main()
{
	int n;
	cin >> n;
	DoanhNghiep* dn = new DoanhNghiep[n];
	for (int i = 0; i < n; i++)
	{
		cin >> dn[i];
	}
	xuly(dn, n);
	return 0;
}