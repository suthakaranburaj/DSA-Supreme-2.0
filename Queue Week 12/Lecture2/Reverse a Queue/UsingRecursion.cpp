#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#include <stack>

using namespace std;

void reverseQueue(queue<int> &q){
    if(q.empty()){
        return;
    }

    int temp = q.front();
    q.pop();
    reverseQueue(q);
    q.push(temp);
    // q.pop();

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