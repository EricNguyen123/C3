#include<iostream>
#include<string>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<stdbool.h>
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
	scanf("\n");
	getline(cin, a.name);
	cin >> a.lop;
	cin >> a.diem1;
	cin >> a.diem2;
	cin >> a.diem3;
}
bool check(SinhVien a, SinhVien b)
{
	return a.name < b.name;
}
void sap_xep(SinhVien a[], int n)
{
	sort(a, a + n, check);
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