#Q1 reverse intergers
class Solution {
  public:
    int reverseDigits(int n) {
        string s=to_string(n);
        reverse(s.begin(),s.end());
        n=stoi(s);
        return n;
        
    }
};

#Q2 insert position
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int size=nums.size();
        int end=size-1;
        int start=0;
        int mid = start + (end - start) / 2;
        while(start<=end){
           int mid = start + (end - start) / 2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<target){
                start=mid+1;
            }
            else{
                end=mid-1;
            }



        }
        return start;

    }
};

#Q3 Single Number

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=nums[0];
        for(int i=1; i<nums.size(); i++){
            ans=ans^nums[i];
        }
        
        return ans;
    }  
};

#Q4 Missing Number

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
    long long rSum=n*(n+1)/2;
    long long numsSum=0;
    for(int i=0; i<nums.size(); i++){
        numsSum+=nums[i];
    }  
    return rSum-numsSum;
    }
    
};


