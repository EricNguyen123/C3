#include<iostream>
using namespace std;
struct watch
{
	int gio;
	int phut;
	int giay;
	int sum;
};
void nhap(watch& a)
{
	cin >> a.gio >> a.phut >> a.giay;
	a.sum = a.gio * 60 * 60 + a.phut * 60 + a.giay;
}
void xuly(watch a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i].sum > a[j].sum)
			{
				watch tg = a[i];
				a[i] = a[j];
				a[j] = tg;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << a[i].gio << " " << a[i].phut << " " << a[i].giay << endl;
	}
}

int main()
{
	int n;
	cin >> n;
	watch* a = new watch[n];
	for (int i = 0; i < n; i++)
	{
		nhap(a[i]);
	}
	xuly(a, n);
	return 0;
}