#include<iostream>
#include<string>
#include<cstring>
#include<iomanip>
using namespace std;
struct SinhVien
{
	string ten;
	string lop;
	string ngaysinh;
	float gpa;
};
void nhapThongTinSV(SinhVien& a)
{
	getline(cin, a.ten);
	cin >> a.lop;
	cin >> a.ngaysinh;
	if (a.ngaysinh[1] == '/')
	{
		a.ngaysinh = a.ngaysinh.insert(0, "0");
	}
	if (a.ngaysinh[4] == '/')
	{
		a.ngaysinh = a.ngaysinh.insert(3, "0");
	}
	cin >> a.gpa;
}
void inThongTinSV(SinhVien& a)
{
	cout << "N20DCCN001" << " " << a.ten <<" "<< a.lop << " "<< a.ngaysinh <<" "<< fixed << setprecision(2) << a.gpa;
}
int main()
{
	struct SinhVien a;
	nhapThongTinSV(a);
	inThongTinSV(a);
	return 0;
}
