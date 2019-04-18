//Solution to http://www.spoj.com/problems/JNEXT/

#include<iostream>
#include<string>
using namespace std;

const int MAX_DIGITS = 1000010;

int NUM[MAX_DIGITS];
//int DIGITS_ARRY[10];
int N;

void mswap(int f, int s) {
	int  temp = NUM[f];
	NUM[f] = NUM[s];
	NUM[s] = temp;
}

void Process() {

	//1. Find the first Non Increasing Suffix 
	int index = N - 1; int lastval = NUM[index];
	for (; index >= 0; index--) {
		if ((NUM[index]) < lastval) {
			break;
		}
		else {
			lastval = NUM[index];
		}
	}
	if (index > -1) {
		int j = N - 1;
		for (; j > index; j--) {
			if (NUM[index] < NUM[j]) {
				break;
			}
		}
		mswap(index, j);
		//reverse the indexpart;
		index++; j = N - 1;
		while (index < j) {
			mswap(index, j);
			index++; j--;
		}
		for (index = 0; index <N; index++) {
			cout << NUM[index];
		}
	}
	else {
		cout << -1;
	}
}


int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		for (int m = 0; m < N; m++) {
			cin >> NUM[m];
		}
		Process();
		cout << endl;
	}
	return 0;
}
