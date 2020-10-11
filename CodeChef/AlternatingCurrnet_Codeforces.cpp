//https://codeforces.com/contest/343/problem/B
//Complexity : O(N)
// Approach : If there are two ++ or -- together they fuse , hence just pop. else push. if empty then good



#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

const char minus = '-';
const char plus ='+';

int main() {
    string S;cin>>S;
    stack<char> CS;
    for(int i=0;i<S.length();i++){
        if(CS.empty()) { CS.push(S[i]); }
        else{
            if(S[i]==CS.top()) { CS.pop(); }
            else CS.push(S[i]);
        }
    }
    cout<<( CS.empty() ? "Yes" : "No") <<endl;
	return 0;
}
