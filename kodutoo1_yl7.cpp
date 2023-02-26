/*
https://leetcode.com/problems/container-with-most-water/description/

You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the container contains the most water.

Solved by: Erki Laanemae
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        // Declare all needed attributes.
        int side, dist, vol, answer = 0;
        // Loop through the heights twice and compare heights.
        for (int i=0; i<height.size(); i++) {
            for (int j=0; j<height.size(); j++) {
                // Can't make a container from the same vertical line.
                if (i != j) {
                    // Find lower vertical line to prevent overfilling.
                    side = min(height[i], height[j]);
                    // Find length of container bottom.
                    dist = j-i;
                    // Find volume on container.
                    vol = side*dist;
                    // If volume is bigger than last, save it as answer.
                    if (answer < vol) {
                        answer = vol;
                    }
                }
            }
        }
        // Return largest volume.
        return answer;
    }
};