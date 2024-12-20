#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
class CircularDequeue{
    public:
        int size;
        int *arr;
        int front;
        int rear;
    
    CircularDequeue(int size){
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    
    int getFront(){
        if(front == -1){
            cout<<"No Element in the queue !!"<<endl;
        }
        else{
            return arr[front];
        }
    }

    int getRear(){
        if(rear == -1){
            cout<<"No Element in the queue !!"<<endl;
        }
        else{
            return arr[rear];
        }
    }

    // int getSize(){

    // }

    bool isEmpty(){
        if(front == -1 && rear == -1){
            return true;
        }
        else{
            return false;
        }
    }

    void pushBack(int val){
        if(front == 0 && rear == size-1 || rear == front - 1){
            cout<<"Overflow !!"<<endl;
        }
        else if(rear == -1 && front == -1){
            rear++;
            front++;
            arr[rear] = val;
        }
        else if(rear == size-1){
            rear = 0;
            arr[rear] = val;
        }
        else{
            rear++;
            arr[rear]=val;
        }
    }

    void pushFront(int val){
        if(front == 0 && rear == size-1 || rear == front -1){
            cout<<"OverFlow !!"<<endl;
        }
        else if(front == -1 && rear == -1){
            front++;
            rear++;
            arr[front]=val;
        }
        else if(front == 0 && rear !=size-1){
            front =size-1;
            arr[front]=val;
        }
        else{
            front--;
            arr[front]=val;
        }
    }

    void popBack(){
        if(rear == -1 && front == -1){
            cout<<"UnderFlow !!"<<endl;
        }
        else if(front == rear){
            arr[rear] = -1;
            rear = -1;
            front = -1;
        }
        else if(rear == size-1 && front !=0 ){
            arr[rear]=-1;
            rear = size-1;
        }
        else{
            arr[rear]=-1;
            rear--;
        }
    }

    void popFront(){
        if(rear == -1 && front == -1){
            cout<<"UnderFlow !!"<<endl;
        }
        else if(front == rear){
            arr[rear] = -1;
            rear = -1;
            front = -1;
        }
        else if(front == size-1){
            arr[front] = -1;
            front = 0;
        }
        else{
            arr[front]=-1;
            front++;
        }
    }

    void print(){
        cout<<"Printing Dequeue:"<<endl;
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    CircularDequeue q(5);
    q.pushFront(10);
    q.pushFront(20);
    q.pushFront(30);
    q.pushFront(40);
    q.pushFront(50);
    q.print();
    q.popFront();
    q.print();
    q.pushFront(110);
    q.print();
    

return 0;
}