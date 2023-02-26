/*
https://leetcode.com/problems/house-robber-iv/submissions/904081965/

There are several consecutive houses along a street, each of which has some money inside. There is also a robber, who wants to steal money from the homes, but he refuses to steal from adjacent homes.
The capability of the robber is the maximum amount of money he steals from one house of all the houses he robbed.
You are given an integer array nums representing how much money is stashed in each house. More formally, the ith house from the left has nums[i] dollars.
You are also given an integer k, representing the minimum number of houses the robber will steal from. It is always possible to steal at least k houses.
Return the minimum capability of the robber out of all the possible ways to steal at least k houses.

Solved by: Erki Laanemae
*/
class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        // If not possible to rob k non-adjacent homes.
        if (nums.size() < k*2-1) {
            cout << "Faulty input";
            return 0;
        }
        // Declare the smallest and largest possible values for binary search.
        int smallest = 1,
            highest = 1e9,
            middle,
            count;
        while (smallest < highest) {
            // Find average value.
            middle = (smallest + highest) / 2;
            count = 0;
            // Loop through given array and count possibilities.
            for (int i=0; i<nums.size(); i++) {
                if (nums[i] <= middle) {
                    count++;
                    // No neghbors allowed.
                    i++;
                }
            }
            // If more possibilities are found than k, search left side.
            if (count >= k) {
                highest = middle;
            // Else search right side.
            } else {
                smallest = middle + 1;
            }
        }
        // Return the minimum capability.
        return smallest;
    }
};