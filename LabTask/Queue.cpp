#include <iostream>
using namespace std;

#define max 7

int Queue[max];
int front=-1,rear=-1;

bool isEmpty(){
    return(front ==-1&& rear==-1);
}

bool isFull(){
    return(rear==max-1);
}

void enqueue(int x){
    if(isFull()){
        cout<<"Queue Full"<<endl;
        return;
    }
    if(isEmpty()){
        front = rear=0;
    }
    else{
        rear++;
    }
    Queue[rear]=x;
}

void dequeue(){
    if(isEmpty()){
        cout<<"Queue Empty"<<endl;
        return;
    }
    if(front == rear){
        front = rear = -1;
    }
    else{
        front++;
    }
}

void show(){
    if(isEmpty()){
        cout<<"Queue empty"<<endl;
        return;
    }
    for(int i=front;i<=rear;i++){
        cout<<Queue[i]<<endl;
    }
}

int main(){
    enqueue(2);
    enqueue(5);
    enqueue(6);
    enqueue(2);
    enqueue(2);
    enqueue(7);
    enqueue(4);
    enqueue(2);


    dequeue();
    dequeue();

    show();



}