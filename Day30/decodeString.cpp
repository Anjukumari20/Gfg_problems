//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    string decodedString(string &s) {
    stack<string> strStack; 
        stack<int> numStack;
        string currStr = "";
        int num = 0;

        for (char ch : s) {
            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');  // Forming the complete number
            } else if (ch == '[') {
                numStack.push(num);   // Store number for repetition
                strStack.push(currStr); // Store current string
                num = 0;
                currStr = "";          // Reset for new scope
            } else if (ch == ']') {
                int repeatCount = numStack.top();
                numStack.pop();

                string temp = strStack.top();
                strStack.pop();

                while (repeatCount--) {
                    temp += currStr;
                }

                currStr = temp;
            } else {
                currStr += ch; // Append character
            }
        }
        return currStr;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.decodedString(s) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends