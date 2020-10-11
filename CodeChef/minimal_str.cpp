//https://codeforces.com/contest/797/problem/C
//Complexity : O(N)
//count the occurance of the chars one after the another, then just pop / push the chars based on if the char on top is smaller or greater than what is coming 


#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

const int MAX_CHARS=26;

int main() {
    string IS;cin>>IS;string OP;
	vector<int> NOC(MAX_CHARS);
    for(int i=0;i<MAX_CHARS;i++) { NOC[i]=0; }
    for(int i=0;i<IS[i];i++) { NOC[IS[i]-'a']++; }
	int charid=0;for(int i=0;i<MAX_CHARS;i++) { if(NOC[i]) { charid=i; break; } }
	stack<char> CS;
	for(int i=0;i<IS.length();i++){
		if(IS[i]-'a' == charid) { 
		    OP+=IS[i];  NOC[charid]--;while(charid<MAX_CHARS && 0==NOC[charid]) charid++;
			continue; 
		}
		if(CS.empty()){			CS.push(IS[i]);	NOC[IS[i]-'a']--;	}
		else{
			if(CS.top()>IS[i]) {	
				if(charid != (CS.top()-'a')) { CS.push(IS[i]); NOC[IS[i]-'a']--; }
			}else{
				if(charid< IS[i]-'a') { CS.push(IS[i]); NOC[IS[i]-'a']--; }
				else{
						while(!CS.empty() && CS.top()<=IS[i]) {
						OP+=CS.top(); NOC[CS.top()-'a']--; CS.pop(); 
					}
				}
			}
		}
	}
	while(!CS.empty()) { OP+=CS.top(); CS.pop(); }
	cout<<OP<<endl;
	return 0;
}
