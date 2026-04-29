#include <iostream>
using namespace std;

#define max 7

int Stack[max] ;
int top = 0;
bool isEmpty(){
    return(top==0);
}

bool isFull(){
    return (top==max);
}
void push(int val){
    if(isFull()){
        cout<<"Stack Is Full " <<endl;
        return;
    }
    Stack[top++]=val;
}

void pop(){
    if(isEmpty()){
        cout<<"Stack is Empty"<<endl;
        return;
    }
    top--;
}

void show(){
    if(isEmpty()){
        cout<<"Stack is Empty" <<endl;
        return;
    }
    for(int i=top-1;i>=0;i--){
        cout<<Stack[i]<<endl;
    }
}
int main(){
    push(2);
    push(5);
    push(6);
    push(2);
    push(2);
    push(7);
    push(4);
    push(2);

    pop();
    pop();

    show();
}