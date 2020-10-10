//Problem : https://www.spoj.com/problems/HISTOGRA/
//Approach :  get nearest smaller to left &  nearest smaller right for all index; then area= height* ( nsr-nsl-1)
//Complexity : O(N)
//Result : WA

#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void printarry(const vector<unsigned long long>& A){
    cout<<" A[] = ";
    for(int i=0;i<A.size();i++){ cout<<A[i]<<" "; } 
    cout<<endl;
}

void getNSL(const vector<unsigned long long>& A, vector<int>& nsl){
    stack<int> S;
    for(int i=0;i<A.size();i++){
        if(S.empty()) { S.push(i); nsl.push_back(-1); }
        else if(A[i]>A[S.top()]) { nsl.push_back(S.top());S.push(i); }
        else if(A[i]<=A[S.top()]) {
            while(!S.empty() && A[S.top()]>=A[i]) S.pop();
            if(S.empty()) {  S.push(i); nsl.push_back(-1); }
            else { nsl.push_back(S.top()); S.push(i); }
        }
    }
    //printarry(nsl);
}
void getNSR(vector<unsigned long long> A, vector<int>& nsr){
    stack<int> S;A.push_back(0);
    for(int i=A.size()-1;i>=0;i--){
        if(S.empty()) { S.push(i); nsr.push_back(-1); }
        else if(A[i]>A[S.top()]) { nsr.push_back(S.top());S.push(i); }
        else if(A[i]<=A[S.top()]) {
            while(!S.empty() && A[S.top()]>=A[i]) S.pop();
            if(S.empty()) {  S.push(i); nsr.push_back(-1); }
            else { nsr.push_back(S.top()); S.push(i); }
        }
    }
    std::reverse(nsr.begin(),nsr.end());
    //printarry(nsr);
}

int main() {
    int IP;
	while(cin>>IP){
	    vector<unsigned long long> Arr(IP);
	    vector<int> NSL;vector<int> NSR;
	    unsigned long long val=0;unsigned long long max_h=0;
	    for(int i=0;i<IP;i++){  cin>>Arr[i];     }
	    //printarry(Arr);
	    getNSL(Arr,NSL);
	    getNSR(Arr,NSR);
	    for(int i=0;i<IP;i++){
	        val=Arr[i]*(NSR[i]-NSL[i]-1);
	        //cout<<NSR[i]<<" "<<NSL[i]<<" val="<<val<<endl;
	        if(max_h<val) max_h=val;
	    }
	    cout<<max_h<<endl;
	}
	return 0;
}
