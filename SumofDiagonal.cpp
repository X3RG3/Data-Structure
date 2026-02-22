#include <iostream>
using namespace std;
int main(){
    int a[2][2];
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            cin>>a[i][j];
        }
    }
    int sum = 0;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            if(i==j || (i+j)==(2-1)){
                sum+=a[i][j];
            }
        }
       
    }

    cout<<sum<<endl;
}