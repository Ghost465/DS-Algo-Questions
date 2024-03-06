/*
Leetcode : https://leetcode.com/problems/3sum/description/?envType=featured-list&envId=top-google-questions?envType=featured-list&envId=top-google-questions

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int N=nums.size();
        vector<vector<int>> RES;
        sort(nums.begin(), nums.end());
        for(int i=0 ; i<N-2 ; i++){
            // if current i and last entry i (RES[last_entry_idx][0]) have same value, then there's a chance duplicate is also stored
            // ex. -1 -1 0 1 2  => could return duplicate of same set of triplets (-1, 0, 1)
            // ex. -1 -1 -1 0 2 => could return duplicate of same set of triplets (-1, -1, 2)
            // ex. 0 0 0 0      => could return duplicate of same set of triplets (0, 0, 0)
            while (i<N-2 && RES.size()>0 && RES[RES.size()-1][0]==nums[i]) {
                i++;
            }
            if (i==N-2) {
                return RES;
            }
            int left=i+1;
            int right=N-1;
            while(left<right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum<0) {
                    left++;
                } else if (sum>0) {
                    right--;
                } else {
                    RES.push_back({nums[i], nums[left], nums[right]});
                    // to avoid duplicate entries here too
                    while(left<right && nums[left]==nums[left+1]) {
                        left++;
                    }
                    left++;
                    // to avoid duplicate entries here too
                    while(left<right && nums[right]==nums[right-1]) {
                        right--;
                    }
                    right--;
                }
            }
        }
        return RES;
    }
};
