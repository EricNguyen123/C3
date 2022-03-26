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
    return a.lop < b.lop;
}
void sapxep(SinhVien ds[], int N)
{
    sort(ds, ds + N, check1);
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (ds[i].lop == ds[j].lop)
            {
                if (ds[i].ma > ds[j].ma)
                {
                    SinhVien tg = ds[i];
                    ds[i] = ds[j];
                    ds[j] = tg;
                }
            }
            else
            {
                break;
            }
        }
    }
}
int main() {
    int N, i;
    cin >> N;
    SinhVien* ds = new SinhVien[N];
    for (i = 0; i < N; i++) cin >> ds[i];
    sapxep(ds, N);
    for (i = 0; i < N; i++) cout << ds[i];
    return 0;
}