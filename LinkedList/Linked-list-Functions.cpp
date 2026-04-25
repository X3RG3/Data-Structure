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

void insertAtLast(Node* head,Node* addedNode){
    Node* temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = addedNode;
    addedNode->next = NULL;
}

int main(){

    Node n1,n2;
    n1.data = 10;
    n2.data = 20;

    n1.next = &n2;
    n2.next = NULL;

    Node* head = &n1;

    showElements(head);

    cout<<endl;

    Node n3;
    n3.data = 30;


    insertAtLast(head,&n3);

    showElements(head);

    cout<<endl;

    Node n4;
    n4.data = 40;

    insertAtLast(head,&n4);

    showElements(head);


}