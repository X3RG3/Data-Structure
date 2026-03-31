#include <iostream>
using namespace std;
int main(){

    int A[5] = {1,2,3};//
    A[0]= 10;
    A[10] = 123;
    cout<<sizeof(A)<<endl;
    cout<<sizeof(A[0])<<endl;
    cout<<&A[0]<<endl;
    cout<<A[4]<<endl;
    cout<<A[9]<<endl;
    cout<<A[10] <<endl;
    cout<<A<<endl;
}
#include <iostream>
using namespace std;

// Nested structure for Date
struct Date {
    int day;
    int month;
    int year;
};

// Main structure
struct Person {
    string name;
    int age;
    string address;
    Date dob; // nested structure (Date inside Person)
};

int main() {
    Person p;

    // Input
    cout << "Enter name: ";
    cin >> ws;
    getline(cin, p.name);

    cout << "Enter age: ";
    cin >> p.age;

    cout << "Enter address: ";
    cin >> ws;
    getline(cin, p.address);

    cout << "Enter Date of Birth (day month year): ";
    cin >> p.dob.day >> p.dob.month >> p.dob.year;

    // Output
    cout << "\n--- Person Details ---\n";
    cout << "Name: " << p.name << endl;
    cout << "Age: " << p.age << endl;
    cout << "Address: " << p.address << endl;
    cout << "Date of Birth: " 
         << p.dob.day << "/" 
         << p.dob.month << "/" 
         << p.dob.year << endl;

    return 0;
}