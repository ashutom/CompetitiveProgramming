//https://codeforces.com/problemset/problem/281/D
//Complexity : O(N)
//Approach : Since this a sequence where we have to choose the two maximum & get xor of it, we better maintain a stack of non increasing numbers 
//         : taking the xor of the top element when inserting or poping them
/* Test cases : 10 : 76969694 71698884 32888447 31877010 65564584 87864180 7850891 1505323 17879621 15722446
5: 5 2 1 4 3
5 : 9 8 3 5 7
*/

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int IP;cin>>IP;vector<long long> Arr(IP);
    for(int i=0;i<IP;i++) { cin>>Arr[i]; }
    stack<long long> S;long long val=0; long long max_h=0;
	for(int i=0;i<IP;i++){
	    if(S.empty()) { S.push(Arr[i]); }
	    else{
	        val=S.top()^Arr[i]; if(max_h<val) max_h=val;
	        while(!S.empty() && Arr[i]>S.top()){
	            val=S.top()^Arr[i]; if(max_h<val) max_h=val; S.pop();
	        }
	        if(!S.empty()) {	val=S.top()^Arr[i]; if(max_h<val) max_h=val; }
	        S.push(Arr[i]);
	    }
	}
	cout<<max_h<<endl;
	return 0;
}
