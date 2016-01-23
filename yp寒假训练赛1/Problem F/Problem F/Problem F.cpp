#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define MOD 1000000007


__int64 n, m, k;
__int64 A[20][20];
#define M 6 //矩阵阶数
void x(__int64 a[20][20], __int64 b[20][20])
{
	__int64 i, j, k;
	__int64 B[20][20];
	memset(B, 0, sizeof(B));

	for (i = 0; i < M; i++)
	{
		for (j = 0; j < M; j++)
		{
			for (k = 0; k < M; k++)
			{
				B[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < M; j++)
		{
			A[i][j] = B[i][j] % MOD;
		}
	}

}//矩阵相乘运算

void  fast(__int64 p)
{

	__int64 i, j;
	__int64 R[20][20];
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < M; j++)
		{
			R[i][j] = A[i][j];
		}
	}
	if (p / 2)
	{
		x(A, A);
		fast(p / 2);

		if (p % 2)
		{
			x(A, R);
		}
	}

}//快速幂


int main()
{
	__int64 A0, AX, AY;
	__int64 B0, BX, BY;
	while (scanf("%I64d", &n) != EOF)
	{

		scanf("%I64d%I64d%I64d", &A0, &AX, &AY);
		scanf("%I64d%I64d%I64d", &B0, &BX, &BY);
		A0 %= MOD;
		AX %= MOD;
		AY %= MOD;
		B0 %= MOD;
		BX %= MOD;
		BY %= MOD;
		memset(A, 0, sizeof(A));
		if (n == 0)
		{
			printf("0\n");
			continue;
		}

		A[0][0] = AX;
		A[1][0] = AY;
		A[1][1] = 1;
		A[2][2] = BX;
		A[3][2] = BY;
		A[3][3] = 1;
		A[0][4] = (AX*BY)%MOD;
		A[1][4] = (AY*BY)%MOD;
		A[2][4] = (BX*AY)%MOD;
		A[4][4] = (AX*BX)%MOD;
		A[0][5] = (AX*BY)%MOD;
		A[1][5] = (AY*BY)%MOD;
		A[2][5] = (BX*AY)%MOD;
		A[4][5] = (AX*BX)%MOD;
		A[5][5] = 1;
		fast(n - 1);

		if (n == 1)
		{
			printf("%I64d\n", (A0*B0)%MOD);
		}
		else
		{
			printf("%I64d\n", (A0*A[0][5] % MOD + A[1][5] % MOD + (B0*A[2][5]) % MOD + A[3][5] % MOD + (((A0*B0) % MOD)*A[4][5]) % MOD + A0*B0) % MOD);
		}
	}
	return 0;
}
