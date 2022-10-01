
// https://leetcode.com/problems/longest-increasing-subsequence/submissions/

// Simple recursive approach

class Solution {
public:
    
    int solve(vector<int>& nums,int ind,int last){
        // base case
        if(ind==nums.size()){
            return 0;
        }
        
        int incl = 0;
        if(last == -1 || nums[ind]>last){
            incl = 1 + solve(nums,ind+1,nums[ind]);
        }
        
        int excl = solve(nums,ind+1,last);
        
        int ans = max(incl,excl);
        return ans;
    
}
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        return solve(nums,0,-1);
    }
};

// Top down : recursive + memoization
// time :  O(N2)
// space :  O(N2)


class Solution {
public:
    
    int solve(int n,vector<int>& nums,int ind,int last, vector<vector<int> > &dp){
        // base case
        if(ind==n){
            return 0;
        }
        
        if(dp[ind][last+1] != -1){
            return dp[ind][last+1];
        }
        
        int incl = 0;
        if(last == -1 || nums[ind]>nums[last]){
            incl = 1 + solve(n,nums,ind+1,ind,dp);
        }
        
        int excl = solve(n,nums,ind+1,last,dp);
        
        return dp[ind][last+1] = max(incl,excl);
        
}
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        vector<vector<int> > dp(n+1,vector<int> (n+1,-1));
        
        return solve(n,nums,0,-1,dp);
    }
};

// Bottom up : Tabulation
// time :  O(N2)
// space :  O(N2)

class Solution {
public:
    
    int solve(vector<int>& nums){
        int n = nums.size();
        
        vector<vector<int> > dp(n+1,vector<int> (n+1,0));
        
        for(int i = n-1;i>=0;i--){
            for(int j=i-1;j>=-1;j--){
                int incl = 0;
                if(j == -1 || nums[i]>nums[j]){
                    incl = 1 + dp[i+1][i+1];
                }

                int excl = dp[i+1][j+1];

                dp[i][j+1] = max(incl,excl);
            }
        }
        
        return dp[0][0];
    }
    
    int lengthOfLIS(vector<int>& nums) {
        
        return solve(nums);
    }
};

// space optimization
// time :  O(N2)
// space :  O(N2)
