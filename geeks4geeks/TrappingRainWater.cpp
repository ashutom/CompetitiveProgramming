



//This is code submission for this problem 
// https://www.geeksforgeeks.org/trapping-rain-water/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(const vector<int>& A) {
	vector<int> LM; vector<int> RM;
	int temp = 0;
	for (auto i = A.begin(); i != A.end(); i++) {
		LM.push_back(temp);
		if (temp<*i) { temp = *i; }
	}
	temp = 0; auto i = A.end(); i--;
	for (; i != A.begin(); i--) {
		RM.push_back(temp);
		if (temp<*i) { temp = *i; }
	}
	RM.push_back(temp);
	std::reverse(RM.begin(), RM.end());
	//RM.reverse();
	int min = 0;
	unsigned long long MAX = 0; i = A.begin(); auto j = LM.begin(); auto k = RM.begin();
	for (; i != A.end() && j != LM.end() && k != RM.end(); i++, j++, k++) {
		if (*j == 0 || *k == 0) { MAX += 0; continue; }
		else {
			min = std::min(*k, *j);
			if (min - *i>0) {
				MAX += (min - *i);
			}
		}
	}
	cout << MAX << endl;
}


int main() {
	//code
	int T, N;
	cin >> T;
	for (int i = 0; i<T; i++) {
		cin >> N;
		vector<int> A; int temp;
		for (int j = 0; j<N; j++) {
			cin >> temp;
			A.push_back(temp);
		}
		solve(A);
	}
	return 0;
}


