/*
Leetcode : https://leetcode.com/problems/max-consecutive-ones-iii/description/?envType=study-plan-v2&envId=leetcode-75

Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

Example 1:

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
*/

class Solution {
public:
    int longestOnes(vector<int> &nums, int k) {
        int N = nums.size();
        int left=0;
        int right=0;
        int zeroesCounted=0;
        int maxLength=0;
        while(right<N) {
            if (nums[right]==0) {
                zeroesCounted++;
                if (zeroesCounted>k) {
                    while(nums[left]!=0) {
                        left++;
                    }
                    left++;
                }
            }
            maxLength = max(maxLength, right-left+1);
            right++;
        }
        return maxLength;
    }
};
