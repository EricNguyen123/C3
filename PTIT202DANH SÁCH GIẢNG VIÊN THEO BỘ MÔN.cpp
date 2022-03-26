#include<iostream>
#include<string>
#include<stdbool.h>
#include<algorithm>
using namespace std;
string s = "00";
string ma(string s)
{
	string a = "01";
	int nho = 0;
	string c = "";
	for (int i = 1; i >= 0; i--)
	{
		int m = int(a[i] - '0') + int(s[i] - '0') + nho;
		if (m < 10)
		{
			c = char(m + '0') + c;
			nho = 0;
		}
		else
		{
			c = char(m + '0' - 10) + c;
			nho = 1;
		}
	}
	return c;
}
string chuanhoa(string a)
{
	string s = "";
	s += a[0];
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] == ' ')
		{
			s += a[i + 1];
		}
	}
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= 97 && s[i] <= 122)
		{
			s[i] -= 32;
		}
	}
	return s;
}
string tach_name(string a)
{
	int x = a.rfind(" ");
	x++;
	string s = "";
	for (int i = x; i < a.size(); i++)
	{
		s += a[i];
	}
	return s;
}
class GiangVien
{
private:
	string mgv;
	string name;
	string khoa;
	string khoavt;
	string tr;
public:
	friend istream& operator>>(istream& is, GiangVien& gv)
	{
		s = ma(s);
		gv.mgv = "GV" + s;
		getline(is, gv.name);
		gv.tr = tach_name(gv.name);
		getline(is, gv.khoa);
		gv.khoavt = chuanhoa(gv.khoa);
		return is;
	}
	friend ostream& operator<<(ostream& os, GiangVien& gv)
	{
		os << gv.mgv << " " << gv.name << " " << gv.khoavt << endl;
		return os;
	}
	friend void xuly(GiangVien gv[], int n, string bm);
};
void xuly(GiangVien gv[], int n, string bm)
{
	for (int i = 0; i < n; i++)
	{
		if (bm == gv[i].khoavt)
		{
			cout << gv[i];
		}
	}
}
int main()
{
	int n;
	cin >> n;
	cin.ignore();
	GiangVien* gv = new GiangVien[n];
	for (int i = 0; i < n; i++)
	{
		cin >> gv[i];
	}
	int q;
	cin >> q;
	cin.ignore();
	for (int i = 0; i < q; i++)
	{
		string a;
		getline(cin, a);
		a = chuanhoa(a);
		cout << "DANH SACH GIANG VIEN BO MON " << a << ":" << endl;
		xuly(gv, n, a);
	}
	return 0;
}