#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

void insertList(Node* &head, int value) {
    Node* newNode = new Node{value, nullptr, nullptr};
    if (!head) {
        head = newNode;
        return;
    }
    else {
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void insertBeginning(Node* &head, int value) {
    Node* newNode = new Node{value, nullptr, head};
    if (head) {
        head->prev = newNode;
    }
    head = newNode;
}

void insertMiddle(Node* &head, int value, int position) {
    Node* newNode = new Node{value, nullptr, nullptr};

    if (!head) {
        head = newNode;
        return;
    }

    Node* temp = head;
    int index = 1;

    while (temp->next && index < position) {
        temp = temp->next;
        index++;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

void display(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " > ";
        temp = temp->next;
    }
    cout <<endl;
}

int main() {
    Node* head = nullptr;

    insertList(head, 6);
    insertList(head, 2);
    insertList(head, 7);
    insertList(head, 4);
    insertList(head, 2);

    display(head);

    insertBeginning(head, 25);
    display(head);

    insertMiddle(head, 2, 3);
    display(head);

    return 0;
}