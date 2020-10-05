//Problem : https://www.spoj.com/problems/STPAR/
//Solution : Using Stacks : All the three conditions are independent of each other hence just do that & make sure state changes so that we do not get into intifinte loop
//complexity : O(N)

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void printArr(vector<int> A){
    cout<<" Array is : ";
    for(int i=0;i<A.size();i++){    cout<<A[i]; }
    cout<<endl<<endl;
}

int main() {
	// your code goes here
	int N;int T=1;
	cin>>N;
	while(N){
	    //cout<<"TestCase Number ["<<T++<<"] with N=["<<N<<"]"<<endl;
	    vector<int> Arr(N);
	    stack<int> St;int currentid=0;
	    unsigned int CurrentExpectedTruck=1;
	    bool first,second,third;
	    for(int i=0;i<N;i++){ cin>>Arr[i]; }
	    //printArr(Arr);
	    do{
	        first=second=third=false;
	        if(currentid<N){
	           if(Arr[currentid]==CurrentExpectedTruck) {
	               currentid++; CurrentExpectedTruck++;
	               first=true;
	           }
	        }
            if(!St.empty()){
	           if(St.top()==CurrentExpectedTruck) { 
	               St.pop();CurrentExpectedTruck++; 
	               second=true;
	           }
            }	        
	        if(!first && !second){
	            if(currentid<N){
	                St.push(Arr[currentid++]);
	                third=true;
	            }
	        }
	        //break the infinite loop
	        if(!first && !second && !third) break;
	        
	    }while((currentid<N) || !St.empty());
	    cout<<(CurrentExpectedTruck<N? "no" : "yes")<<endl;
	    cin>>N;
	}
	return 0;
}
