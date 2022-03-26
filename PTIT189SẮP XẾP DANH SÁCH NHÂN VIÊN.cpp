#include<iostream>
#include<string>
#include<algorithm>
#include<stdbool.h>
using namespace std;
string ma = "00000";
struct NhanVien
{
	string mnv, name, sex, date, address, mst, daykhd;
};
string tong(string a)
{
	string b = "00001";
	int m = b.size();
	string c = "";
	int nho = 0;
	for (int i = m - 1; i >= 0; i--)
	{
		int s = int(a[i] - '0') + int(b[i] - '0') + nho;
		if (s < 10)
		{
			c = char(s + '0') + c;
			nho = 0;
		}
		else
		{
			c = char(s - 10 + '0') + c;
			nho = 1;
		}
	}
	return c;
}
void chuanhoa(string& d)
{
	if (d[1] == '/')
	{
		d = d.insert(0, "0");
	}
	if(d[4] == '/')
	{
		d = d.insert(3, "0");
	}
}
void nhap(NhanVien& nv)
{
	scanf("\n");
	ma = tong(ma);
	nv.mnv = ma;
	getline(cin, nv.name);
	getline(cin, nv.sex);
	getline(cin, nv.date);
	chuanhoa(nv.date);
	getline(cin, nv.address);
	getline(cin, nv.mst);
	getline(cin, nv.daykhd);
	chuanhoa(nv.daykhd);
}
string chuanhoadecheck(NhanVien a)
{
	int x = a.date.rfind("/");
	string c = "";
	for (int i = x + 1; i < a.date.size(); i++)
	{
		c = c + a.date[i];
	}
	c += "/";
	for (int i = 0; i < x; i++)
	{
		c = c + a.date[i];
	}
	return c;
}
bool check(NhanVien a, NhanVien b)
{
	string c, d;
	c = chuanhoadecheck(a);
	d = chuanhoadecheck(b);
	return c < d;
}
void in(NhanVien nv)
{
	cout << nv.mnv << " " << nv.name << " " << nv.sex << " " << nv.date << " " << nv.address;
	cout << " " << nv.mst << " " << nv.daykhd << endl;
}
void inds(NhanVien nv[], int N)
{
	for (int i = 0; i < N; i++)
	{
		in(nv[i]);
	}
}
void sapxep(NhanVien nv[], int N)
{
	sort(nv, nv + N, check);
}
int main() {
	struct NhanVien ds[50];
	int N, i;
	cin >> N;
	for (i = 0; i < N; i++) nhap(ds[i]);
	sapxep(ds, N);
	inds(ds, N);
	return 0;
}