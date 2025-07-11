#Q1 733. Flood Fill
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor = image[sr][sc];
        if (originalColor == color) return image;

        int m = image.size();
        int n = image[0].size();

        vector<pair<int, int>> stack;
        stack.push_back({sr, sc});

        while (!stack.empty()) {
            auto [r, c] = stack.back();
            stack.pop_back();

            // Color the current pixel
            image[r][c] = color;

            // Check 4 directions
            if (r > 0 && image[r - 1][c] == originalColor)
                stack.push_back({r - 1, c});
            if (r < m - 1 && image[r + 1][c] == originalColor)
                stack.push_back({r + 1, c});
            if (c > 0 && image[r][c - 1] == originalColor)
                stack.push_back({r, c - 1});
            if (c < n - 1 && image[r][c + 1] == originalColor)
                stack.push_back({r, c + 1});
        }

        return image;
    }
};
#Q2 47. Permutations II
class Solution {

private:
    void recursion(vector<vector<int>> &ans,vector<int> ds,int freq[], vector<int> nums){
        if(nums.size()==ds.size()){
            ans.push_back(ds);
            return;
        }
        set<int> s;
        for(int i=0; i<nums.size(); i++){
            if(!freq[i] && s.find(nums[i])==s.end()){
                
                s.insert(nums[i]);
                freq[i]=1;
                ds.push_back(nums[i]);
                recursion(ans,ds,freq,nums);
                ds.pop_back();
                freq[i]=0;

            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
       int freq[nums.size()];
        for(int i=0; i<nums.size(); i++) {
            freq[i]=0;
        }
        recursion(ans,ds,freq,nums);
        return ans;
    }
};
#Q3 1922. Count Good Numbers
class Solution {
private:
    const int MOD = 1e9 + 7;

    long long power(long long base, long long exp) {
        long long result = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % MOD;
            }
            base = (base * base) % MOD;
            exp /= 2;
        }
        return result;
    }

public:
    int countGoodNumbers(long long n) {
        long long even_positions = (n + 1) / 2; 
        long long odd_positions = n / 2;        

        long long res_even = power(5, even_positions);
        long long res_odd = power(4, odd_positions);

        return (res_even * res_odd) % MOD;
    }
};


#Q4 781. Rabbits in Forest
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int countZero=0;
        vector<int> v;
        for(int i=0; i<answers.size(); i++){
            if(answers[i]==0){
                countZero++;
            }
            else{
                v.push_back(answers[i]);
            }



        }
        unordered_map<int,int> mp;
        for(auto i: v){
            mp[i]++;
        }
        int ans=0;
        for(auto data: mp){
            if(data.second<(data.first+1)){
                ans=ans+data.first+1;
            }
            else if(data.second%(data.first+1)==0){
                ans=ans+data.second;
            }
            else{
                ans=ans+data.second-(data.second)%(data.first+1)+data.first+1;
            }
            
        }
        return ans+countZero;
    }
};
