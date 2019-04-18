//Solution for CodeChef : //https://www.codechef.com/problems/NOKIA

#include <iostream>
using namespace std;

const int MAX = 40;
int ARRY[MAX];
int MinArray[MAX];
int MaxArray[MAX];
int N, M;
void swap(int i, int j) {
	if (i != j) {
		int c = ARRY[i];
		ARRY[i] = ARRY[j];
		ARRY[j] = c;
	}
}

void Permute(char s[], int start, int len) {
	if (len - start <= 1) {
		cout << s << endl;
		return;
	}
	for (int i = start; i<len; i++) {
		swap(start, i);
		Permute(s, start + 1, len);
		swap(start, i);
	}
}

int calmin(int s, int e) {
	if (e - s <= 0)	return 2;
	//if (e - s <= 1) {
	//	return (1 + 2 + 2 + 1);
	//}
	if (e % 2) {//odd
		//int mid = (e / 2) + 1;
		return (e + 1) + calmin(s, e/2) + calmin((e+4)/2, e);
	}
	else {//even
		  //int mid = (e / 2);
		return (e + 1) + calmin(s, (e - 2) / 2) + calmin((e + 2) / 2, e);
	}
}

int main() {
	int T;
	for (int i = 1; i <31; i++) {
		ARRY[i] = i;
		MaxArray[i] = (((i + 2)*(i + 1)) / 2) - 1;
		MinArray[i] = calmin(1, i);
	}
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N >> M;
		if (M-MaxArray[N] >= 0) {
			cout << M - MaxArray[N] << endl;
		}
		if (M - MinArray[N] == 0) {
			cout << 0 << endl;
		}
		else if (M - MinArray[N] < 0) {
			cout << -1 << endl;
		}
	}
	//Permute(ARRY, 0, len);
	return 0;
}

