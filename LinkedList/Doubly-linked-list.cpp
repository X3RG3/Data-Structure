#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node *prev;   // 🔥 new
};

void showElements(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

void insertAtLast(Node* head, Node* newNode){
    Node* temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;   // 🔥 new
    newNode->next = NULL;
}

void insertAfterValue(Node* head, int value, Node* newNode){
    Node* temp = head;

    while(temp != NULL && temp->data != value){
        temp = temp->next;
    }

    if(temp == NULL){
        cout<<"NOT FOUND...!!"<<endl;
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;   // 🔥 new

    if(temp->next != NULL){
        temp->next->prev = newNode;   // 🔥 fix backward link
    }

    temp->next = newNode;
}

void insertBeforeValue(Node* &head, int value, Node* newNode){
    Node* temp = head;
    Node* prev = NULL;

    while(temp != NULL && temp->data != value){
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL){
        cout<<"NOT FOUND...!!"<<endl;
        return;
    }

    if(prev == NULL){ // insert before head
        newNode->next = head;
        newNode->prev = NULL;   // 🔥 new
        head->prev = newNode;   // 🔥 new
        head = newNode;
    }
    else{
        newNode->next = temp;
        newNode->prev = prev;   // 🔥 new

        prev->next = newNode;
        temp->prev = newNode;   // 🔥 new
    }
}

void Delete(Node* &head, int value){
    Node* temp = head;
    Node* prev = NULL;

    while(temp != NULL && temp->data != value){
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL){
        cout<<"NOT FOUND...!"<<endl;
        return;
    }

    if(prev == NULL){ // delete head
        head = temp->next;
        if(head != NULL){
            head->prev = NULL;   // 🔥 new
        }
        delete temp;
    }
    else{
        prev->next = temp->next;

        if(temp->next != NULL){
            temp->next->prev = prev;   // 🔥 new
        }

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

    n1->data = 10;
    n2->data = 20;

    n1->next = n2;
    n1->prev = NULL;

    n2->next = NULL;
    n2->prev = n1;

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