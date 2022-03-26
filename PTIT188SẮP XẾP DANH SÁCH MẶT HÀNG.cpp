#include<iostream>
#include<algorithm>
#include<stdbool.h>
#include<string>
#include<iomanip>
using namespace std;
struct HangHoa
{
	int ma;
	string ten, nhom;
	double giamua, giaban;
	double lai;
};
void nhap(HangHoa& a, int i)
{
	scanf("\n");
	a.ma = i + 1;
	getline(cin, a.ten);
	getline(cin, a.nhom);
	cin >> a.giamua;
	cin >> a.giaban;
	a.lai = a.giaban - a.giamua;
}
void in(HangHoa a)
{
	cout << a.ma << " " << a.ten << " " << a.nhom << " " << fixed << setprecision(2) << a.lai << endl;
}
bool check(HangHoa a, HangHoa b)
{
	return a.lai > b.lai;
}
int main()
{
	int N;
	cin >> N;
	HangHoa* hh = new HangHoa[N];
	for (int i = 0; i < N; i++)
	{
		nhap(hh[i], i);
	}
	sort(hh, hh + N, check);
	for (int i = 0; i < N; i++)
	{
		in(hh[i]);
	}
	return 0;
}