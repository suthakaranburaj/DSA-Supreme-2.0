#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Cqueue{
    public:
        int size;
        int *arr;
        int front;
        int rear;

    //create 
    //push
    //pop
    //getFront
    //getRear
    //isEmpty
    //print
    Cqueue(int size){
        this->size = size;
        front = -1;
        rear = -1;
        arr = new int[size];
    }

    void push(int val){
        if(front == 0 && rear == size-1 || rear == front-1){
            cout<<"Overflow !!";
        }
        else if(front == -1 && rear == -1){
            rear++;
            front++;
            arr[rear]=val;
        }
        else if(rear == size-1 && front !=0 ){
            rear = 0;
            arr[rear] = val;
        }
        else{
            rear++;
            arr[rear]=val;
        }
    }

    void pop(){
        if(front == -1 && rear == -1){
            cout<<"Underflow !!"<<endl;
        }
        else if(front == rear){
            arr[front]= -1;
            front = -1;
            rear = -1;
        }
        else if(front == size-1){
            arr[front] = -1;
            front =0;

        }
        else{
            arr[front] = -1;
            front++;
        }
    }

    void print(){
        cout<<"Printing Cqueue !!"<<endl;
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
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
        if(front ==-1){
            cout<<"No elements in the Queue !"<<endl;
        }
        return arr[front];
    }

    int getRear(){
        if(rear ==-1){
            cout<<"No elements in the Queue !"<<endl;
        }
        return arr[rear];
    }

};

int main(){
    Cqueue q(5);
    q.push(10);
    q.push(20);
    // q.print();


    q.push(30);
    q.push(40);
    // q.print();
    q.getFront();

    q.push(50);
    // q.print();
    q.getFront();

    q.print();
    q.pop();
    q.pop();
    q.print();
    q.push(110);
    q.print();
    q.push(120);
    q.print();
    q.push(130);
    q.print();
return 0;
}