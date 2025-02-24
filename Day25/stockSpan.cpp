#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> calculateSpan(vector<int> &arr) {
    int n = arr.size();
    vector<int> span(n);
    stack<int> st; // Stores indices

    for (int i = 0; i < n; i++) {
        // Pop elements from stack while stack is not empty 
        // and top element is smaller than or equal to arr[i]
        while (!st.empty() && arr[st.top()] <= arr[i]) {
            st.pop();
        }

        // If stack is empty, means no greater element to the left
        if (st.empty()) {
            span[i] = i + 1;
        } else {
            span[i] = i - st.top();
        }

        // Push current index onto stack
        st.push(i);
    }
    return span;
}

int main() {
    vector<int> arr = {100, 80, 60, 70, 60, 75, 85};
    vector<int> result = calculateSpan(arr);

    cout << "Stock Span: ";
    for (int x : result) {
        cout << x << " ";
    }
    return 0;
}
