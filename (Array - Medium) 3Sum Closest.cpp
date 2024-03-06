/*
Leetcode : https://leetcode.com/problems/3sum-closest/description/?envType=featured-list&envId=top-google-questions?envType=featured-list&envId=top-google-questions

Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.
Return the sum of the three integers.
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // O(n^3)
        // int N=nums.size();
        // long valueNearestToTarget=INT_MAX;
        // for(int i=0 ; i<N-2 ; i++) {
        //     for(int j=i+1 ; j<N-1 ; j++) {
        //         for(int k=j+1 ; k<N ; k++) {
        //             if (abs((long)nums[i]+(long)nums[j]+(long)nums[k]-(long)target)<abs(valueNearestToTarget-(long)target)){
        //                 valueNearestToTarget = (long)nums[i]+(long)nums[j]+(long)nums[k];
        //             }
        //         }
        //     }
        // }
        // return valueNearestToTarget;

        // O(n^2)
        int N=nums.size();
        sort(nums.begin(), nums.end()); // O(n.logn)
        long valueNearestToTarget=nums[0]+nums[1]+nums[2];
        for(int i=0 ; i<N-2 ; i++) { // O(n)
            int left = i+1;
            int right = N-1;
            while(right-left>=1) { // O(n)
                int curr3Sum = nums[i] + nums[left] + nums[right];
                if (abs(curr3Sum-target)<abs(valueNearestToTarget-target)){
                    valueNearestToTarget = curr3Sum;
                }
                if (curr3Sum > target) {
                    right--;
                } else if (curr3Sum < target) {
                    left++;
                } else {
                    return target;
                }
            }
        }
        return valueNearestToTarget;
    }

};
