#include<iostream>
#include<string>
#include<stdbool.h>
#include<algorithm>
using namespace std;
string du_lieu_mon_hoc[100][2];
int j = 0;
class MonHoc
{
public:
	string ma_mon_hoc;
	string ten_mon_hoc;
public:
	friend istream& operator>>(istream& is, MonHoc& mh)
	{
		is >> mh.ma_mon_hoc;
		is.ignore();
		getline(is, mh.ten_mon_hoc);
		du_lieu_mon_hoc[j][0] = mh.ma_mon_hoc;
		du_lieu_mon_hoc[j][1] = mh.ten_mon_hoc;
		j++;
		return is;
	}
};
string tt = "000";
string stt(string s)
{
	string d = "001";
	int nho = 0;
	string sum = "";
	for (int i = 2; i >= 0; i--)
	{
		int m = int(s[i] - '0') + int(d[i] - '0') + nho;
		if (m < 10)
		{
			sum = char(m + '0') + sum;
			nho = 0;
		}
		else
		{
			sum = char(m - 10 + '0') + sum;
			nho = 1;
		}
	}
	tt = sum;
	return sum;
}
class LichThi
{
public:
	string mlt;
	string mmh;
	string tmh;
	string ngay;
	string gio;
	string nhom;
public:
	friend istream& operator>>(istream& is, LichThi& lt)
	{
		is >> lt.mmh;
		is >> lt.ngay;
		is >> lt.gio;
		is >> lt.nhom;
		lt.mlt = stt(tt);
		lt.mlt = "T" + lt.mlt;
		for (int i = 0; i < j; i++)
		{
			if (lt.mmh == du_lieu_mon_hoc[i][0])
			{
				lt.tmh = du_lieu_mon_hoc[i][1];
				break;
			}
		}
		return is;
	}
	friend ostream& operator<<(ostream& os, LichThi& lt)
	{
		os << lt.mlt << " " << lt.mmh << " " << lt.tmh << " " << lt.ngay << " " << lt.gio << " " << lt.nhom << endl;
		return os;
	}
	friend bool check(LichThi a, LichThi b);
	
};
int chuanhoa(string ngay)
{
	int n = 0;
	int x = ngay.rfind("/");
	for (int i = x + 1; i < ngay.size(); i++)
	{
		n = n * 10 + int(ngay[i] - '0');
	}
	int y = ngay.find("/");
	for (int i = y + 1; i < x; i++)
	{
		n = n * 10 + int(ngay[i] - '0');
	}
	for (int i = 0; i < y; i++)
	{
		n = n * 10 + int(ngay[i] - '0');
	}
	return n;
}
int gio(string gio)
{
	int n = 0;
	int x = gio.find(":");
	for (int i = 0; i < gio.size(); i++)
	{
		if (i == x)
		{
			continue;
		}
		n = n * 10 + int(gio[i] - '0');
	}
	return n;
}
bool check(LichThi a, LichThi b)
{
	int ngay1 = chuanhoa(a.ngay);
	int ngay2 = chuanhoa(b.ngay);
	int gio1 = gio(a.gio);
	int gio2 = gio(b.gio);
	if (ngay1 == ngay2)
	{
		if (gio1 == gio2)
		{
			return a.mmh < b.mmh;
		}
		else
		{
			return gio1 < gio2;
		}
	}
	else
	{
		return ngay1 < ngay2;
	}
}
void process(MonHoc mh[], int n, LichThi lt[], int m)
{
	sort(lt, lt + m, check);
}
int main() {
	int n, m;
	cin >> n >> m;
	cin.ignore();
	MonHoc mh[100];
	LichThi lt[1000];
	for (int i = 0; i < n; i++) {
		cin >> mh[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> lt[i];
	}
	process(mh, n, lt, m);
	for (int i = 0; i < m; i++) {
		cout << lt[i];
	}
}