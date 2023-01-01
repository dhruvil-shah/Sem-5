
#define N 4
#include <stdbool.h>
#include <stdio.h>

void print(int a[N][N])
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			printf(" %d ", a[i][j]);
		printf("\n");
	}
}

bool isPoss(int a[N][N], int row, int col)
{
	int i, j;

	for (i = 0; i < col; i++)
		if (a[row][i])
			return false;

	for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
		if (a[i][j])
			return false;

	for (i = row, j = col; j >= 0 && i < N; i++, j--)
		if (a[i][j])
			return false;

	return true;
}

bool backtrack(int a[N][N], int col)
{
	if (col >= N)
		return true;

	for (int i = 0; i < N; i++) {
		if (isPoss(a, i, col)) {
			a[i][col] = 1;

			if (backtrack(a, col + 1))
				return true;

			a[i][col] = 0; 
		}
	}

	return false;
}

bool solve()
{
	int a[N][N] = { { 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 } };

	if (backtrack(a, 0) == false) {
        printf("Solution for such N doesn't exist");
		return false;
	}

	print(a);
	return true;
}
int main()
{
	solve();
	return 0;
}
