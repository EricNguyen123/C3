#include<iostream>
#include<string>
#include<cstring>
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
int main() {
    NhanVien ds[50];
    int N, i;
    cin >> N;
    for (i = 0; i < N; i++) cin >> ds[i];
    for (i = 0; i < N; i++) cout << ds[i];
    return 0;
}