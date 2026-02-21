#include <iostream>
using namespace std;
struct student{
    string name;
    int id;
    float cgpa;
};
int main(){
    student s[5];

    for(int i=0;i<5;i++){
        cout<<"Name : ";
        cin>>s[i].name;
        cout<<"ID : ";
        cin>>s[i].id;
        cout<<"CGPA : ";
        cin>>s[i].cgpa;
    }

    int scolCount =0;
    cout<<endl;
    cout<<"Students getting scholarship : "<<endl;
    cout<<endl;
    for(int i=0;i<5;i++){
        if(s[i].cgpa >=3.5){
            scolCount++;
            cout<<"Name : "<<s[i].name<<endl;
            cout<<"ID : "<<s[i].id<<endl;
            cout<<"CGPA : "<<s[i].cgpa<<endl;
        }
    }
    cout<<"Total Student Getting Scholarship : "<<scolCount<<endl;

}