#include<iostream>
#include<string>
using namespace std;
class SinhVien
{
private:
	string msv, name, lop, email;
public:
	friend istream& operator>>(istream& is, SinhVien& sv)
	{
		scanf("\n");
		getline(is, sv.msv);
		getline(is, sv.name);
		getline(is, sv.lop);
		getline(is, sv.email);
		return is;
	}
	friend ostream& operator<<(ostream& os, SinhVien& sv)
	{
		os << sv.msv << " " << sv.name << " " << sv.lop << " " << sv.email << endl;
		return os;
	}
	friend void tim_kiem(string ng, SinhVien sv[], int N);
};
string xuly(string ng)
{
	string s;
	if (ng == "Ke toan")
	{
		s = "DCKT";
	}
	else if (ng == "Cong nghe thong tin")
	{
		s = "DCCN";
	}
	else if (ng == "An toan thong tin")
	{
		s = "DCAT";
	}
	else if (ng == "Vien thong")
	{
		s = "DCVT";
	}
	else if (ng == "Dien tu")
	{
		s = "DCDT";
	}
	return s;
}
void chuanhoa(string& ng)
{
	for (int i = 0; i < ng.size(); i++)
	{
		if (ng[i] >= 97 && ng[i] <= 122)
		{
			ng[i] -= 32;
		}
	}
}
 void tim_kiem(string ng, SinhVien sv[], int N)
{
	string s = xuly(ng);
	chuanhoa(ng);
	cout << "DANH SACH SINH VIEN NGANH " << ng << ":" << endl;
	for (int i = 0; i < N; i++)
	{
		if (s == "DCCN" || s == "DCAT")
		{
			if (sv[i].lop[0] == 'E')
			{
				s = s.replace(0, 1, "E");
			}
		}
		
		if (int(sv[i].msv.find(s)) > -1)
		{
			cout << sv[i];
		}
		s = s.replace(0, 1, "D");
	}
}
int main()
{
	int N;
	cin >> N;
	SinhVien* sv = new SinhVien[N];
	for (int i = 0; i < N; i++)
	{
		cin >> sv[i];
	}
	int Q;
	cin >> Q;
	string* nganh = new string[Q];
	for (int i = 0; i < Q; i++)
	{
		scanf("\n");
		getline(cin, nganh[i]);
	}
	for (int i = 0; i < Q; i++)
	{
		tim_kiem(nganh[i], sv, N);
	}
	return 0;
}
