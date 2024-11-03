#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#include <stack>

using namespace std;

void InterLeave(queue<int> &q){
    queue<int>second;
    queue<int>first;
    int n=q.size();
    int half;
    if(n%2==0){
        half = n/2;
    }
    else{
        half = (n/2)+1;
    }

    for(int i = 0 ; i<half ; i++){
        int frontElementOfFirstQueue = q.front();
        q.pop();
        second.push(frontElementOfFirstQueue);
        // cout<<frontElementOfFirstQueue<<endl;
    }
    
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        first.push(temp);
    }


    while(!second.empty()){
        int frontOfSecondQueue = second.front();
        cout<<frontOfSecondQueue<<endl;
        second.pop();
        q.push(frontOfSecondQueue);

        if(!first.empty()){
            int remainginFirstQueue = first.front();
            q.push(remainginFirstQueue);
            // cout<<remainginFirstQueue<<endl;
            first.pop();
        }
    }
}
int main(){
    queue<int>q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    // q.push(60);

    InterLeave(q);
    cout<<"Printing queue : "<<endl;
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
return 0;
}