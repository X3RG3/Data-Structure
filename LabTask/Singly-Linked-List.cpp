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

void insertBeforeValue(Node* &head,int value,Node* newNode){
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
    if(prev == NULL){ 
        newNode->next = head;
        head = newNode;
    }
    else{ 
        newNode->next = temp;
        prev->next = newNode;
    }

}

void Delete(Node* &head, int value){
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

void update(Node* head, int oldVal, int newVal){
    Node* temp = head;

    while(temp != NULL && temp->data != oldVal){
        temp = temp->next;
    }

    if(temp == NULL){
        cout<<"NOT FOUND...!!"<<endl;
        return;
    }

    temp->data = newVal;
}

int main(){
    
}