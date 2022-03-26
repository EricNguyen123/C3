#include<iostream>
#include<string>
#include<cstring>
#include<stdbool.h>
#include<algorithm>
using namespace std;
string jj = "00000";
string k = "00001";
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
class NhanVien
{
public:
    string ma, ten, gioitinh, ngaysinh, diachi, mathue, ngayky;
public:
    friend istream& operator >> (istream& is, NhanVien& a)
    {
        scanf("\n");
        getline(is, a.ten);
        getline(is, a.gioitinh);
        getline(is, a.ngaysinh);
        getline(is, a.diachi);
        getline(is, a.mathue);
        getline(is, a.ngayky);
        tong();
        a.ma = a.ma + jj;
        return is;
    }
    friend ostream& operator<<(ostream& os, NhanVien a)
    {
        os << a.ma << " " << a.ten << " " << a.gioitinh << " " << a.ngaysinh << " " << a.diachi << " " << a.mathue << " " << a.ngayky << endl;
        return os;
    }
};
bool check(NhanVien a, NhanVien b)
{
    int i = a.ngaysinh.rfind("/");
    string c, d;
    for (int j = i + 1; j < a.ngaysinh.size(); j++)
    {
        c = c + a.ngaysinh[j];
        d = d + b.ngaysinh[j];
    }
    for (int j = 0; j < i; j++)
    {
        c = c + a.ngaysinh[j];
        d = d + b.ngaysinh[j];
    }
    return c < d;
}
void sapxep(NhanVien ds[], int N)
{
    sort(ds, ds + N, check);
}
int main() {
    NhanVien ds[50];
    int N, i;
    cin >> N;
    for (i = 0; i < N; i++) cin >> ds[i];
    sapxep(ds, N);
    for (i = 0; i < N; i++) cout << ds[i];
    return 0;
}