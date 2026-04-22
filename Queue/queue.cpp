#include <iostream>
using namespace std;

#define maxSize 4

int queueArr[maxSize];
int front = -1;
int rear = -1;

// Check if empty
bool isEmpty() {
    return (front == -1 && rear == -1);
}

// Check if full
bool isFull() {
    return (rear == maxSize - 1);
}

// Enqueue
void enqueue(int x) {
    if (isFull()) {
        cout << "Queue is full!" << endl;
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear++;
    }

    queueArr[rear] = x;
}

// Dequeue
void dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return;
    }

    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
}

// Front element
int frontElement() {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return -1;
    }
    return queueArr[front];
}

// Show queue
void showQueue() {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return;
    }

    for (int i = front; i <= rear; i++) {
        cout << queueArr[i] << " ";
    }
    cout << endl;
}

int main() {
    enqueue(3);
    enqueue(6);
    enqueue(2);
    enqueue(5);

    cout << "Queue: ";
    showQueue();

    dequeue();

    cout << "After dequeue: ";
    showQueue();

    cout << "Front element: " << frontElement() << endl;

    return 0;
}