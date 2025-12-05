#include<iostream>
using namespace std;

void bubbleSort(int arr[],int n){
    int temp;
    for(int i = 0;i<n-1;i++){
        for(int j = 0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1]; 
                arr[j+1] = temp;
            }
        }
    }
}


int main(){
    int arr[] = {1,4,2,5,3};
    int n = sizeof(arr)/sizeof(arr[0]);


    cout << "Unsorted:" << endl;
    for(int i = 0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    
    bubbleSort(arr,n);
    
    cout << "Sorted:" << endl;
    for(int i = 0;i<n;i++){
        cout << arr[i] << " ";
    }
    return 0;
}
