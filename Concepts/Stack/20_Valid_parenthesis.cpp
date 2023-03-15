#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> stack;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                stack.push(s[i]);
            }
            else  
            /* 
            there may be some closing brackets
            also checks if stack is empty because of no opening brackets
            */
            {
                if (!stack.empty())
                {
                    char close = s[i];
                    char top = stack.top();
                    if ((top == '(' && close == ')') ||
                        (top == '[' && close == ']') ||
                        (top == '{' && close == '}'))
                    {
                        stack.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
        }
        /*
        At this point if there is any opening bracket left then return false
        */
        if (!stack.empty())
        {
            return false;
        }
        return true;
    }
};

int main()
{

    Solution s;
    cout << s.isValid("{}{");

    return 0;
}