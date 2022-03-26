#include<iostream>
#include<string>
#include<cstring>
#include<stdbool.h>
#include<algorithm>
using namespace std;

class SinhVien
{
public:
    string ma, ten, lop, email;
public:
    friend istream& operator >> (istream& is, SinhVien& a)
    {
        scanf("\n");
        getline(is, a.ma);
        getline(is, a.ten);
        getline(is, a.lop);
        getline(is, a.email);
        return is;
    }
    friend ostream& operator<<(ostream& os, SinhVien a)
    {
        os << a.ma << " " << a.ten << " " << a.lop << " " << a.email << endl;
        return os;
    }
};
bool check(SinhVien a, string ss)
{
    if (a.lop[1] == ss[2] && a.lop[2] == ss[3])
    {
        return true;
    }
    return false;
}
void xuly(SinhVien ds[], int N, string ss[], int Q)
{
    for (int i = 0; i < Q; i++)
    {
        cout << "DANH SACH SINH VIEN KHOA " << ss[i] << ":" << endl;
        for (int j = 0; j < N; j++)
        {
            if (check(ds[j],ss[i]) == true)
            {
                cout << ds[j];
            }
        }
    }
}
int main() {
    int N, i;
    cin >> N;
    SinhVien* ds = new SinhVien[N];
    for (i = 0; i < N; i++) cin >> ds[i];
    int Q;
    cin >> Q;
    string* ss;
    ss = new string[Q];
    for (i = 0; i < Q; i++) cin >> ss[i];
    xuly(ds, N, ss, Q);
    return 0;
}