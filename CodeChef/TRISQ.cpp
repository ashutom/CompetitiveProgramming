//https://www.codechef.com/problems/TRISQ
//Recursion with storage
//Complexity O(N)


#include <iostream>
using namespace std;

const int MAX=10009;

int NOS[MAX];

int GetTriangles(int B){
    if(B<=3) return 0;
    if(NOS[B]) return NOS[B];
    int forBby2=(B>>1)-1;
    NOS[B]= forBby2 + GetTriangles(2*forBby2);
    return NOS[B];
}

int main() {
	// your code goes here
	for(int i=0;i<MAX;i++){
	    NOS[i]=0;
	}
	NOS[4]=1;
	int T,B;
	cin>>T;
	for(int t=0;t<T;t++){
	    cin>>B;
	    if(B>3 && B<=MAX){
	        cout<<GetTriangles(B);
	    }else{
	        cout<<0;
	    }
	    cout<<endl;
	}
	return 0;
}
