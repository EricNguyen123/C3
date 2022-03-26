#include<iostream>
#include<string>
#include<stdbool.h>
#include<algorithm>
using namespace std;
struct SinhVien
{
	string msv, name, lop, email, doanh_nghiep;
	int stt;
};
void nhap(SinhVien& sv, int i)
{
	scanf("\n");
	sv.stt = i + 1;
	getline(cin, sv.msv);
	getline(cin, sv.name);
	getline(cin, sv.lop);
	getline(cin, sv.email);
	getline(cin, sv.doanh_nghiep);
}
void in_ds(SinhVien sv)
{
	cout << sv.stt << " " << sv.msv << " " << sv.name << " " << sv.lop << " " << sv.email << " ";
	cout << sv.doanh_nghiep << endl;
}
bool check(SinhVien a, SinhVien b)
{
	return a.name < b.name;
}
void tim_kiem_ds(SinhVien sv[], int N)
{
	scanf("\n");
	string ten_dn;
	getline(cin, ten_dn);
	for (int i = 0; i < N; i++)
	{
		if (ten_dn == sv[i].doanh_nghiep)
		{
			in_ds(sv[i]);
		}
	}
}
int main()
{
	int N;
	cin >> N;
	SinhVien* sv = new SinhVien[N];
	for (int i = 0; i < N; i++)
	{
		nhap(sv[i], i);
	}
	sort(sv, sv + N, check);
	int Q;
	cin >> Q;
	for (int i = 0; i < Q; i++)
	{
		tim_kiem_ds(sv, N);
	}
	return 0;
}
