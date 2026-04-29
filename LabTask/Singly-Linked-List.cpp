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
    Node* n1 = new Node();
    Node* n2 = new Node();
    Node* n3 = new Node();
    Node* n4 = new Node();
    Node* n5 = new Node();
    Node* n6 = new Node();
    Node* n7 = new Node();

    Node* head = n1;

    n1->data = 25;
    n2->data = 6;
    n3->data = 2;
    n4->data = 2;
    n5->data = 7;
    n6->data = 4;
    n7->data = 2;

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;
    n7->next = NULL;

    showElements(head);
    Delete(head,n6->data);
    cout<<endl;
    showElements(head);
}