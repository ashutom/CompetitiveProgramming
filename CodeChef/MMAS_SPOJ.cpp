//Problem : https://www.spoj.com/problems/MMASS/
//Strategy : Just push values on the stack & pop all on ')'
//Most important, just don't try to get inputs in a while. just write code for single input.


#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

const int START_BRKT=-1;

int main() {
    string IP;
	//while(cin>>IP){
		cin>>IP;
	    stack<int> IS;int val=0;IS.push(val);
	    for(int i=0;i<IP.length();i++){
	        val=0;
	        if(IP[i]=='C') { IS.push(12);}
	        else if(IP[i]=='H') { IS.push(1);}
	        else if(IP[i]=='O') { IS.push(16);}
	        else if(IP[i]>'1' && IP[i]<='9') { val=IS.top();IS.pop();val=val*(IP[i]-'0'); IS.push(val);}
	        else if(IP[i]=='(') {IS.push(START_BRKT);IS.push(0);}
	        else if(IP[i]==')') {
	            while(IS.top()!=START_BRKT){ val+=IS.top();IS.pop();	}
	            IS.pop(); IS.push(val);
	        }
	    }
	    val=0;
	    while(!IS.empty()){ val+=IS.top(); IS.pop(); }
	    cout<<val;
	//}
	return 0;
}
