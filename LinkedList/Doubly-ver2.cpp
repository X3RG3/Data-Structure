#include <iostream>
using namespace std;

struct Node{
    int data;

    Node *prev;   // <<< NEW ADDED

    Node *next;
};

void showElements(Node* head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void insertAtLast(Node* head, Node* newNode){
    Node* temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newNode;

    newNode->prev = temp;   // <<< NEW ADDED

    newNode->next = NULL;
}

void insertAfterValue(Node* head, int value, Node* newNode){
    Node* temp = head;

    while(temp != NULL && temp->data != value){
        temp = temp->next;
    }

    if(temp == NULL){
        cout << "NOT FOUND...!!" << endl;
        return;
    }

    newNode->next = temp->next;

    newNode->prev = temp;   // <<< NEW ADDED

    if(temp->next != NULL){   // <<< NEW BLOCK ADDED
        temp->next->prev = newNode;
    }

    temp->next = newNode;
}

void insertBeforeValue(Node* &head, int value, Node* newNode){
    Node* temp = head;

    // <<< REMOVED:
    // Node* prev = NULL;

    while(temp != NULL && temp->data != value){
        temp = temp->next;
    }

    if(temp == NULL){
        cout << "NOT FOUND...!!" << endl;
        return;
    }

    newNode->next = temp;

    newNode->prev = temp->prev;   // <<< NEW ADDED

    if(temp->prev != NULL){   // <<< CHANGED
        temp->prev->next = newNode;
    }
    else{
        head = newNode;
    }

    temp->prev = newNode;   // <<< NEW ADDED
}

void Delete(Node* &head, int value){
    Node* temp = head;

    // <<< REMOVED:
    // Node* prev = NULL;

    while(temp != NULL && temp->data != value){
        temp = temp->next;
    }

    if(temp == NULL){
        cout << "NOT FOUND...!!" << endl;
        return;
    }

    if(temp->prev != NULL){   // <<< CHANGED
        temp->prev->next = temp->next;
    }
    else{
        head = temp->next;
    }

    if(temp->next != NULL){   // <<< NEW BLOCK ADDED
        temp->next->prev = temp->prev;
    }

    delete temp;
}

void update(Node* head, int oldVal, int newVal){
    Node* temp = head;

    while(temp != NULL && temp->data != oldVal){
        temp = temp->next;
    }

    if(temp == NULL){
        cout << "NOT FOUND...!!" << endl;
        return;
    }

    temp->data = newVal;
}

int main(){

    Node* n1 = new Node();
    Node* n2 = new Node();

    n1->data = 10;
    n2->data = 20;

    n1->prev = NULL;   // <<< NEW ADDED

    n1->next = n2;

    n2->prev = n1;   // <<< NEW ADDED

    n2->next = NULL;

    Node* head = n1;

    showElements(head);
    cout << endl;

    Node* n3 = new Node();
    n3->data = 30;

    insertAtLast(head, n3);

    showElements(head);
    cout << endl;

    Node* n4 = new Node();
    n4->data = 40;

    insertAtLast(head, n4);

    showElements(head);
    cout << endl;

    Node* n5 = new Node();
    n5->data = 50;

    insertAfterValue(head, 30, n5);

    showElements(head);
    cout << endl;

    Node* n6 = new Node();
    n6->data = 60;

    insertBeforeValue(head, 40, n6);

    showElements(head);
    cout << endl;

    Delete(head, 60);

    showElements(head);
    cout << endl;

    update(head, 50, 100);

    showElements(head);

    return 0;
}