#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
class Dequeue{
    public:
        int size;
        int front;
        int rear;
        int *arr;

    //create
    //push
        //fromFront
        //fromRear
    //pop
        //fromFront
        //fromRear
    //getFront
    //getRear
    //getSize
    //isEmpty

    Dequeue(int size){
        this -> size = size;
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
        if(rear == size -1 ){
            cout<<"Overflow !!"<<endl;
        }
        else if(rear == -1 && front == -1){
            rear++;
            front++;
            arr[rear] = val;
        }
        else{
            rear++;
            arr[rear]=val;
        }
    }

    void pushFront(int val){
        if(front == 0){
            cout<<"OverFlow !!"<<endl;
        }
        else if(front == -1 && rear == -1){
            front++;
            rear++;
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
    Dequeue q(5);
    q.pushFront(10);
    q.pushBack(20);
    q.print();
    q.pushBack(30);
    q.pushBack(40);
    q.pushBack(50);
    q.popFront();
    q.popBack();
    q.print();
    q.pushFront(10);
    q.pushBack(50);
    q.print();
return 0;
}