#include<iostream>
#include<string>
#include<cstring>
#include<iomanip>
using namespace std;
struct SinhVien
{
	string name;
	string msv;
	string lop;
	float diem1;
	float diem2;
	float diem3;
};
void nhap(SinhVien& a)
{
		cin >> a.msv;
		cin.ignore();
		getline(cin, a.name);
		cin >> a.lop;
		cin >> a.diem1;
		cin >> a.diem2;
		cin >> a.diem3;
}
void sap_xep(SinhVien a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		
		for (int j = i + 1; j < n; j++)
		{
			if (a[i].msv > a[j].msv)
			{
				SinhVien tg = a[i];
				a[i] = a[j];
				a[j] = tg;
			}
		}
	}
}
void in_ds(SinhVien a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << " " << a[i].msv << " " << a[i].name << " " << a[i].lop << " " << fixed << setprecision(1) << a[i].diem1 << " " << fixed << setprecision(1) << a[i].diem2 << " " << fixed << setprecision(1) << a[i].diem3 << endl;
	}
}
int main() {
	int n;
	cin >> n;
	struct SinhVien* ds = new SinhVien[n];
	for (int i = 0; i < n; i++) {
		nhap(ds[i]);
	}
	sap_xep(ds, n);
	in_ds(ds, n);
	return 0;
}