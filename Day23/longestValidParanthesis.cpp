class Solution {
    public:
      int maxLength(string& s) {
          stack<int> st;
          st.push(-1); // Initialize with -1 to handle base cases
          int max_len = 0;
          
          for (int i = 0; i < s.size(); i++) {
              if (s[i] == '(') {
                  st.push(i); // Store the index of '('
              } else {
                  st.pop(); // Pop matching '(' or base index
                  if (!st.empty()) {
                      max_len = max(max_len, i - st.top());
                  } else {
                      st.push(i); // Push current ')' index as base
                  }
              }
          }
          return max_len;
      }
  };
  