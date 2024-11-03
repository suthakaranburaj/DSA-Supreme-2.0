#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#include <stack>

using namespace std;

void FirstNegativeInteger(int *q,int k, int n){

    queue<int>ans;
    for(int i=0 ; i<=n-k; i++){
        for(int j=i; j<n; j++){
            if(q[j]<0){
                ans.push(j);
                cout<<q[j]<<endl;
                break;
            }
        }
    }
}
int main(){
    int k=3;
    int q[7]={2, -5, 4, -1, -2, 0, 5};
    int n=7;

    FirstNegativeInteger(q,k,n);
return 0;
}