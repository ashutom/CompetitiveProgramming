//https://www.codechef.com/problems/COMPILER
//Strategy : Remeber, a good string is one which make your stack empty at the last. rest is easy

#include <iostream>
#include <string>
#include <stack>
using namespace std;
#if 1
int main() {
	int T;	cin>>T;
	for(int t=0;t<T;t++){
	    stack<char> CS;string IS;cin>>IS;long long lofvi=0;//leght of valid input
	    for(int i=0;i<IS.length();i++){
	        if(IS[i]=='<') {    CS.push(IS[i]);    }
	        if(IS[i]=='>') {
	            if(CS.empty()){ break; }
	            else{   CS.pop(); }
	        }
	        if(CS.empty()){    lofvi=i+1;   }
	    }
	    cout<<lofvi<<endl;
	}
	return 0;
}
#else

const int MAX_CHARS = 1000010;
char STR[MAX_CHARS];

template<typename NT, int MAX_ELEMENT>
struct Amstack {
	//const int MAX_ELEMENT;
	NT mARRAY[MAX_ELEMENT];
	int SP;
	Amstack(): SP(-1) {}
	~Amstack() { Reset();  }
	bool IsEmpty() { return SP < 0; }
	bool IsFull() { return SP >= MAX_ELEMENT - 1; }
	void Reset() { SP = -1; }
	void Push(NT e) {
		if (!IsFull()) {
			mARRAY[++SP] = e;
		}
	}
	NT Pop() {
		NT temp;
		if (!IsEmpty()) {
			temp = mARRAY[SP];
			SP--;
		}
		return temp;
	}
	NT Peek() {
		NT temp;
		if (!IsEmpty()) {
			temp = mARRAY[SP];
		}
		return temp;
	}
};

Amstack<char, MAX_CHARS> CStack;

void Process() {
	CStack.Reset();
	int i = 0; int Result = 0;
	while (STR[i]) {
		if (STR[i] == '<') {CStack.Push(STR[i]);		}
		else { //its >
			if (!CStack.IsEmpty()) {    CStack.Pop();	}
			else break;
		}
		if (CStack.IsEmpty()) { Result = i + 1; }
		i++;
	}
	cout << Result;
}

int main() {
	//return Process_2();
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> STR;
		Process();
		cout << endl;
	}
	return 0;
}

#endif
