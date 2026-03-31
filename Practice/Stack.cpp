#include <iostream>
#include <string>
using namespace std;

#define MAX 5

// Person structure
struct Person {
    string name;
    int age;
};

// Stack structure
struct Stack {
    Person arr[MAX];
    int top;
};

// Initialize
Stack init(Stack s) {
    s.top = -1;
    return s;
}

// Push
Stack push(Stack s, string name, int age) {
    if (s.top == MAX - 1) {
        cout << "Stack Overflow\n";
        return s;
    }

    s.top++;
    s.arr[s.top].name = name;
    s.arr[s.top].age = age;

    cout << "Pushed: " << name << " (" << age << ")\n";
    return s;
}

// Pop
Stack pop(Stack s) {
    if (s.top == -1) {
        cout << "Stack Underflow\n";
        return s;
    }

    cout << "Popped: "
         << s.arr[s.top].name << " ("
         << s.arr[s.top].age << ")\n";

    s.top--;
    return s;
}

// Display
void display(Stack s) {
    if (s.top == -1) {
        cout << "Stack is empty\n";
        return;
    }

    cout << "Stack elements:\n";
    for (int i = s.top; i >= 0; i--) {
        cout << s.arr[i].name << " (" << s.arr[i].age << ")\n";
    }
}

int main() {
    Stack s;
    s = init(s);

    s = push(s, "Irfan", 21);
    s = push(s, "Rahim", 25);
    s = push(s, "Karim", 19);

    display(s);

    s = pop(s);

    display(s);

    return 0;
}