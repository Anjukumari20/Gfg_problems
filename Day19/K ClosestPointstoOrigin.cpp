#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    // Lambda function to calculate squared distance
    auto dist = [](const vector<int>& point) {
        return point[0] * point[0] + point[1] * point[1];
    };
    
    // Sort points based on the squared distance
    sort(points.begin(), points.end(), [&dist](const vector<int>& a, const vector<int>& b) {
        return dist(a) < dist(b);
    });
    
    // Return the first k points
    return vector<vector<int>>(points.begin(), points.begin() + k);
}

int main() {
    int k = 2;
    vector<vector<int>> points = {{1, 3}, {-2, 2}, {5, 8}, {0, 1}};
    
    vector<vector<int>> result = kClosest(points, k);
    
    for (const auto& point : result) {
        cout << "[" << point[0] << ", " << point[1] << "] ";
    }
    cout << endl;
    
    return 0;
}
