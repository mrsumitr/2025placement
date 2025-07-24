#Q1 Merge sort
#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &v, int low, int mid, int high) {
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high) {
        if (v[left] <= v[right]) {
            temp.push_back(v[left]);
            left++;
        } else {
            temp.push_back(v[right]);
            right++;
        }
    }

    while (left <= mid) {
        temp.push_back(v[left]);
        left++;
    }

    while (right <= high) {
        temp.push_back(v[right]);
        right++;
    }

    for (int i = low; i <= high; i++) {
        v[i] = temp[i - low];  // correct indexing
    }
}

void mergeSort(int low, int high, vector<int> &v) {
    if (low >= high) return;
    int mid = low + (high - low) / 2;
    mergeSort(low, mid, v);
    mergeSort(mid + 1, high, v);
    merge(v, low, mid, high);
}

int main() {
    vector<int> v = {2, 5, 1, 6, 4, 9, 0, 4};
    int n = v.size();
    mergeSort(0, n - 1, v);

    // Output the sorted vector
    for (int i : v) {
        cout << i << " ";
    }

    return 0;
}

#Q2 Quick Sort
#include <bits/stdc++.h>
using namespace std;
int partition(vector<int> &v,int low, int high){
    int pivot=v[low];
    int i=low;
    int j=high;
    while(i<j){
        while(v[i]<=pivot && i<high){
            i++;
        }
        while(v[j]>pivot && j>=low+1){
            j--;
        }
        if(i<j) swap(v[i],v[j]);
        
    }
    swap(v[low],v[j]);
    return j;
}
void quickSort(vector<int> &v, int low, int high){
    if(low<high){
        int pIndex=partition(v,low,high);
        quickSort(v,low,pIndex-1);
        quickSort(v,pIndex+1,high);
        
        
    }
}


int main() {
    vector<int> v = {2, 5, 1, 6, 4, 9, 0, 4};
    int n = v.size();
    quickSort(v,0,n-1);

   
    for (int i : v) {
        cout << i << " ";
    }

    return 0;
}
#Q3 
