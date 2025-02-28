class Solution {
    public:
      int evaluate(vector<string>& arr) {
          stack<int> st;
  
          for (string& s : arr) {
              if (s == "+" || s == "-" || s == "*" || s == "/") {
                  // Pop two elements
                  int b = st.top(); st.pop();
                  int a = st.top(); st.pop();
  
                  // Perform operation
                  if (s == "+") st.push(a + b);
                  else if (s == "-") st.push(a - b);
                  else if (s == "*") st.push(a * b);
                  else if (s == "/") st.push(a / b);  // Integer division, rounding toward zero
  
              } else {
                  // Convert string to integer and push to stack
                  st.push(stoi(s));
              }
          }
  
          return st.top();
      }
  };