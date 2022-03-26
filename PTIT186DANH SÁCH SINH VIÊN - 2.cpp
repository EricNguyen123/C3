#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
struct SinhVien
{
    string msv, name, lop, date;
    float gpa;
};

string tong(string a)
{
    string b = "001";
    int nho = 0;
    int m = b.length();
    string c = "";
    for (int i = m - 1; i >= 0; i--)
    {
        int s = int(a[i] - '0') + int(b[i] - '0') + nho;
        if (s >= 10)
        {
            c = char(s - 10 + '0') + c;
            nho = 1;
        }
        else
        {
            c = char(s + '0') + c;
            nho = 0;
        }
    }
    return c;
}
void chuanhoa_name(string& d)
{
    while (d[0] == ' ')
    {
        d = d.substr(1, d.size() - 1);
    }
    while (d[d.size() - 1] == ' ')
    {
        d = d.substr(0, d.size() - 1);
    }
    int x = d.find("  ");
    while (x > -1)
    {
        d = d.replace(x, 2, " ");
        x = d.find("  ");
    }
    for (int i = 0; i < d.size(); i++)
    {
        if (d[i] >= 65 && d[i] <= 90)
        {
            d[i] += 32;
        }
    }
    d[0] -= 32;
    for (int i = 0; i < d.size(); i++)
    {
        if (d[i - 1] == ' ')
        {
            d[i] -= 32;
        }
    }
}

void chuanhoa_date(string& d)
{
    if (d[1] == '/')
    {
        d = d.insert(0, "0");
    }
    if (d[4] == '/')
    {
        d = d.insert(3, "0");
    }
}
void nhap(SinhVien ds[], int N)
{
    string ma = "000";
    for (int i = 0; i < N; i++)
    {
        cin.ignore();
        ma = tong(ma);
        ds[i].msv = "B20DCCN" + ma;
        getline(cin, ds[i].name);
        chuanhoa_name(ds[i].name);
        getline(cin, ds[i].lop);
        getline(cin, ds[i].date);
        chuanhoa_date(ds[i].date);
        cin >> ds[i].gpa;
    }
}
void in(SinhVien ds[], int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << ds[i].msv;
        cout << " " << ds[i].name;
        cout << " " << ds[i].lop;
        cout << " " << ds[i].date;
        cout << " " << fixed << setprecision(2) << ds[i].gpa << endl;
    }
}
int main() {
    struct SinhVien ds[50];
    int N;
    cin >> N;
    nhap(ds, N);
    in(ds, N);
    return 0;
}