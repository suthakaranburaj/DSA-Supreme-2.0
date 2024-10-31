#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Queue{

    public:
        int size;
        int *arr;
        int front;
        int rear;

    Queue(int size){
        arr = new int[size];
        this->size = size;
        front = -1;
        rear = -1;
    }

    void push(int val){
        if(rear == size-1){
            cout<<"Queue is Overflow!"<<endl;
            return;
        }
        else if(front ==-1 && rear ==-1){
            front++;
            rear++;
            arr[rear]=val;
        }
        else{
            rear++;
            arr[rear]=val;
        }
    }

    void pop(){
        if(front == -1 && rear == -1){
            cout<<"Queue is Underflow !"<<endl;
            return;
        }
        else if(front == rear){
            arr[rear]=-1;
            front = -1;
            rear = -1;
        }
        else{
            arr[front]=-1;
            front++;
        }
    }

    bool isEmpty(){
        if(front == -1 && rear ==-1){
            return true;
        }
        else{
            return false;
        }
    }

    int getFront(){
        if(front == -1){
            cout<<"No element in queue"<<endl;
            return -1;
        }
        else{
            return arr[front];
        }
    }

    int getSize(){
        return rear-front+1;
    }

    void print(){

        cout<<"Printing Queue:"<<endl;
        for(int i=0;i<size;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    int getRear(){
        if(rear == -1){
            cout<<"No element in queue !!"<<endl;
        }
        else{
            return arr[rear];
        }
    }

};



int main(){
    Queue q(4);
    q.push(10);
    // q.print();
    // q.print();
    q.push(20);
    q.push(30);
    q.push(30);
    q.push(30);
    q.push(30);
    // q.print();
    q.pop();
    q.pop();
    q.print();
    int ans=q.getRear();
    cout<<ans;

    return 0;
}