#Q1 3443. Maximum Manhattan Distance After K Changes
class Solution {
public:
    int maxDistance(string s, int k) {
        unordered_map<char,int> mp;
        int n=s.length();
        int maxMd=0;
        
        int east=0;
        int west=0;
        int north=0;
        int south=0;
        for(int i=0; i<n; i++){
            if(s[i]=='E') east++;
            if(s[i]=='W') west++;
            if(s[i]=='N') north++;
            if(s[i]=='S') south++;

            int currMd=abs(north-south)+abs(east-west);
        

            int steps=i+1;
            int wasted=steps-currMd;
            int extra=0;
            if(wasted!=0){
                extra=min(2*k,wasted);
            }

            int finalMd=currMd+extra;
            maxMd=max(maxMd,finalMd);

        }
            return maxMd;
    }
};

#Q2 find town judge
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        vector<int> v(n+1, 0);
        vector<int> a(n+1, 0);
        
        
        for(auto &it: trust){
            v[it[0]]++;
            a[it[1]]++;
        }
        for(int i=1; i<=n; i++){
            if(v[i]==0 && a[i]==n-1){
                return i;
            }
        }
        return -1;

    }
};

#Q3 PLUS ONE
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        for (int i = n - 1; i >= 0; --i) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }

        // If all digits are 9, then we need an extra digit at the beginning
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
#Q4 Maximum SubarraySum
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int sum=INT_MIN;
        int data=0;
        for(int i=0; i<n; i++){
            data+=nums[i];
            data=max(nums[i], data);
            sum=max(data,sum);
        }
        return sum;
    }
};

#Q4 Assign Cookies
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int sizeS=s.size();
        int sizeG=g.size();
        int count=0;

        
        int poss=0;
        int posg=0;
        while(poss<sizeS && posg<sizeG){
            if(s[poss]>=g[posg]){
                count++;
                poss++;
                posg++;
            }
            else{
            poss++;
            }
        }
            
        return count;
    }
};
