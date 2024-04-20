class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        heights.push_back(0);
        stack<int> heightsIndex;
        for (int i = 0; i < heights.size(); i++) {
            while (!heightsIndex.empty() &&
                   heights[heightsIndex.top()] >= heights[i]) {
                int lastHeight = heights[heightsIndex.top()];
                heightsIndex.pop();

                int lastIndex = heightsIndex.empty()>0?-1:heightsIndex.top();
                int currArea = lastHeight * (i - lastIndex - 1);
                maxArea = max(maxArea, currArea);
            }
            heightsIndex.push(i);
        }
        return maxArea;
    }
};