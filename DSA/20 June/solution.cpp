#Q 1 Rotate Image
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
    int rows=matrix.size();
    int cols=matrix[0].size();
    for(int i=0; i<rows; i++){
        for(int j=i; j<cols; j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    for(int i=0; i<rows; i++){
        reverse(matrix[i].begin(),matrix[i].end());
    }
    }
};

#Q2 3SUM
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());  // Step 1: Sort the array

        for (int i = 0; i < n - 2; i++) {
            // Skip duplicate values for the first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    ans.push_back({nums[i], nums[left], nums[right]});

                    // Skip duplicates for left and right
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;

                    left++;
                    right--;
                }
                else if (sum < 0) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }
        return ans;
    }
};
#Q3 485. Max Consecutive Ones
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0; 
        int ans=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==1){
                ans++;
                
            }
            else{
                
                count=max(count,ans);
                ans=0;
            }
        }
        count=max(count,ans);
        return count;
    }
};

#Q4 
