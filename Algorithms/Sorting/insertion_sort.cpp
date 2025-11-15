#include<iostream>
using namespace std;

void insertionSort(int arr[],int n){
    for(int i = 1;i<n;i++){
        int temp = arr[i];
        int j = i-1;

    while( j>=0 && arr[j] > temp){
        arr[j+1] = arr[j];
        j--;
    }
        arr[j+1] = temp;
    }

}

void printArray(int arr[],int n){
    for(int i = 0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = {2,6,3,8,9,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Unsorted Array:" << endl;
    printArray(arr,n);
    insertionSort(arr,n);
    cout << "Sorted Array:" << endl;
    printArray(arr,n);


    return 0;
}
