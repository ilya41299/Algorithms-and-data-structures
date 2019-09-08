// https://habr.com/ru/post/148336/

#include <iostream>
using namespace std;

struct matrix {
	long long mat[2][2];
};

matrix mul(matrix A, matrix B) {
	matrix C;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++) {
			C.mat[i][j] = 0;
			for (int v = 0; v < 2; v++)
				C.mat[i][j] += A.mat[i][v] * B.mat[v][j];
		}
	return C;
}

matrix power(matrix A, long long k) {
	if (k == 1)
		return A;
	matrix B;
	if (k % 2 == 0) 
	{
		B = power(A, k / 2);
		B = mul(B, B);
		return B;
	}
	else  
	{
		B = power(A, (k - 1) / 2);
		B = mul(B, B);
		B = mul(B, A);
	}
	return B;
}

int main() {
	long long k = 40;
	matrix A;
	A.mat[0][0] = 1;
	A.mat[0][1] = 1;
	A.mat[1][0] = 1;
	A.mat[1][1] = 0;
	
	matrix ans = power(A, k);
	cout << ans.mat[0][0];
	return 0;
}
