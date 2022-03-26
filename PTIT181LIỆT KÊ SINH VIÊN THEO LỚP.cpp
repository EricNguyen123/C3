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
void xuly(SinhVien ds[], int N, string ss[], int Q)
{
    for (int i = 0; i < Q; i++)
    {
        cout << "DANH SACH SINH VIEN LOP " << ss[i] << ":" << endl;
        for (int j = 0; j < N; j++)
        {
            if (ds[j].lop == ss[i])
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