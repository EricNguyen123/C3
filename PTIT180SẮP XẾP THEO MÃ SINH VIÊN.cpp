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
bool check1(SinhVien a, SinhVien b)
{
    return a.ma < b.ma;
}
void sapxep(SinhVien ds[], int N)
{
    sort(ds, ds + N, check1);
}
int main() {
    int i = 0;
    SinhVien ds[1000];
    while (cin)
    {
        cin >> ds[i];
        i++;
    }
    sapxep(ds, i);
    for (int j = 0; j < i; j++) cout << ds[j];
    return 0;
}