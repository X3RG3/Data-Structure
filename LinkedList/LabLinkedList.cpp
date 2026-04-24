#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// 1. INSERTION
void insert(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// 2. DELETION
void remove(Node*& head, int key) {
    if (head == nullptr) return;

    // If head holds the key
    if (head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != key) {
        temp = temp->next;
    }

    if (temp->next != nullptr) {
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }
}

// 3. UPGRADATION (Update)
void update(Node* head, int oldVal, int newVal) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == oldVal) {
            temp->data = newVal;
            return;
        }
        temp = temp->next;
    }
    cout << "Value " << oldVal << " not found." << endl;
}

// Display the list
void display(Node* head) {
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = nullptr;

    // Insertion
    insert(head, 10);
    insert(head, 20);
    insert(head, 30);
    cout << "Initial List: ";
    display(head);

    // Upgradation (Update 20 to 25)
    update(head, 20, 25);
    cout << "After Update (20 -> 25): ";
    display(head);

    // Deletion
    remove(head, 10);
    cout << "After Deleting 10: ";
    display(head);

    return 0;
}