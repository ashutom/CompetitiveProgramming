//Solution for CodeChef : //https://www.codechef.com/problems/TRISQ

#include <iostream>
using namespace std;

const int MAX = 10005;

unsigned long long SqArray[MAX];

unsigned long long NumberOfSquares(const int n) {
	if (n < 1) return 0;
	if (!SqArray[n]) {
		SqArray[n] = n + NumberOfSquares(n - 1);
	}
	return SqArray[n];
}


int main() {
	int T, B, N;
	for (int i = 0; i < MAX; i++) {
		SqArray[i] = 0;
	}
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> B;
		N = (B / 2) - 1;
		if (N >= MAX) return 0;
		cout << NumberOfSquares(N) << endl;
	}
	return 0;
}