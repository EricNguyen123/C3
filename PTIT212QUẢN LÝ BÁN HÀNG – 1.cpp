#include<iostream>
#include<string>
using namespace std;
string s_kh = "000";
string s_mh = "000";
string s_hd = "000";
string ma(string s)
{
    string x = "";
    string m = "001";
    int n = m.size() - 1;
    int nho = 0;
    for (int i = n; i >= 0; i--)
    {
        int a = int(s[i] - '0') + int(m[i] - '0') + nho;
        if (a < 10)
        {
            x = char(a + '0') + x;
            nho = 0;
        }
        else
        {
            x = char(a - 10 + '0') + x;
            nho = 1;
        }
    }
    return x;
}
string dulieukh[25][3];
string dulieumh[45][3];
int giamuaban[45][2];
int m = 0, n = 0;
class KhachHang
{
public:
    string codekh;
    string namekh;
    string sexkh;
    string agekh;
    string addresskh;
public:
    friend istream& operator>>(istream& is, KhachHang& kh)
    {
        scanf("\n");
        getline(is, kh.namekh);
        dulieukh[m][0] = kh.namekh;
        getline(is, kh.sexkh);
        getline(is, kh.agekh);
        getline(is, kh.addresskh);
        dulieukh[m][1] = kh.addresskh;
        s_kh = ma(s_kh);
        kh.codekh = "KH" + s_kh;
        dulieukh[m][2] = kh.codekh;
        m++;
        return is;
    }
};
class MatHang
{
public:
    string codemh;
    string namemh;
    string dvt;
    int gmua;
    int gban;
public:
    friend istream& operator>>(istream& is, MatHang&mh)
    {
        is.ignore();
        getline(is, mh.namemh);
        dulieumh[n][0] = mh.namemh;
        getline(is,mh.dvt);
        dulieumh[n][1] = mh.dvt;
        is >> mh.gmua;
        giamuaban[n][0] = mh.gmua;
        is >> mh.gban;
        giamuaban[n][1] = mh.gban;
        s_mh = ma(s_mh);
        mh.codemh = "MH" + s_mh;
        dulieumh[n][2] = mh.codemh;
        n++;
        return is;
    }
};
class HoaDon :private KhachHang,private MatHang
{
private:
    string codehd;
    int soluong;
public:  
    friend istream& operator>>(istream& is, HoaDon& hd)
    {
        s_hd = ma(s_hd);
        hd.codehd = "HD" + s_hd;
        is >> hd.codekh;
        for (int i = 0; i < m; i++)
        {
            if (hd.codekh == dulieukh[i][2])
            {
                hd.namekh = dulieukh[i][0];
                hd.addresskh = dulieukh[i][1];
                break;
            }
        }
        is >> hd.codemh;
        for (int i = 0; i < n; i++)
        {
            if (hd.codemh == dulieumh[i][2])
            {
                hd.namemh = dulieumh[i][0];
                hd.dvt = dulieumh[i][1];
                hd.gmua = giamuaban[i][0];
                hd.gban = giamuaban[i][1];
                break;
            }
        }
        is >> hd.soluong;
        return is;
    }
    
    friend ostream& operator<<(ostream& os, HoaDon& hd)
    {
        os << hd.codehd << " ";
        os << hd.namekh << " ";
        os << hd.addresskh << " ";
        os << hd.namemh << " ";
        os << hd.dvt << " ";
        os << hd.gmua << " ";
        os << hd.gban << " ";
        os << hd.soluong << " ";
        os << hd.soluong * hd.gban << endl; 
        return os;
    }
};
int main() {
    KhachHang dskh[25];
    MatHang dsmh[45];
    HoaDon dshd[105];
    int N, M, K, i;
    cin >> N;
    for (i = 0; i < N; i++) cin >> dskh[i];
    cin >> M;
    for (i = 0; i < M; i++) cin >> dsmh[i];
    cin >> K;
    for (i = 0; i < K; i++) cin >> dshd[i];

    for (i = 0; i < K; i++) cout << dshd[i];
    return 0;
}