#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int largestRectangleArea(vector<int>& heights) {
    stack<int> st;
    int maxArea = 0;
    int n = heights.size();
    
    for (int i = 0; i <= n; i++) {
        while (!st.empty() && (i == n || heights[i] < heights[st.top()])) {
            int height = heights[st.top()];
            st.pop();
            int width = st.empty() ? i : (i - st.top() - 1);
            maxArea = max(maxArea, height * width);
        }
        st.push(i);
    }
    
    return maxArea;
}

int main() {
    vector<int> arr1 = {60, 20, 50, 40, 10, 50, 60};
    vector<int> arr2 = {3, 5, 1, 7, 5, 9};
    vector<int> arr3 = {3};

    cout << "Largest Rectangular Area: " << largestRectangleArea(arr1) << endl;
    cout << "Largest Rectangular Area: " << largestRectangleArea(arr2) << endl;
    cout << "Largest Rectangular Area: " << largestRectangleArea(arr3) << endl;

    return 0;
}
