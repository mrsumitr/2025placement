#Q1 LC 17. Letter Combinations of a Phone Number
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.empty()) return ans;

        vector<string> numbers = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        int n = digits.length();

        if (n == 1) {
            string data = numbers[digits[0] - '0'];
            for (char c : data) {
                ans.push_back(string(1, c));
            }
            return ans;
        } 
        else if (n == 2) {
            string data1 = numbers[digits[0] - '0'];
            string data2 = numbers[digits[1] - '0'];
            for (char c1 : data1) {
                for (char c2 : data2) {
                    ans.push_back(string() + c1 + c2);
                }
            }
            return ans;
        } 
        else if (n == 3) {
            string data1 = numbers[digits[0] - '0'];
            string data2 = numbers[digits[1] - '0'];
            string data3 = numbers[digits[2] - '0'];
            for (char c1 : data1) {
                for (char c2 : data2) {
                    for (char c3 : data3) {
                        ans.push_back(string() + c1 + c2 + c3);
                    }
                }
            }
            return ans;
        } 
        else {
            string data1 = numbers[digits[0] - '0'];
            string data2 = numbers[digits[1] - '0'];
            string data3 = numbers[digits[2] - '0'];
            string data4 = numbers[digits[3] - '0'];
            for (char c1 : data1) {
                for (char c2 : data2) {
                    for (char c3 : data3) {
                        for (char c4 : data4) {
                            ans.push_back(string() + c1 + c2 + c3 + c4);
                        }
                    }
                }
            }
            return ans;
        }
    }
};
#Q2 LC 39. Combination Sum

#Q3 46. Permutations
class Solution {

private:
    void recursion( vector<vector<int>> &ans, vector<int> &ds, int freq[], vector<int> &nums){

        if(ds.size()==nums.size()){
            ans.push_back(ds);
            return;
        }
        for(int i=0; i<nums.size(); i++){
            if(!freq[i]){
            ds.push_back(nums[i]);
            freq[i]=1;
            
            recursion(ans,ds,freq,nums);
            ds.pop_back();
            freq[i]=0;
            }
        }

    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        int freq[nums.size()];
        for(int i=0; i<nums.size(); i++) freq[i]=0;
        recursion(ans,ds,freq,nums);
        return ans;

    }
};

