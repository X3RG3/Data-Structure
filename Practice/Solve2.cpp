#include <iostream>
using namespace std;
int main(){
    int x1,x2,x3,x4;
    cin>>x1>>x2>>x3>>x4;

    int abc[3];

    abc[0] = x4-x3;
    abc[1] =x4 - x2;
    abc[2] = x4 - x1;

    for(int i=0;i<3;i++){
        cout<<abc[i];
        if(i<2){
            cout<<" ";
        }
    }
}