#include<iostream>
#include<stack>
using namespace std;
class Solution
{
public:
    bool isBalanced(string &str)
    {
        // code here
        stack<char> s;
        for (char ch : str)
        {
            if (ch == '(' || ch == '{' || ch == '[')
            {
                s.push(ch);
            }
            else
            {
                if (s.empty())
                    return false;

                char top = s.top();
                s.pop();

                if ((ch == ')' && top != '(') ||
                    (ch == '}' && top != '{') ||
                    (ch == ']' && top != '['))
                {
                    return false;
                }
            }
        }
        return s.empty();
    }
};