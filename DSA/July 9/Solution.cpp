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
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
        }

        return dp[n - 1];
    }
};



#Q4 199. House Robber II
class Solution {
public:
    int robRange(vector<int>& nums, int start, int end) {
        int n = end - start + 1;
        if (n == 1) return nums[start];
        
        vector<int> dp(n);
        dp[0] = nums[start];
        dp[1] = max(nums[start], nums[start + 1]);

        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 1], nums[start + i] + dp[i - 2]);
        }

        return dp[n - 1];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        // Case 1: Rob from 0 to n-2
        int case1 = robRange(nums, 0, n - 2);

        // Case 2: Rob from 1 to n-1
        int case2 = robRange(nums, 1, n - 1);

        return max(case1, case2);
    }
};
