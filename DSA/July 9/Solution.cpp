#Q1 70. Climbing Stairs
class Solution {
public:
    int climbStairs(int n) {
        if(n==0 || n==1){
            return 1;
        }
        if(n<4){
            return n;
        }
        int sum=0;
        int data=3;
        int ot=2;
        
        for(int i=3; i<n; i++){
            
            int copy=data;
            data=ot+data;
            ot=copy;

        }
        return data;
    }
    
};
#Q2 78. Subsets
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        int total=(1<<n);
        for(int i=0; i<total; i++){
            vector<int> subset;
            for(int j=0; j<n; j++){
                if(i&(1<<j)){ //check if ith bit is set or not
                    subset.push_back(nums[j]);
                }
            }
            ans.push_back(subset);

        }
        return ans;
    }
};
#Q3 198. House Robber
#Q4 199. House Robber II
