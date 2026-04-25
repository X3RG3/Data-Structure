#include <iostream>
using namespace std;
struct Node{
    int data;
    Node *next;
};
int main(){
    Node n1,n2,n3,n4,n5;
    n1.data = 10;
    n2.data = 20;
    n3.data = 30;
    

    n1.next = &n2;
    n2.next = NULL;
    n3.next = NULL;
    
    // 10 20
    // Insert Value at last.....

    Node* head = &n1;
    Node* temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = &n3;

    // 10 20 30

    // Insert 50 after value 20....
    n4.data = 50;
    n4.next = NULL;

    temp = head;
    int value = 20;
    while(temp != NULL && temp->data != value){
        temp = temp->next;
    }
    if(temp == NULL){
        cout<<"NOT FOUND..!!"<<endl;
    }
    else{
        n4.next = temp->next;
        temp->next = &n4;
    }

    // 10 20 50 30

    // Insert Value before 20....
    Node* prev = NULL;
    temp = head;

    value = 20;
    n5.data = 15;
    n5.next = NULL;

    while(temp != NULL && temp->data != value ){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        cout<<"Not Found..!!"<<endl;
    }
    else if(prev == NULL){
    // inserting before head
    n5.next = head;
    head = &n5;
    }
    else{
        n5.next = temp;
        prev->next = &n5;
    }

    // 10 15 20 50 30 

    // Printing all Linked list Values....

    temp = head;

    while (temp != NULL) {
    cout<<temp->data<<" ";
    temp = temp->next;
    }
}