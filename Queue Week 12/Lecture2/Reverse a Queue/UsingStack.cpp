#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#include <stack>

using namespace std;

void reverseQueue(queue<int> &q){
    stack<int>s;
    while(!q.empty()){
        int frontElementOfQueue = q.front();
        q.pop();
        s.push(frontElementOfQueue);
    }

    while(!s.empty()){
        int frontElementOfStack = s.top();
        s.pop();

        q.push(frontElementOfStack);
    }

}
int main(){
    queue<int>q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    reverseQueue(q);
    cout<<"Printing queue : "<<endl;
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
return 0;
}