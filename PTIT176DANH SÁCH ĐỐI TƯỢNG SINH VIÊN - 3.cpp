#include<iostream>
#include<iomanip>
#include<string>
#include<cstring>
#include<stdbool.h>
#include<algorithm>
using namespace std;
string jj = "000";
string k = "001";
void tong()
{
    int m = jj.size();
    int nho = 0;
    string sum;
    for (int i = m - 1; i >= 0; i--)
    {
        int s = int(jj[i] - '0') + int(k[i] - '0') + nho;
        if (s >= 10)
        {
            sum = char(s - 10 + '0') + sum;
            nho = 1;
        }
        else
        {
            sum = char(s + '0') + sum;
            nho = 0;
        }
    }
    jj = sum;
}
class SinhVien
{
public:
    string msv;
    string name;
    string nameclass;
    string date;
    float gpa;
public:
    SinhVien()
    {
        msv = "B20DCCN";
    }
    void chuahoa1()
    {
        if (date[1] == '/')
        {
            date.insert(0, "0");
        }
        if (date[4] == '/')
        {
            date.insert(3, "0");
        }
    }
    void chuanhoa2()
    {
        while (name[0] == ' ')
        {
            name = name.substr(1, name.size() - 1);
        }
        while (name[name.size() - 1] == ' ')
        {
            name = name.substr(0, name.size() - 1);
        }
        int i = name.find("  ");
        while (i > -1)
        {
            name = name.replace(i, 2, " ");
            i = name.find("  ");
        }
        for (int j = 0; j < name.size(); j++)
        {
            if (name[j] >= 65 && name[j] <= 90)
            {
                name[j] += 32;
            }
        }
        name[0] -= 32;
        for (int j = 0; j < name.size(); j++)
        {
            if (name[j] == ' ')
            {
                name[j + 1] -= 32;
            }
        }
    }
    friend istream& operator >>(istream& is, SinhVien& a)
    {
        scanf("\n");
        getline(is, a.name);
        getline(is, a.nameclass);
        getline(is, a.date);
        is >> a.gpa;
        tong();
        a.msv = a.msv + jj;
        return is;

    }
    friend ostream& operator<<(ostream& os, SinhVien a)
    {
        a.chuahoa1();
        a.chuanhoa2();
        os << a.msv << " " << a.name << " " << a.nameclass << " " << a.date << " ";
        os << fixed << setprecision(2) << a.gpa;
        os << endl;
        return os;
    }
};
bool check(SinhVien a, SinhVien b)
{
    return a.gpa > b.gpa;
}
void sapxep(SinhVien ds[], int N)
{
    sort(ds, ds + N, check);
}
int main() {
    SinhVien ds[50];
    int N, i;
    cin >> N;
    for (i = 0; i < N; i++) {
        cin >> ds[i];
    }
    sapxep(ds, N);
    for (i = 0; i < N; i++) {
        cout << ds[i];
    }
    return 0;
}