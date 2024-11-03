#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#include <stack>

using namespace std;

void FirstNegativeInteger(int *q,int k, int n){

    queue<int>ans;
    for(int i=0; i<k; i++ ){
        int ele = q[i];
        if(ele < 0){
            ans.push(i);
        }
    }

    for(int i = k; i<n; i++){
        if(ans.empty()){
            cout<<"0"<<endl;
        }
        else{
            cout<<q[ans.front()]<<" ";
        }

        if(i - ans.front() >= k){
            ans.pop();
        }

        if(q[i]<0){
            ans.push(i);
        }
    }

    if(!ans.empty()){
        cout<<q[ans.front()]<<" ";
        ans.pop();
    }
    else{
        cout<<"0"<<" ";
    }
}
int main(){
    int k=3;
    int q[7]={2, -5, 4, -1, 2, 0, 5};
    int n=7;

    FirstNegativeInteger(q,k,n);
return 0;
}