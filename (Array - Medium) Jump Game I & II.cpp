/*
LeetCode
Jump Game I : https://leetcode.com/problems/jump-game/?envType=featured-list&envId=top-google-questions?envType=featured-list&envId=top-google-questions
Jump Game II : https://leetcode.com/problems/jump-game-ii/description/?envType=featured-list&envId=top-google-questions?envType=featured-list&envId=top-google-questions
*/

/*
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length from that position.
Return true if you can reach the last index, or false otherwise.
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int N = nums.size();
        int maxIndexReachable=0;
        for(int i=0 ; i<=maxIndexReachable ; i++) {
            maxIndexReachable = max(maxIndexReachable, i + nums[i]);
            if (maxIndexReachable>=N-1) {
                return true;
            }
        }
        return false;
    }
};

/*
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length from that position.
Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].
*/

class Solution {
public:
    int jump(vector<int>& nums) {
        int N = nums.size();
        int startIdx=0;
        int endIdx=0;
        int stepNum=0;
        while(endIdx<N-1) {
            int nextEndIdx = endIdx;
            while(startIdx<=endIdx){
                nextEndIdx = max(nextEndIdx, startIdx + nums[startIdx]);
                startIdx++;
            }
            endIdx = nextEndIdx;
            stepNum++;
        }
        return stepNum;
    }
};
