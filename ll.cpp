#include<iostream>
using namespace std;
int main(){
    int n;
    int f;
    cin>>n;
    cin>>f;
    int arr[n];
    int w=n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]> f){
            w++;
        }
    }
    cout<<w;
    return 0;
}