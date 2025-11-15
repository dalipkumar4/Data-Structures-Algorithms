#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &arr,int start,int mid,int end){
    vector <int> temp;
    int i,j;
    i = start;
    j = mid+1;
    
    while(i<= mid && j<= end){
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
        }
    }


    while(i <= mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j <= end){
        temp.push_back(arr[j]);
        j++;
    }

    for(int k = 0; k < temp.size();k++){

        arr[start+k] = temp[k]; 
    }
}

void mergeSort(vector<int> &arr,int start,int end){
    if(start < end){
        int mid = start+(end-start)/2;
        //Left half
        mergeSort(arr,start,mid);
        //Right half
        mergeSort(arr,mid+1,end);

        merge(arr,start,mid,end);
    }
}


void printArray(const vector<int> &arr){
    for(int val: arr){
        cout << val << " ";
    }
    cout << endl;
}

int main(){
    vector<int> arr ={3,5,1,2,9,8};
    int n = arr.size();
    vector<int>temp;

    cout << "Before Sorting: " ;
    printArray(arr);
    mergeSort(arr,0,n-1);
    cout << "After Sorting: " ;
    printArray(arr);

    return 0;
}
