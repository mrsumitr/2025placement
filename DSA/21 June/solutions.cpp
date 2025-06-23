1. Minimize Size Subarray Sum
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int minLength = INT_MAX;
        int left = 0;
        int sum = 0;

        for (int right = 0; right < n; ++right) {
            sum += nums[right];

            while (sum >= target) {
                minLength = min(minLength, right - left + 1);
                sum-=nums[left];
                left++;
            }
        }

        if(minLength==INT_MAX){
            return 0;
        }
        else{
            return minLength;
        }
    }
};
2. Majority Elements II
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        vector <int> ans;
        int req=nums.size()/3+1;
        int n=nums.size();
        if(n==1){
            return {nums[0]};
        }
        if(n==2){
            if(nums[0]!=nums[1]){
                return {nums[0],nums[1]};
            }
            else{
                return {nums[0]};
            }
            
        }
        sort(nums.begin(), nums.end());
        int firstele=nums[0];
        int count=1;
        for(int i=1; i<n; i++){
            if(nums[i]==firstele){
                count++;
                
            }
            else{
                if(count>=req){
                    ans.push_back(firstele);
                }
                firstele=nums[i];
                count=1;
            }
            
            
        
                
            
        }
        if(count>=req){
                    ans.push_back(firstele);
                }
       
        return ans;
    }
};
3. Next Permutation
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index=-1;
        int n=nums.size();
        for(int i=n-2; i>=0; i--){
            if(nums[i]<nums[i+1]){
                index=i;
                break;
            }
        }
        if(index==-1){
            reverse(nums.begin(), nums.end());
            return;
        }
        for(int i=n-1; i>index; i--){
            if(nums[i]>nums[index]){
                swap(nums[i],nums[index]);
                break;
            }
        }
        reverse(nums.begin()+index+1,nums.end());
    
    }
};
4. 
