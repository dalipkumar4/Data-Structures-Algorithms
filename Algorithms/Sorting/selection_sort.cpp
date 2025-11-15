#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void selectionSort(vector<int> &arr){
    for(int i = 0;i<arr.size();i++){
        int smallIdx = i;
        for(int j = i+1;j<arr.size();j++){
            if(arr[j] < arr[smallIdx])
                swap(arr[j],arr[smallIdx]);
        }
    }
}

void printArray(const vector<int> &arr){
    for(int val: arr){
        cout << val << " ";
    }
    cout << endl;
}


int main(){
    vector<int> arr = {4,1,5,2,3};
    int n = arr.size();

    cout << "Unsorted Array: ";
    printArray(arr);
    selectionSort(arr);
    cout << "Sorted Array: ";
    printArray(arr);

    return 0;
}
