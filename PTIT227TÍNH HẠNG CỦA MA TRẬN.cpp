#include<iostream>
using namespace std;
void divrow(double** matrix, int r, int col, double x)
{
	for (int i = 0; i < col; i++)
	{
		matrix[r][i] /= x;
	}
}
void changerow(double** matrix, int r1, int r2, int col, double x)
{
	for (int i = 0; i < col; i++)
	{
		matrix[r2][i] = matrix[r2][i] + matrix[r1][i] * x;
	}
}
int ranks(double** matrix, int row, int col)
{
	int rank = 0;
	int rmax = (row < col) ? row : col;
	for (int i = 0; i < row; i++)
	{
		int j;
		bool flag = false;
		for (j = 0; j < col; j++)
		{
			if (matrix[i][j] != 0)
			{
				flag = true;
				break;
			}
		}
		if (flag == true)
		{
			divrow(matrix, i, col, matrix[i][j]);
			for (int k = i + 1; k < row; k++)
			{
				if (matrix[k][j] != 0)
				{
					changerow(matrix, i, k, col, -matrix[k][j] / matrix[i][j]);
				}
			}
			rank++;
		}
		if (rank == rmax)
		{
			break;
		}
	}
	return rank;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int row, col;
		cin >> row >> col;
		double** matrix;
		matrix = new double* [row];
		for (int i = 0; i < row; i++)
		{
			matrix[i] = new double[col];
		}
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				cin >> matrix[i][j];
			}
		}
		cout << ranks(matrix, row, col) << endl;
	}
	return 0;
}