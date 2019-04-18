
#include<iostream>
#include<string>
using namespace std;

void Solve(string N, string& A, string& B) {
	string::iterator it = N.end()-1;
	while (it >= N.begin()){
		if (*it == '4') {
			B= '3'+B;
			A= '1'+A;
		}
		else {
			B= *it+B;
			A= '0'+A;
		}
		if(it>N.begin()) it--;
		else break;
	}
	it = A.begin();
	for (; it <A.end(); it++) {
		if ((*it) != '0') {	break;}
	}
	//if(it>A.begin()) it--;
	A.erase(A.begin(), it);
	it = B.begin();
	for (; it <B.end(); it++) {
		if ('0' != *it) {	break;	}
	}
	//if (it>B.begin()) it--;
	B.erase(B.begin(), it);
}


int main() {
	int T;
	string N;
	cin >> T;
	for (int i = 0; i<T; i++) {
		string A, B;
		cin >> N;
		Solve(N, A, B);
		cout << "Case #" << i + 1 << ": " << A << " " << B
			<< endl;
	}
	return 0;
}





#if 0
Problem
Someone just won the Code Jam lottery, and we owe them N jamcoins!However, when we tried to print out an oversized check, we encountered a problem.The value of N, which is an integer, includes at least one digit that is a 4... and the 4 key on the keyboard of our oversized check printer is broken.

Fortunately, we have a workaround : we will send our winner two checks for positive integer amounts A and B, such that neither A nor B contains any digit that is a 4, and A + B = N.Please help us find any pair of values A and B that satisfy these conditions.

Input
The first line of the input gives the number of test cases, T.T test cases follow; each consists of one line with an integer N.

Output
For each test case, output one line containing Case #x: A B, where x is the test case number(starting from 1), and A and B are positive integers as described above.

It is guaranteed that at least one solution exists.If there are multiple solutions, you may output any one of them. (See "What if a test case has multiple correct solutions?" in the Competing section of the FAQ.This information about multiple solutions will not be explicitly stated in the remainder of the 2019 contest.)

Limits
1 ≤ T ≤ 100.
Time limit : 10 seconds per test set.
Memory limit : 1GB.
At least one of the digits of N is a 4.

Test set 1 (Visible)
1 < N < 105.

	Test set 2 (Visible)
	1 < N < 109.

	Solving the first two test sets for this problem should get you a long way toward advancing.The third test set is worth only 1 extra point, for extra fun and bragging rights!

	Test set 3 (Hidden)
	1 < N < 10100.

	Sample

	Input

	Output

	3
	4
	940
	4444


	Case #1: 2 2
	Case #2: 852 88
	Case #3: 667 3777



#endif 