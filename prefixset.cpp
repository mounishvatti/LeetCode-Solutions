#include <iostream>
#include <vector>
#include <algorithm>
bool isPrefix(std::string str1, std::string str2) 
{
    if(str1.size() > str2.size()) return false;
    return str2.substr(0, str1.size()) == str1;
}
std::string checkPasswords(std::vector<std::string> passwords) 
{
    std::sort(passwords.begin(), passwords.end());
    for(int i = 0; i < passwords.size() - 1; i++) 
    {
        if(isPrefix(passwords[i], passwords[i+1])) 
        {
            return "BAD PASSWORD";
        }
    }
    return "GOOD PASSWORD";
}
int main() 
{
    int n=3;
    std::vector<std::string> passwords(n);
    for(int i = 0; i < n; i++) 
    {
        std::cin >> passwords[i];
    }
    std::cout << checkPasswords(passwords) << std::endl;
    return 0;
}