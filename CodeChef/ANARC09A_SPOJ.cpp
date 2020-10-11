//https://www.spoj.com/problems/ANARC09A/
//Complexity : o(N)
//Approach : Just put all the input to stack if openb, if close just pop. If empty & get close then you change one brace

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

const char openb='{';
const char closeb='}';

int main() {
    long long IP=1;string IS;
    while(cin>>IS){
    	if(IS.length()<=0 || (IS[0]!=openb && IS[0]!=closeb)) break;
        int result=0;stack<char> S;
        for(int i=0;i<IS.length();i++){
            if(IS[i]==openb){ S.push(openb); }
            else{
                if(S.empty()){ result++; S.push(openb);}
                else{ S.pop(); }
            }
        }
        while(!S.empty()) { result++; S.pop();S.pop();   }
        cout<<IP++<<". "<<result<<endl;
    }
	return 0;
}
