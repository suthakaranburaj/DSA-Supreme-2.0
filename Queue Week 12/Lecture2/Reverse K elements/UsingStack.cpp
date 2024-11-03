#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#include <stack>

using namespace std;

void reverseKElement(queue<int> &q,int k){

    if(k==0 || q.empty()){
        return;
    }
    stack<int>s;
    int n = q.size();
    for(int j=0;j<k;j++){
        int frontElementOfQueue = q.front();
        q.pop();
        s.push(frontElementOfQueue);
    }

    while(!s.empty()){
        int frontElementOfStack = s.top();
        s.pop();

        q.push(frontElementOfStack);
    }
    for(int i = 0;i<(n-k); i++){
        int temp = q.front();
        q.pop();
        q.push(temp);
    }

}
int main(){
    queue<int>q;
    int k=2;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    reverseKElement(q,k);
    cout<<"Printing queue : "<<endl;
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
return 0;
}