//Problem : https://www.codechef.com/problems/NOKIA
//O(N!)
//Just permute & calculate the value of rope.  
//GIVES  TLE :P


#include <iostream>
#include <vector>

using namespace std;

const int MAX=99999;

void print(const vector<int>& v, int val, const int& M){
    cout<<"Current permutation :";
    for(int i=0;i<v.size();i++){
        cout<<" "<<v[i];
    }
    cout<<" The summation is : "<<val<<", M= "<<M<<" "<<endl;
}


int ropeusedforthisval(const vector<int>& v, int id){
    int l=0;int r=v.size()+1;
    for(int i=0;i<id;i++){
        if(v[i]>v[id]){if(r>v[i]) r=v[i];}
        else {if(l<v[i]) l=v[i];}
    }
    //cout<<"for id="<<id<<" v[id]="<<v[id]<<" l="<<l<<" r="<<r<<" val="<<v[id]-l+r-v[id]<<endl;
    return(v[id]-l+r-v[id]);
}
void swap(vector<int>& v, int l, int r){
    if(l!=r && l>=0 && r>=0 && l<v.size() && r<v.size()){
        int temp=v[l];v[l]=v[r];v[r]=temp;
    }
}

void permute(vector<int>& v, int& minval,int& val, int id, const int& M){
    if(id>=v.size()){
        //print(v,val,M);
        int tempval=M-val;
        if(tempval>=0){
            if(minval== -1 || minval>tempval) minval=tempval;
        }else{  if(minval>=MAX) minval=-1;  }
        return;
    }
    for(int i=id;i<v.size();i++){
        swap(v,i,id);
        int thisval=ropeusedforthisval(v,id);
        val+=thisval;
        permute(v,minval,val,id+1,M);
        val-=thisval;
        swap(v,i,id);
    }
}


void permuteandget(int N,int M,int& minlen){
    vector<int> v;
    for(int i=0;i<N;i++){v.push_back(i+1); }
    int tempval=0;
    permute(v,minlen,tempval,0,M);
}


int main() {
    int T;
    cin>>T;
    for(int t=0;t<T;t++){
        int N,M;
        cin>>N>>M;
        int minlen=MAX;
        permuteandget(N,M,minlen);
        cout<<minlen<<endl;
    }
    return 0;
}
