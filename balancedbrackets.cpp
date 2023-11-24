#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <vector>
bool isBalanced(std::string str) 
{
    std::stack<char> s;
    for(char c : str) 
    {
        switch(c) 
        {
            case '(':
            case '{':
            case '[':
                s.push(c);
                break;
            case ')':
                if(s.empty() || s.top() != '(') return false;
                s.pop();
                break;
            case '}':
                if(s.empty() || s.top() != '{') return false;
                s.pop();
                break;
            case ']':
                if(s.empty() || s.top() != '[') return false;
                s.pop();
                break;
            default:
                break;
        }
    }
    return s.empty();
}
int main() 
{
    std::string line;
    std::getline(std::cin, line);
    std::stringstream ss(line);
    std::string str;
    while(std::getline(ss, str, ',')) 
    {
        if(isBalanced(str)) 
        {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}