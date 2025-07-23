#Q1. Binary Search
--iterative
// Online C++ compiler to run C++ program online
#include<bits/stdc++.h>
using namespace std;
#include <iostream>
bool binary(vector<int>& v,int target){
    int start=0;
    int end=v.size()-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(v[mid]==target) return true;
        else if(v[mid]<target) start=mid+1;
        else end=mid-1;
    }
    return false;
}

int main() {
    vector<int> v={1,2,5,7,8,12,17,19,25,46};
   int target=12;
   int other=8;
    bool ans=binary(v,target);
    (ans) ? cout<<"yes"<<endl : cout<<"NO"<<endl;
    bool ans1=binary(v,other);
    (ans1) ? cout<<"yes"<<endl : cout<<"NO"<<endl;
    
    
    return 0;
}
--recursive
#include <bits/stdc++.h>
using namespace std;

bool binary(int target, int start, int end, vector<int> &v) {
    if (start > end) return false;  

    int mid = start + (end - start) / 2;

    if (v[mid] == target) return true;

    if (v[mid] < target)
        return binary(target, mid + 1, end, v);
    else
        return binary(target, start, mid - 1, v);
}

int main() {
    vector<int> v = {1, 2, 5, 7, 8, 12, 17, 19, 25, 46};
    int target = 12;
    bool ans = binary(target, 0, v.size() - 1, v);

    cout << (ans ? "Found" : "Not Found") << endl;

    return 0;
}
