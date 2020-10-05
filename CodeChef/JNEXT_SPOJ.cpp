//Problem : https://www.spoj.com/problems/JNEXT/
//Solution using stacks.
/*Solution Strategy :
The number which is non ascending order is always the highest. If that is an input, just output -1;
Else, find the first break from the right side for the non ascending. 
Then, just start putting all the numbers on to stack till you find something which is smaller than breaking number.
Finally, just pop the stack and insert in to the string.*/
//Complexity : O(N)

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	// your code goes here
	int T;
	cin>>T;
	for(int t=0;t<T;t++){
		int N,num;bool swapdone=false;
		cin>>N;string Arr;Arr.resize(N);
		for(int i=0;i<N;i++){
		    cin>>num;Arr[i]=(char)('0'+num);
		}
		//cout<<"Orignal num = "<<Arr<<std::endl;
		int breakid=N-2;
		while(breakid>=0){
			if(Arr[breakid]<Arr[breakid+1]){ break; }
			breakid--;
		}
		if(breakid<0) { cout<<"-1"<<endl; continue; }
		else{
			stack<int> CS;int id=breakid+1;
			while(id<=N-1){
				if(Arr[breakid]<Arr[id]) {CS.push(Arr[id]);}
				else{
					char temp=Arr[breakid]; Arr[breakid]=CS.top();CS.pop();CS.push(temp);
					while(id<N){CS.push(Arr[id++]);}
					swapdone=true;
				}
				id++;
			}
			if(!swapdone){ char temp=Arr[breakid]; Arr[breakid]=CS.top();CS.pop();CS.push(temp);}
			while(!CS.empty()){ Arr[++breakid]=CS.top(); CS.pop();}
		}
		cout<<Arr<<endl;//write the processed num
	}
	return 0;
}
