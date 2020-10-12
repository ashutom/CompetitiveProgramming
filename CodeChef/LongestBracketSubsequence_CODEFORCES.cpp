//https://codeforces.com/contest/5/problem/C
//Complexity : O(N)
//Approach : We go on to push index on to the stack for both ( & ) , if ) comes then we pop if top is ( when we pop we know 
//between top & the current index will be a valid string.


#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

const char openb ='(';
const char closeb =')';

int main() {
    string S;cin>>S;int lnoc=0; int lnos=0;
    stack<int> CS;int startid=0;int noc=0; int endid=0;
    for(int i=0;i<S.length();i++){
        if(S[i]==closeb){
            if(CS.empty()){
                CS.push(i);
            }else{
                if(S[CS.top()]==openb) {
                    CS.pop();
                    if(CS.empty()) noc=i+1;
                    else noc=(i-CS.top());
                    if(lnoc<noc) { lnoc=noc; lnos=1; }
                    else if(lnoc==noc && noc!=0) lnos++;
                }else{
                    CS.push(i);
                }
            }
        }else{
            CS.push(i);
        }
    }
    if(lnos){
        cout<<lnoc<<" "<<lnos<<endl;
    }else{
        cout<<0<<" "<<1<<endl;
    }
	return 0;
}
