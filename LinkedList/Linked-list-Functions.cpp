#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

void showElements(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }

}

void insertAtLast(Node* head,Node* newNode){
    Node* temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = NULL;
}

void insertAfterValue(Node* head,int value,Node* newNode){
    Node* temp = head;
    while(temp != NULL && temp->data != value){
        temp = temp->next;
    }
    if(temp == NULL){
        cout<<"NOT FOUND...!!"<<endl;
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void insertBeforeValue(Node* head,int value,Node* newNode){
    Node* temp = head;
    Node* prev = NULL;
    while(temp!= NULL && temp->data != value){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        cout<<"NOT FOUND...!!"<<endl;
        return;
    }
    if(prev == NULL){ //insert before head
        newNode->next = head;
        head = newNode;
    }
    else{ //insert before others
        newNode->next = temp;
        prev->next = newNode;
    }

}

void Delete(Node* head, int value){
    Node* temp = head;
    Node* prev = NULL;
    while(temp!= NULL && temp->data != value){
        prev = temp;
        temp = temp->next;
    }
    if(temp== NULL){
        cout<<"NOT FOUND...!"<<endl;
        return;
    }
    if(prev == NULL){
        head = temp->next;
        delete temp;
    }
    else{
        prev->next = temp->next;
        delete temp;
    }
}


int main(){
    Node* n1 = new Node();
    Node* n2 = new Node();
    
    n1->data = 10;
    n2->data = 20;

    n1->next = n2;
    n2->next = NULL;

    Node* head = n1;

    showElements(head);

    cout<<endl;

    Node* n3 = new Node();
    n3->data = 30;


    insertAtLast(head,n3);

    showElements(head);

    cout<<endl;

    Node* n4 = new Node();
    n4->data = 40;

    insertAtLast(head,n4);

    showElements(head);
    cout<<endl;

    Node* n5 = new Node();
    n5->data = 50;

    insertAfterValue(head,n3->data,n5);

    showElements(head);

    cout<<endl;
    Node* n6 = new Node();
    n6->data = 60;
    insertBeforeValue(head,n4->data,n6);

    showElements(head);

    cout<<endl;

    Delete(head,n6->data);

    showElements(head);


}